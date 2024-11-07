// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "ActionRpgGameplayAbility.generated.h"

UENUM(BlueprintType)
enum class EActionRpgAbilityActivationPolicy : uint8
{
    OnTriggered,
    OnGiven
};

class UPawnCombatComponent;
class UActionRpgAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class ACTIONRPG_API UActionRpgGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
protected:
    //~ Begin UGameplayAbility Interface
    virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
    //~ End UGameplayAbility Interface
    virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

    UPROPERTY(EditDefaultsOnly, Category = "Hero|Ability")
    EActionRpgAbilityActivationPolicy AbilityActivationPolicy = EActionRpgAbilityActivationPolicy::OnTriggered;

    UFUNCTION(BlueprintPure, Category = "Hero|Ability")
    UPawnCombatComponent* GetPawnCombatComponentFromActorInfo() const;

    UFUNCTION(BlueprintPure, Category = "Hero|Ability")
    UActionRpgAbilitySystemComponent* GetActionRpgAbilitySystemComponentFromActorInfo() const;
};
