// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "PlayerCharacter.generated.h"

class UInputAction;
class UInputMappingContext;

UCLASS()
class OLDSCHOOLFPS_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Input Actions
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_MoveForward;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_MoveRight;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_LookUp;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_Turn;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* JumpAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* FireAction;

	// Sprint input action
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_Sprint;

	// Base and sprint speeds
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	float WalkSpeed = 800.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	float SprintSpeed = 1400.f;

	// Movement functions
	void MoveForward(const FInputActionValue& Value);
	void MoveRight(const FInputActionValue& Value);

	// Look functions
	void LookUp(const FInputActionValue& Value);
	void Turn(const FInputActionValue& Value);
	
	//Fire
	void Fire();

	// Sprint handlers
	void StartSprinting();
	void StopSprinting();

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
