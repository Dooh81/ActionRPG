// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "ActionRpgAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONRPG_API UActionRpgAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
    void OnAbilityInputPressed(const FGameplayTag& InInputTag);
    void OnAbilityInputReleased(const FGameplayTag& InInputTag);
	
};
