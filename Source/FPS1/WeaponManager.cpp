// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponManager.h"
#include "FPS1Character.h"
#include "InputActionValue.h"
#include "TP_WeaponComponent.h"

// Sets default values for this component's properties
UWeaponManager::UWeaponManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	WeaponNodePool.Empty();
	for (int i = 0; i < 6; i++)
	{
		WeaponNodePool.Add(FWeaponNode(nullptr, i));
	}
	DefaultWeapon = CreateDefaultSubobject<UTP_WeaponComponent>(TEXT("DefaultWeapon"));
	CurrentWeaponIndex = 0;
	LastWeaponIndex = 0;
	WeaponNodePool[0].Weapon = DefaultWeapon;
}

//// Called when the game starts
void UWeaponManager::BeginPlay()
{
	Super::BeginPlay();
	Character = Cast<AFPS1Character>(GetOwner());
	GetCurrentWeapon()->AttachWeapon(Character);
}

void UWeaponManager::AddWeapon(UTP_WeaponComponent* NewWeapon)
{
	if (NewWeapon)
	{
		for (int i = 0; i < 6; i++)
		{
			if (!WeaponNodePool[i].Weapon)
			{
				WeaponNodePool[i].Weapon = NewWeapon;
				int next = WeaponNodePool[LastWeaponIndex].Next;
				WeaponNodePool[i].Prev = LastWeaponIndex;
				WeaponNodePool[i].Next = next;
				WeaponNodePool[LastWeaponIndex].Next = i;
				WeaponNodePool[next].Prev = i;
				LastWeaponIndex = i;
				//hide in bag
				NewWeapon->SetVisibility(false, true);
				NewWeapon->SetComponentTickEnabled(false);
				break;
			}
		}
	}
}

void UWeaponManager::SwitchWeapon(const FInputActionValue& Value)
{
	int TargetWeaponIndex;
	if (Value.Get<float>() > 0) TargetWeaponIndex = WeaponNodePool[CurrentWeaponIndex].Next;
	else TargetWeaponIndex = WeaponNodePool[CurrentWeaponIndex].Prev;
	WeaponNodePool[CurrentWeaponIndex].Weapon->DisattachWeapon();
	CurrentWeaponIndex = TargetWeaponIndex;
	WeaponNodePool[CurrentWeaponIndex].Weapon->AttachWeapon(Character);
	UE_LOG(LogTemp, Warning, TEXT("Weapon: %d"), CurrentWeaponIndex);
	OnSwitchWeapon.Broadcast();
}

UTP_WeaponComponent* UWeaponManager::GetCurrentWeapon() const
{
	return WeaponNodePool[CurrentWeaponIndex].Weapon;
}

UWeaponManager::FWeaponNode::FWeaponNode(UTP_WeaponComponent* InWeapon, int index)
{
	Weapon = InWeapon;
	Next = index;
	Prev = index;
}
