// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponManager.generated.h"

class UTP_WeaponComponent;
class AFPS1Character;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSwitchWeaponDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPS1_API UWeaponManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponManager();

	UPROPERTY(BlueprintAssignable, Category = "Weapon")
	FOnSwitchWeaponDelegate OnSwitchWeapon;

	// Add a weapon component to the manager
	UFUNCTION(BlueprintCallable, Category = "Weapons")
	void AddWeapon(UTP_WeaponComponent* NewWeapon);

	UFUNCTION(BlueprintCallable, Category = "Weapons")
	void SwitchWeapon(const FInputActionValue& Value);

	//UFUNCTION(BlueprintImplementableEvent, Category = "Weapon")
	//void OnSwitchWeapon_BP();

	UFUNCTION(BlueprintCallable, Category = "Weapons")
	UTP_WeaponComponent* GetCurrentWeapon() const;

protected:
	virtual void BeginPlay() override;

private:	
	TObjectPtr<AFPS1Character> Character;

	TObjectPtr<UTP_WeaponComponent> DefaultWeapon;

	struct FWeaponNode
	{
		TObjectPtr<UTP_WeaponComponent> Weapon;
		int Next;
		int Prev;

		FWeaponNode(UTP_WeaponComponent* InWeapon, int index);
	};

	int CurrentWeaponIndex;
	int LastWeaponIndex;

	TArray<FWeaponNode, TInlineAllocator<6>> WeaponNodePool;
};
