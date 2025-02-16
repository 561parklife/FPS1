// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPS1GameMode.h"
#include "FPS1Character.h"
#include "GameFramework/PlayerState.h"
#include "UObject/ConstructorHelpers.h"

void AFPS1GameMode::StartPlay()
{
	Super::StartPlay();
	UITime = GameTime;
	GetWorld()->GetTimerManager().SetTimer(GameTimer, this, &AFPS1GameMode::TimeOut, GameTime, false);
	GetWorld()->GetTimerManager().SetTimer(UITimer, this, &AFPS1GameMode::UpdateTime, DeltaTime, true);
}

AFPS1GameMode::AFPS1GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
	PlayerStateClass = APlayerState::StaticClass();
	GameTime = 10.0f;
	DeltaTime = 1.0f;
}

void AFPS1GameMode::UpdateTime()
{
	UITime -= DeltaTime;
}
