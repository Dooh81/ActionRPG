// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/ActionRpgCharcterAnimInstance.h"
#include "ActionRpgHeroAnimInstance.generated.h"

/**
 * 
 */
class AActionRPGHeroCharacter;
UCLASS()
class ACTIONRPG_API UActionRpgHeroAnimInstance : public UActionRpgCharcterAnimInstance
{
	GENERATED_BODY()
	
public:
    virtual void NativeInitializeAnimation() override;
    virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Refereneces")
    AActionRPGHeroCharacter* OwningHeroCharacter;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
    bool bShouldEnterRelaxState;

    //5���� idle ���·� ���� ���������µ����� ����
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AnimData|LocomotionData")
    float EnterRelaxStateThreshold = 5.0f;

    //���̵� ����ð�
    float IdleElpasedTime;
};
