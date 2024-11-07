// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HeroWeaponBase.generated.h"

class UBoxComponent;
UCLASS()
class ACTIONRPG_API AHeroWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHeroWeaponBase();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Weapons")
    UStaticMeshComponent* WeaponMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapons")
    UBoxComponent* WeaponCollisionBox;

public:
    FORCEINLINE UBoxComponent* GetWeapneCollisionBox() const { return WeaponCollisionBox; }
};