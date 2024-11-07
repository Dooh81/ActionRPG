// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/ActionRPGBaseCharacter.h"
#include "GameplayTagContainer.h"
#include "ActionRPGHeroCharacter.generated.h"


//Forward Declaration (전방 선언) #include 된 것이 변경되면 이를 include하는 모든것이 재컴파일 되므로 성능적 저하를 불러올 수 있다. 또한 Header들이 순환이 발생될 수 있기 때문에 cpp에서 헤더를 불러오도록 한다.
class USpringArmComponent;
class UCameraComponent;
class UDataAsset_InputConfig;
struct FInputActionValue;
class UHeroCombatComponent;

/**
 * 
 */
UCLASS()
class ACTIONRPG_API AActionRPGHeroCharacter : public AActionRPGBaseCharacter
{
	GENERATED_BODY()

public:
    AActionRPGHeroCharacter();

    //~Begin APawn Interface.
    virtual void PossessedBy(AController* NewController) override;
    //~End APawn Interface.
	
protected:
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    virtual void BeginPlay() override;

private:
#pragma region Components
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, category="Camera", meta=(AllowPrivateAccess = "true"))
    USpringArmComponent* CameraBoom;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, category = "Camera", meta = (AllowPrivateAccess = "true"))
    UCameraComponent* FollowCamera;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, category = "Combat", meta = (AllowPrivateAccess = "true"))
    UHeroCombatComponent* HeroCombatComponent;
#pragma endregion

   

#pragma region Inputs
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, category = "CharacterData", meta = (AllowPrivateAccess = "true"))
    UDataAsset_InputConfig* InputConfigDataAsset;

    void Input_Move(const FInputActionValue& InputActionValue);
    void Input_Look(const FInputActionValue& InputActionValue);
    void Input_AbilityInputPressed(FGameplayTag InInputTag);
    void Input_AbilityInputReleased(FGameplayTag InInputTag);

#pragma endregion

public:
    FORCEINLINE UHeroCombatComponent* GetHeroCombatComponent() const { return HeroCombatComponent; }
};
