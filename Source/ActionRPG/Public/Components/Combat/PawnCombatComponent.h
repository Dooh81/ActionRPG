// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnExtentionComponentBase.h"
#include "GameplayTagContainer.h"
#include "PawnCombatComponent.generated.h"

class AHeroWeaponBase;
/**
 * 
 */
UCLASS()
class ACTIONRPG_API UPawnCombatComponent : public UPawnExtentionComponentBase
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Hero|combat")
    void RegisterSpawnWeapon(FGameplayTag InWeaponTagToRegister, AHeroWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon = false);

    UFUNCTION(BlueprintCallable, Category = "Hero|combat")
    AHeroWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;

    UPROPERTY(BlueprintReadWrite, Category = "Hero|combat")
    FGameplayTag CurrentEquippedWeaponTag;

    UFUNCTION(BlueprintCallable, Category = "Hero|combat")
    AHeroWeaponBase* GetCharacterCurrentEquippedWeapon() const;
	
private:
    TMap<FGameplayTag, AHeroWeaponBase*> CharacterCarriedWeaponMap;
};
