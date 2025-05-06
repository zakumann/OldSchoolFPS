// Fill out your copyright notice in the Description page of Project Settings.


#include "OldSchoolFPS/Character/Enemy/EnemyCharacterBase.h"

// Sets default values
AEnemyCharacterBase::AEnemyCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth;
}

void AEnemyCharacterBase::ApplyDamage(float DamageAmount)
{
    if (IsDead()) return;

    CurrentHealth -= DamageAmount;

    if (CurrentHealth <= 0.0f)
    {
        Die();
    }
}

void AEnemyCharacterBase::Die_Implementation()
{
    // Default death behavior — can be overridden in Blueprint
    Destroy();
}