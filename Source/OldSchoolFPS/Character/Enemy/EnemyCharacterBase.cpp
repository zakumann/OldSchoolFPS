// Fill out your copyright notice in the Description page of Project Settings.


#include "OldSchoolFPS/Character/Enemy/EnemyCharacterBase.h"

// Sets default values
AEnemyCharacterBase::AEnemyCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Health = 100.0f;
}

// Called when the game starts or when spawned
void AEnemyCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemyCharacterBase::TakeDamage(float DamageAmount)
{
    Health -= DamageAmount;
    if (Health <= 0.0f)
    {
        Destroy();
    }
}
