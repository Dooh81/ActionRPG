// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/HeroWeaponBase.h"
#include "Components/BoxComponent.h"

// Sets default values
AHeroWeaponBase::AHeroWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
    SetRootComponent(WeaponMesh);

    WeaponCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponCollisionBox"));

    WeaponCollisionBox->SetupAttachment(GetRootComponent());
    WeaponCollisionBox->SetBoxExtent(FVector(20.0f));
    WeaponCollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

