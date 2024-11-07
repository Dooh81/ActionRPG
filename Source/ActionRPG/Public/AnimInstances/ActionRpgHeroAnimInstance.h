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

    //5초후 idle 상태로 진입 릴렉스상태도달점 진입
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AnimData|LocomotionData")
    float EnterRelaxStateThreshold = 5.0f;

    //아이들 경과시간
    float IdleElpasedTime;
};
