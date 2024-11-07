// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/ActionRpgBaseAnimInstance.h"
#include "ActionRpgCharcterAnimInstance.generated.h"

/**
 * 
 */
class AActionRPGBaseCharacter;
class UCharacterMovementComponent;
UCLASS()
class ACTIONRPG_API UActionRpgCharcterAnimInstance : public UActionRpgBaseAnimInstance
{
	GENERATED_BODY()
	
public:
    virtual void NativeInitializeAnimation() override;
    virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;


protected:
    UPROPERTY()
    AActionRPGBaseCharacter* OwningCharacter;

    UPROPERTY()
    UCharacterMovementComponent* OwningMovementComponent;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData|LocomotionData")
    float GroundSpeed;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
    bool bHasAcceleration;
};
