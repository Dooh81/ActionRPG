// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/ActionRpgCharcterAnimInstance.h"
#include "Characters/ActionRPGBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UActionRpgCharcterAnimInstance::NativeInitializeAnimation()
{

    OwningCharacter = Cast<AActionRPGBaseCharacter>(TryGetPawnOwner());

    if (OwningCharacter != nullptr)
    {
       OwningMovementComponent = OwningCharacter->GetCharacterMovement();
    }
}

void UActionRpgCharcterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
    if (!OwningCharacter || !OwningMovementComponent)
    {
        return;
    }

    GroundSpeed = OwningCharacter->GetVelocity().Size2D();
    bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f; //0보다 크다는 가속도가 있다는 뜻
}
