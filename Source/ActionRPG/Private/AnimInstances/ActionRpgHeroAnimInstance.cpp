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

    //�ӵ��� ������ ���Խð� �ʱ�ȭ �� ������ ���Ի��� ��Ȱ��ȭ
    if (bHasAcceleration)
    {
        IdleElpasedTime = 0.0f;
        bShouldEnterRelaxState = false;
    }
    else
    {
        //IdleElpasedTime �ð��� ���ϱ�, ������ ���°��� �Ӱ谪���� Ŭ���
        IdleElpasedTime += DeltaSeconds;
        bShouldEnterRelaxState = (IdleElpasedTime >= EnterRelaxStateThreshold);
    }

}
