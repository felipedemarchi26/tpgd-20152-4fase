// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "MemoryGamePawn.generated.h"

UCLASS()
class GAME2D_API AMemoryGamePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMemoryGamePawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void AddCard(class AMemoryCard* Card);

	void CheckCards();

	bool IsFreeze();

private:

	UPROPERTY(EditAnywhere)
		UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
		class AMemoryCard* FirstCard;

	UPROPERTY(EditAnywhere)
		class AMemoryCard* SecondCard;

	FTimerHandle TimerTurnOff;

	void TurnCardsOff();

	bool bFreeze;

	
};
