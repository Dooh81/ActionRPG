// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/ActionRpgGameplayAbility.h"
#include "HeroGameplayAbility.generated.h"

class AActionRPGHeroCharacter;
class AActionRPGHeroController;
class UHeroCombatComponent;
/**
 * 
 */
UCLASS()
class ACTIONRPG_API UHeroGameplayAbility : public UActionRpgGameplayAbility
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, Category = "Hero|Ability")
    AActionRPGHeroCharacter* GetHeroCharacterFromActorInfo();

    UFUNCTION(BlueprintPure, Category = "Hero|Ability")
    AActionRPGHeroController* GetHeroControllerFromActorInfo();

    UFUNCTION(BlueprintPure, Category = "Hero|Ability")
    UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();

private:
    TWeakObjectPtr<AActionRPGHeroCharacter> CachedActionRpgHeroCharacter;
    TWeakObjectPtr<AActionRPGHeroController> CachedActionRpgHeroController;
};
