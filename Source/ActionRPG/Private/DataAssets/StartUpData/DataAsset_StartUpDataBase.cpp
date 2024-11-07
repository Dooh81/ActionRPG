// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "AbilitySystem/ActionRpgAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/HeroGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UActionRpgAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
    check(InASCToGive);

    GrantAbilities(ActivateOnGivenAbilities, InASCToGive, ApplyLevel);
    GrantAbilities(ReActiveAbilities, InASCToGive, ApplyLevel);
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UActionRpgGameplayAbility>>& InAbilitiesToGive, UActionRpgAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
    if (InAbilitiesToGive.IsEmpty())
    {
        return;
    }

    UE_LOG(LogTemp, Warning, TEXT("InAbilitiesToGive Count: %d"), InAbilitiesToGive.Num());

    for (const TSubclassOf<UActionRpgGameplayAbility>& Ability : InAbilitiesToGive)
    {
        if (!Ability) continue;

        FGameplayAbilitySpec AbiltitySpec(Ability);
        AbiltitySpec.SourceObject = InASCToGive->GetAvatarActor();
        AbiltitySpec.Level = ApplyLevel;

        InASCToGive->GiveAbility(AbiltitySpec);
    }
}
