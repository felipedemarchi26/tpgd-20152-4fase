// Fill out your copyright notice in the Description page of Project Settings.

#include "Game2D.h"
#include "MemoryGamePawn.h"
#include "MemoryCard.h"


// Sets default values
AMemoryGamePawn::AMemoryGamePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>
		(TEXT("Camera"));
	Camera->ProjectionMode = ECameraProjectionMode::Orthographic;
	Camera->OrthoWidth = 2048.0f;
	Camera->SetupAttachment(RootComponent);

	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void AMemoryGamePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMemoryGamePawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AMemoryGamePawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void AMemoryGamePawn::AddCard(class AMemoryCard* Card) {
	if (FirstCard == nullptr) {
		FirstCard = Card;
	} else if (SecondCard == nullptr) {
		SecondCard = Card;
	}
}

void AMemoryGamePawn::CheckCards() {
	if (FirstCard != nullptr && SecondCard != nullptr) {
		if (FirstCard->GetIndex() == SecondCard->GetIndex()) {
			FirstCard->Destroy();
			SecondCard->Destroy();
			FirstCard = nullptr;
			SecondCard = nullptr;
		} else {
			UWorld* World = GetWorld();
			if (World != nullptr) {
				GetWorldTimerManager().SetTimer(TimerTurnOff, this,
					&AMemoryGamePawn::TurnCardsOff, 2.0f, true);
				bFreeze = true;
			}
		}
	}
}

void AMemoryGamePawn::TurnCardsOff() {
	FirstCard->TurnOff();
	SecondCard->TurnOff();
	FirstCard = nullptr;
	SecondCard = nullptr;
	bFreeze = false;
	GetWorldTimerManager().ClearTimer(TimerTurnOff);
}

bool AMemoryGamePawn::IsFreeze() {
	return bFreeze;
}