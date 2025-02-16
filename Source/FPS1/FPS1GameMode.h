// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPS1GameMode.generated.h"

UCLASS(minimalapi)
class AFPS1GameMode : public AGameModeBase
{
	GENERATED_BODY()

	FTimerHandle GameTimer;
	FTimerHandle UITimer;

	void StartPlay() override;

public:
	AFPS1GameMode();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void TimeOut();

	UFUNCTION()
	void UpdateTime();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float GameTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float UITime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DeltaTime;


};



