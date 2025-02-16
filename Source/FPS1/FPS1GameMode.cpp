// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPS1GameMode.h"
#include "FPS1Character.h"
#include "GameFramework/PlayerState.h"
#include "UObject/ConstructorHelpers.h"

AFPS1GameMode::AFPS1GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
	PlayerStateClass = APlayerState::StaticClass();
}
