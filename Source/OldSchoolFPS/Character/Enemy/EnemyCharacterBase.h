// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacterBase.generated.h"

UCLASS()
class OLDSCHOOLFPS_API AEnemyCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Health
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	float Health;

	// Damage function
	UFUNCTION()
	virtual void TakeDamage(float DamageAmount);
};
