// Fill out your copyright notice in the Description page of Project Settings.

#include "Game2D.h"
#include "Game2DGameMode.h"
#include "MemoryCardPlayerController.h"

AGame2DGameMode::AGame2DGameMode() {

	PlayerControllerClass = AMemoryCardPlayerController::StaticClass();

}




