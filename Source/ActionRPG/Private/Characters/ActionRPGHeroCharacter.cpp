// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/ActionRPGHeroCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputSubsystems.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "Components/Input/ActionRPGInputComponent.h"
#include "ActionRPGGamePlayTags.h"
#include "AbilitySystem/ActionRpgAbilitySystemComponent.h"
#include "AbilitySystem/ActionRpgAttributeSet.h"
#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "Components/Combat/HeroCombatComponent.h"

#include "ActionRPGDebugHelper.h"

void AActionRPGHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
   ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();

   UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

   check(Subsystem);

   Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);
   
   UActionRPGInputComponent* ActionRpgInputComponent = CastChecked<UActionRPGInputComponent>(PlayerInputComponent);
   ActionRpgInputComponent->BindNativeInputAction(InputConfigDataAsset, ActionRPGGamePlayTags::InputTag_Move, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
   ActionRpgInputComponent->BindNativeInputAction(InputConfigDataAsset, ActionRPGGamePlayTags::InputTag_Look, ETriggerEvent::Triggered, this, &ThisClass::Input_Look);
   ActionRpgInputComponent->BindAbilityInputAction(InputConfigDataAsset, this, &ThisClass::Input_AbilityInputPressed, &ThisClass::Input_AbilityInputReleased);

}

void AActionRPGHeroCharacter::BeginPlay()
{
    Super::BeginPlay();
}


void AActionRPGHeroCharacter::Input_Move(const FInputActionValue& InputActionValue)
{
    const FVector2D MovementVector = InputActionValue.Get<FVector2D>();
    const FRotator MovementRotation(0.f, Controller->GetControlRotation().Yaw, 0.0f);

    if (MovementVector.Y != 0.0f)
    {
        const FVector ForwardDirection = MovementRotation.RotateVector(FVector::ForwardVector);

        AddMovementInput(ForwardDirection, MovementVector.Y);
    }

    if (MovementVector.X != 0.0f)
    {
        const FVector RightDirection = MovementRotation.RotateVector(FVector::RightVector);

        AddMovementInput(RightDirection, MovementVector.X);
    }
}

void AActionRPGHeroCharacter::Input_Look(const FInputActionValue& InputActionValue)
{
    const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

    if (LookAxisVector.X != 0.f)
    {
        AddControllerYawInput(LookAxisVector.X);
    }

    if (LookAxisVector.Y != 0.0f)
    {
        AddControllerPitchInput(LookAxisVector.Y);
    }
}

void AActionRPGHeroCharacter::Input_AbilityInputPressed(FGameplayTag InInputTag)
{
    ActionRpgAbilitySystemComponent->OnAbilityInputPressed(InInputTag);
}

void AActionRPGHeroCharacter::Input_AbilityInputReleased(FGameplayTag InInputTag)
{
    ActionRpgAbilitySystemComponent->OnAbilityInputReleased(InInputTag);
}

AActionRPGHeroCharacter::AActionRPGHeroCharacter()
{
    //캡슐사이즈 초기사이즈 세팅
    GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

    //회전 사용 비활성화 
    bUseControllerRotationPitch = false;
    bUseControllerRotationRoll = false;
    bUseControllerRotationYaw = false;

    //스프링암 초기세팅
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(GetRootComponent());
    CameraBoom->TargetArmLength = 200.0f;
    CameraBoom->SocketOffset = FVector(0.f, 55.f, 65.f);
    CameraBoom->bUsePawnControlRotation = true;

    //카메라 초기세팅
    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation = false;

    //케릭터 움직임 초기세팅
    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
    GetCharacterMovement()->MaxWalkSpeed = 400.0f;
    GetCharacterMovement()->BrakingDecelerationWalking = 2000.0f;

    HeroCombatComponent = CreateDefaultSubobject<UHeroCombatComponent>(TEXT("HeroCombatComponent"));
}

void AActionRPGHeroCharacter::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);

   /* if (HeroAbilitySystemComponent && HeroAttributeSet)
    {
        const FString ASCText = FString::Printf(TEXT("Owner Acotr: %s, Avatar Acotr: %s"), *HeroAbilitySystemComponent->GetOwnerActor()->GetActorLabel(), *HeroAbilitySystemComponent->GetAvatarActor()->GetActorLabel());
        Debug::Print(TEXT("AbilitySystemComponent valid.") + ASCText, FColor::Green);
        Debug::Print(TEXT("AttributeSet valid. ") + ASCText, FColor::Cyan);
    }*/

    if (!CharacterStartUpData.IsNull())
    {
        if (UDataAsset_StartUpDataBase* LoadData = CharacterStartUpData.LoadSynchronous())
        {
            LoadData->GiveToAbilitySystemComponent(ActionRpgAbilitySystemComponent);
        }

    }
}
