// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "ActionRPGBaseCharacter.generated.h"

class UActionRpgAbilitySystemComponent;
class UActionRpgAttributeSet;
class UDataAsset_StartUpDataBase;
UCLASS()
class ACTIONRPG_API AActionRPGBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
    GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AActionRPGBaseCharacter();

    //~Begin IAbilitySystemInterface Interface.
    virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;
    //~End IAbilitySystemInterface Interface.
protected:
    //~Begin APawn Interface.
    virtual void PossessedBy(AController* NewController) override;
    //~End APawn Interface.

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AbilitySystem")
    UActionRpgAbilitySystemComponent* ActionRpgAbilitySystemComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
    UActionRpgAttributeSet* ActionRpgAttributeSet;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, category = "CharacterData")
    TSoftObjectPtr< UDataAsset_StartUpDataBase> CharacterStartUpData;

public:
    FORCEINLINE UActionRpgAbilitySystemComponent* GetActionRpgAbilitySystemComponent() const { return ActionRpgAbilitySystemComponent; }
    FORCEINLINE UActionRpgAttributeSet* GetActionRpgAttributeSet() const { return ActionRpgAttributeSet; }
};
