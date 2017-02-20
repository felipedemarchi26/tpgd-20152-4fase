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

	FORCEINLINE int GetCoins() const { return Coins; }
	FORCEINLINE void SetCoins(int NewCoins) { Coins = NewCoins; }

private:

	UPROPERTY(EditAnywhere)
		USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere)
		UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
		class UPaperFlipbook* Idle;

	UPROPERTY(EditAnywhere)
		class UPaperFlipbook* Walking;

	UPROPERTY(EditAnywhere)
		int Coins;

	UPROPERTY(EditAnywhere)
		UChildActorComponent* ChildGun;

	void Move(float Value);
	
	void UpdateFlipbook();

	void UpdateFlipbookRotation();
	
	void TouchStarted(const ETouchIndex::Type FinderIndex,
		const FVector Location);

	void TouchStopped(const ETouchIndex::Type FinderIndex,
		const FVector Location);

	void OnStartFire();

	void OnStopFire();

	void NoGun();

	void FirstGun();

};
