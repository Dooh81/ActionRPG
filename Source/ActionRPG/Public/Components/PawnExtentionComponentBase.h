// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnExtentionComponentBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ACTIONRPG_API UPawnExtentionComponentBase : public UActorComponent
{
	GENERATED_BODY()
		
protected:
    template <class T>
    T* GetOwningPawn() const
    {
        static_assert(TPointerIsConvertibleFromTo<T, APawn>::Value, "'T' Template Parameter to GetPawn must be derived from Apawn");
        return CastChecked<T>(GetOwner());
    }

    APawn* GetOwningPawn() const
    {
        return GetOwningPawn<APawn>();
    }

    template <class T>
    T* GetOwningController() const
    {
        static_assert(TPointerIsConvertibleFromTo<T, AController>::Value, "'T' Template Parameter to GetController must be derived from AController");
        GetOwningPawn<APawn>()->GetController<T>();
    }
};
