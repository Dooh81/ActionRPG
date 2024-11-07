// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/ActionRpgGameplayAbility.h"
#include "AbilitySystem/ActionRpgAbilitySystemComponent.h"
#include "Components/Combat/PawnCombatComponent.h"

void UActionRpgGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
    Super::OnGiveAbility(ActorInfo, Spec);

    if (AbilityActivationPolicy == EActionRpgAbilityActivationPolicy::OnGiven)
    {
        if (ActorInfo && !Spec.IsActive())
        {
            ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
        }
    }
}

void UActionRpgGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
    Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

    if (AbilityActivationPolicy == EActionRpgAbilityActivationPolicy::OnGiven)
    {
        if (ActorInfo)
        {
            ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
        }
    }
}

UPawnCombatComponent* UActionRpgGameplayAbility::GetPawnCombatComponentFromActorInfo() const
{
    return GetAvatarActorFromActorInfo()->FindComponentByClass<UPawnCombatComponent>();
}

UActionRpgAbilitySystemComponent* UActionRpgGameplayAbility::GetActionRpgAbilitySystemComponentFromActorInfo() const
{
    return Cast<UActionRpgAbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent);
}
