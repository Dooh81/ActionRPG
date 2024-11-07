// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class UActionRpgAbilitySystemComponent;
class UHeroGameplayAbility;
class UActionRpgGameplayAbility;
/**
 * 
 */
UCLASS()
class ACTIONRPG_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
    virtual void GiveToAbilitySystemComponent(UActionRpgAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
	
protected:
    UPROPERTY(EditDefaultsOnly, Category="StartUpData")
    TArray<TSubclassOf< UActionRpgGameplayAbility>> ActivateOnGivenAbilities;

    UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
    TArray<TSubclassOf< UActionRpgGameplayAbility>> ReActiveAbilities;

    void GrantAbilities(const TArray<TSubclassOf< UActionRpgGameplayAbility>>& InAbilitiesToGive, UActionRpgAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
};
