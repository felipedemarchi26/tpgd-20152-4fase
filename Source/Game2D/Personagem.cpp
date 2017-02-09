// Fill out your copyright notice in the Description page of Project Settings.

#include "Game2D.h"
#include "Personagem.h"
#include "PaperFlipbookComponent.h"

APersonagem::APersonagem() {
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->TargetArmLength = 500.0f;
	CameraBoom->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->ProjectionMode = ECameraProjectionMode::Orthographic;
	Camera->OrthoWidth = 2048.0f;
	Camera->SetupAttachment(CameraBoom);
}

void APersonagem::BeginPlay() {
	Super::BeginPlay();

	GetSprite()->SetFlipbook(Idle);
}

void APersonagem::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Move", this, &APersonagem::Move);
}

void APersonagem::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);

	UpdateFlipbook();
}

void APersonagem::Move(float Value) {
	AddMovementInput(FVector(1.0f, 0.0f, 0.0f), Value);
}

void APersonagem::UpdateFlipbook() {
	if (GetVelocity().X != 0) {
		if (GetSprite()->GetFlipbook() != Walking) {
			GetSprite()->SetFlipbook(Walking);
		}
	} else {
		if (GetSprite()->GetFlipbook() != Idle) {
			GetSprite()->SetFlipbook(Idle);
		}
	}
}
