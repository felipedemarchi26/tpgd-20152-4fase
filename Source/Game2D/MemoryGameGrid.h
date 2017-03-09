// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MemoryGameGrid.generated.h"

UCLASS()
class GAME2D_API AMemoryGameGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMemoryGameGrid();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

private:

	UPROPERTY(EditAnywhere)
		USceneComponent* Root;

	TSubclassOf<class AMemoryCard> BullCard;
	TSubclassOf<class AMemoryCard> SheepCard;
	TSubclassOf<class AMemoryCard> CatCard;
	TSubclassOf<class AMemoryCard> MouseCard;
	
};
