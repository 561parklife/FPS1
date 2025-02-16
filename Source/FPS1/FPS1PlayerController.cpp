// Copyright Epic Games, Inc. All Rights Reserved.


#include "FPS1PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerState.h"
#include "Engine/LocalPlayer.h"

void AFPS1PlayerController::BeginPlay()
{
	Super::BeginPlay();
	PlayerState->SetScore(0.0f);
	UE_LOG(LogTemp, Warning, TEXT("Score is: %f"), PlayerState->GetScore());
	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
}

void AFPS1PlayerController::InitPlayerState()
{
	Super::InitPlayerState();
	return;
}

void AFPS1PlayerController::HitTarget(const float ShootScore)
{
	PlayerState->SetScore(PlayerState->GetScore()+ ShootScore);
	UE_LOG(LogTemp, Warning, TEXT("Score is: %f"), PlayerState->GetScore());
}
