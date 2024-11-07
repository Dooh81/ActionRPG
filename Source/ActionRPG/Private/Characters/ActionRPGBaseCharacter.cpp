// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/ActionRPGBaseCharacter.h"
#include "AbilitySystem/ActionRpgAbilitySystemComponent.h"
#include "AbilitySystem/ActionRpgAttributeSet.h"

// Sets default values
AActionRPGBaseCharacter::AActionRPGBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
    PrimaryActorTick.bStartWithTickEnabled = false;
    GetMesh()->bReceivesDecals = false;

    ActionRpgAbilitySystemComponent = CreateDefaultSubobject<UActionRpgAbilitySystemComponent>(TEXT("ActionRpgAbilitySystemComponent"));
    ActionRpgAttributeSet = CreateDefaultSubobject<UActionRpgAttributeSet>(TEXT("ActionRpgAttributeSet"));

}

UAbilitySystemComponent* AActionRPGBaseCharacter::GetAbilitySystemComponent() const
{
    return ActionRpgAbilitySystemComponent;
}

void AActionRPGBaseCharacter::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);

    if (ActionRpgAbilitySystemComponent)
    {
        ActionRpgAbilitySystemComponent->InitAbilityActorInfo(this, this);

        ensureMsgf(!CharacterStartUpData.IsNull(), TEXT("Forget to assign start up data to %s"), *GetName());
    }
}


