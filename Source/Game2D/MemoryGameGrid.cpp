// Fill out your copyright notice in the Description page of Project Settings.

#include "Game2D.h"
#include "MemoryGameGrid.h"
#include "MemoryCard.h"


// Sets default values
AMemoryGameGrid::AMemoryGameGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	ConstructorHelpers::FObjectFinder<UBlueprint> BullBP
		(TEXT("Blueprint'/Game/Bluepritns/MemoryGame/BullMemoryCardBP.BullMemoryCardBP'"));
	ConstructorHelpers::FObjectFinder<UBlueprint> CatBP
		(TEXT("Blueprint'/Game/Bluepritns/MemoryGame/CatMemoryCardBP.CatMemoryCardBP'"));
	ConstructorHelpers::FObjectFinder<UBlueprint> MouseBP
		(TEXT("Blueprint'/Game/Bluepritns/MemoryGame/MouseMemoryCardBP.MouseMemoryCardBP'"));
	ConstructorHelpers::FObjectFinder<UBlueprint> SheepBP
		(TEXT("Blueprint'/Game/Bluepritns/MemoryGame/SheepMemoryCardBP.SheepMemoryCardBP'"));

	if (BullBP.Succeeded()) {
		BullCard = Cast<UClass>(BullBP.Object->GeneratedClass);
	}
	if (CatBP.Succeeded()) {
		CatCard = Cast<UClass>(CatBP.Object->GeneratedClass);
	}
	if (MouseBP.Succeeded()) {
		MouseCard = Cast<UClass>(MouseBP.Object->GeneratedClass);
	}
	if (SheepBP.Succeeded()) {
		SheepCard = Cast<UClass>(SheepBP.Object->GeneratedClass);
	}
}

// Called when the game starts or when spawned
void AMemoryGameGrid::BeginPlay()
{
	Super::BeginPlay();
	
	float LocationX = 0.0f;
	float LocationZ = 0.0f;

	UWorld* World = GetWorld();
	if (World != nullptr) {
		FVector Location(LocationX, 0.0f, LocationZ);
		FActorSpawnParameters SpawnParameters;
		AMemoryCard* MemoryCard = World->SpawnActor<AMemoryCard>(
			CatCard, Location, FRotator::ZeroRotator, SpawnParameters);

	}
}

// Called every frame
void AMemoryGameGrid::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

