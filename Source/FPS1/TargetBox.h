// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LuaOverriderInterface.h"
#include "TargetBox.generated.h"

class UBoxComponent;
class UStaticMeshComponent;

/**
 * 
 */
UENUM(BlueprintType)
enum class EBoxType : uint8
{
	BasicBox,
	ScalableBox,
	BreakbleBox,
};

UCLASS()
class FPS1_API ATargetBox : public AActor, public ILuaOverriderInterface
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Custom, meta = (AllowPrivateAccess = "true"))
	EBoxType BoxType; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Rendering, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> BoxMesh;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Collision, meta = (AllowPrivateAccess = "true"))
	//TObjectPtr<UBoxComponent> CollisionComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Rendering, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMaterialInstance> DefaultMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Rendering, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMaterialInstance> DamagedMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Rendering, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMaterialInstance> ValuableMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Custom, meta = (AllowPrivateAccess = "true"))
	bool bValuable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Custom, meta = (AllowPrivateAccess = "true"))
	int ValuableMultiple;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Custom, meta = (AllowPrivateAccess = "true"))
	int ValuableThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Custom, meta = (AllowPrivateAccess = "true"))
	int hp;

	FTimerHandle DamageTimer;

protected:

	virtual void BeginPlay() override;

	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	///** Returns CollisionComp subobject **/
	//UBoxComponent* GetCollisionComp() const { return CollisionComp; }

	void OnTakeDamage();

	void ResetDamage(); 

	//virtual FString GetLuaFilePath_Implementation() const override;

public:
	ATargetBox();
	
	
	
};
