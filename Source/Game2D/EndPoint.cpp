// Fill out your copyright notice in the Description page of Project Settings.

#include "Game2D.h"
#include "EndPoint.h"
#include "PaperSpriteComponent.h"
#include "Personagem.h"


// Sets default values
AEndPoint::AEndPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
	Sprite->bGenerateOverlapEvents = true;
	Sprite->SetCollisionProfileName("OverlapAllDynamic");
	Sprite->OnComponentBeginOverlap.AddDynamic(this, &AEndPoint::OnOverlapBegin);
	RootComponent = Sprite;

}

// Called when the game starts or when spawned
void AEndPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEndPoint::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AEndPoint::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if ((OtherActor != nullptr) && (OtherActor->IsA(APersonagem::StaticClass()))) {
		APersonagem* Personagem = Cast<APersonagem>(OtherActor);
		UWorld* World = GetWorld();
		if (Personagem->GetCoins() == 5 && World != nullptr) {
			UGameplayStatics::OpenLevel(World, "Map2");
		}
	}
}

