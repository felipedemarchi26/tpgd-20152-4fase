// Fill out your copyright notice in the Description page of Project Settings.

#include "Game2D.h"
#include "Gun.h"
#include "PaperSpriteComponent.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
	Sprite->SetCollisionProfileName("NoCollision");
	RootComponent = Sprite;
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
	AmmoAmount = 20;
}

// Called every frame
void AGun::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AGun::StartFire() {
	UE_LOG(LogTemp, Warning, TEXT("Start Fire"));
}

void AGun::StopFire() {
	UE_LOG(LogTemp, Warning, TEXT("Stop Fire"));
}

void AGun::DoFire() {
	UE_LOG(LogTemp, Warning, TEXT("Do Fire"));
}