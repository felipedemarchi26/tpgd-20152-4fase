// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PaperCharacter.h"
#include "Personagem.generated.h"

/**
 * 
 */
UCLASS()
class GAME2D_API APersonagem : public APaperCharacter
{
	GENERATED_BODY()
	
public:

	APersonagem();

	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Tick(float DeltaSeconds) override;

private:

	UPROPERTY(EditAnywhere)
		USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere)
		UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
		class UPaperFlipbook* Idle;

	UPROPERTY(EditAnywhere)
		class UPaperFlipbook* Walking;

	void Move(float Value);
	
	void UpdateFlipbook();
	
};
