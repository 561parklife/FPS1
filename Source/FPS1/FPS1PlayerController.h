// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FPS1PlayerController.generated.h"

class UInputMappingContext;

/**
 *
 */
UCLASS()
class FPS1_API AFPS1PlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:

	/** Input Mapping Context to be used for player input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;

	// Begin Actor interface
protected:

	virtual void BeginPlay() override;
	virtual void InitPlayerState() override;

	// End Actor interface
public:
	//UFUNCTION()
	void HitTarget(const float ShootScore);
};
