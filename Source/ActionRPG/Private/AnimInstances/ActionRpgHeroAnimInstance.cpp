// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/ActionRpgHeroAnimInstance.h"
#include "Characters/ActionRPGHeroCharacter.h"

void UActionRpgHeroAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();

    if (OwningCharacter)
    {
        OwningHeroCharacter = Cast<AActionRPGHeroCharacter>(OwningCharacter);
    }
}

void UActionRpgHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

    //속도가 있으면 진입시간 초기화 및 릴렉스 진입상태 비활성화
    if (bHasAcceleration)
    {
        IdleElpasedTime = 0.0f;
        bShouldEnterRelaxState = false;
    }
    else
    {
        //IdleElpasedTime 시간값 더하기, 릴렉스 상태값은 임계값보다 클경우
        IdleElpasedTime += DeltaSeconds;
        bShouldEnterRelaxState = (IdleElpasedTime >= EnterRelaxStateThreshold);
    }

}
