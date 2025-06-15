// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "InputActionValue.h"
#include "PlayableCharacter.generated.h"

UCLASS()
class OLDSCHOOLFPS_API APlayableCharacter : public ABaseCharacter
{
	GENERATED_BODY()
	
public:
	APlayableCharacter();

    // Input mappings and actions
    UPROPERTY(EditDefaultsOnly, Category = Input)
    class UInputMappingContext* DefaultMappingContext;

    UPROPERTY(EditDefaultsOnly, Category = Input)
    class UInputAction* MoveAction;

    UPROPERTY(EditDefaultsOnly, Category = Input)
    class UInputAction* LookAction;

    // Input callbacks
    void Move(const FInputActionValue& Value);
    void Look(const FInputActionValue& Value);

protected:
    virtual void BeginPlay() override;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
