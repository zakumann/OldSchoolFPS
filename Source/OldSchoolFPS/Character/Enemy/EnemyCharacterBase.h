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

	// Health variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float MaxHealth = 100.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stats")
	float CurrentHealth;

public:
    /** Apply damage to this enemy */
    UFUNCTION(BlueprintCallable, Category = "Combat")
    virtual void ApplyDamage(float DamageAmount);

    /** Called when health reaches zero */
    UFUNCTION(BlueprintNativeEvent, Category = "Combat")
    void Die();
    virtual void Die_Implementation();

    /** Returns true if health is zero or below */
    UFUNCTION(BlueprintCallable, Category = "Combat")
    bool IsDead() const { return CurrentHealth <= 0.0f; }

    /** Returns current health value */
    UFUNCTION(BlueprintCallable, Category = "Combat")
    float GetCurrentHealth() const { return CurrentHealth; }
};
