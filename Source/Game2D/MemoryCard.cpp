// Fill out your copyright notice in the Description page of Project Settings.

#include "Game2D.h"
#include "MemoryCard.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"
#include "MemoryGamePawn.h"


// Sets default values
AMemoryCard::AMemoryCard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>
		(TEXT("Sprite"));
	Sprite->SetSprite(ClosedSprite);
	Sprite->OnInputTouchBegin.AddDynamic(this, 
		&AMemoryCard::OnTouchBegin);
	RootComponent = Sprite;
}

// Called when the game starts or when spawned
void AMemoryCard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMemoryCard::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AMemoryCard::OnTouchBegin(ETouchIndex::Type type, 
	UPrimitiveComponent* TouchedComponent) {

	UE_LOG(LogTemp, Warning, TEXT("It works!"));

	UWorld* World = GetWorld();

	if (World != nullptr) {
		AMemoryGamePawn* Pawn = Cast<AMemoryGamePawn>
			(UGameplayStatics::GetPlayerController
			(World, 0)->GetControlledPawn());
	}

}