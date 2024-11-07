// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "GameplayTagContainer.h"
#include "DataAsset_HeroStartUpData.generated.h"

USTRUCT(BlueprintType)
struct FHeroAbilitySet
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Catagories = "InputTag"))
    FGameplayTag InputTag;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TSubclassOf<UActionRpgGameplayAbility> AbilityToGrant;

    bool IsValid() const; 
};
/**
 * 
 */
UCLASS()
class ACTIONRPG_API UDataAsset_HeroStartUpData : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()
	
public:
    virtual void GiveToAbilitySystemComponent(UActionRpgAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1) override;

private:
    UPROPERTY(EditDefaultsOnly, Category = "StartUpData", meta = (TitleProperty = "InputTag"))
    TArray<FHeroAbilitySet> HeroStartupDataSets;
};
