// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/HeroGameplayAbility.h"
#include "Characters/ActionRPGHeroCharacter.h"
#include "Controllers/ActionRPGHeroController.h"

AActionRPGHeroCharacter* UHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
    if (!CachedActionRpgHeroCharacter.IsValid())
    {
        CachedActionRpgHeroCharacter = Cast<AActionRPGHeroCharacter>(CurrentActorInfo->AvatarActor);
    }

    return CachedActionRpgHeroCharacter.IsValid() ? CachedActionRpgHeroCharacter.Get() : nullptr;
}

AActionRPGHeroController* UHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
    if (!CachedActionRpgHeroController.IsValid())
    {
        CachedActionRpgHeroController = Cast<AActionRPGHeroController>(CurrentActorInfo->PlayerController);
    }
    return CachedActionRpgHeroController.IsValid() ? CachedActionRpgHeroController.Get() : nullptr;
}

UHeroCombatComponent* UHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
    return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}
