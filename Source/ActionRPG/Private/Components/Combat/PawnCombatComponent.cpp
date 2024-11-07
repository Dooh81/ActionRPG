// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/PawnCombatComponent.h"
#include "Items/HeroWeaponBase.h"
#include "ActionRPGDebugHelper.h"

void UPawnCombatComponent::RegisterSpawnWeapon(FGameplayTag InWeaponTagToRegister, AHeroWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon)
{
    checkf(!CharacterCarriedWeaponMap.Contains(InWeaponTagToRegister),TEXT("A named %s has already been added as carried weapon"), *InWeaponTagToRegister.ToString());
    check(InWeaponToRegister);

    CharacterCarriedWeaponMap.Emplace(InWeaponTagToRegister, InWeaponToRegister);

    if (bRegisterAsEquippedWeapon)
    {
        CurrentEquippedWeaponTag = InWeaponTagToRegister;
    }

    const FString WeaponString = FString::Printf(TEXT("A Weapon named %s has registered using the tag %s"), *InWeaponToRegister->GetName(), *InWeaponTagToRegister.ToString());
    Debug::Print(WeaponString, FColor::Red);
}

AHeroWeaponBase* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{
    if (CharacterCarriedWeaponMap.Contains(InWeaponTagToGet))
    {
        if (AHeroWeaponBase* const* FoundWeapon = CharacterCarriedWeaponMap.Find(InWeaponTagToGet))
        {
            return *FoundWeapon;
        }
    }

    return nullptr;
}

AHeroWeaponBase* UPawnCombatComponent::GetCharacterCurrentEquippedWeapon() const
{
    if (CurrentEquippedWeaponTag.IsValid())
    {
        return nullptr;
    }

    return GetCharacterCarriedWeaponByTag(CurrentEquippedWeaponTag);
}
