// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetBox.h"
#include "Components/BoxComponent.h"
//#include "Kismet/GameplayStatics.h"
#include "FPS1Projectile.h"
#include "FPS1PlayerController.h"


ATargetBox::ATargetBox()
	:Super()
{
	BoxType = EBoxType::BasicBox;
	
	ValuableMultiple = 3;
	ValuableThreshold = 5;
	bValuable = false;

	hp = 20;

	BoxMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DefaultMesh"));
	RootComponent = BoxMesh;
	// Find and assign a mesh asset
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/LevelPrototyping/Meshes/SM_ChamferCube.SM_ChamferCube"));
	//if (MeshAsset.Succeeded())
	//{
	//	BoxMesh->SetStaticMesh(MeshAsset.Object);
	//}
	BoxMesh->SetMobility(EComponentMobility::Movable);
	BoxMesh->SetSimulatePhysics(true);
	BoxMesh->SetCollisionProfileName(TEXT("PhysicsActor"));
	//BoxMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	//BoxMesh->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);
	BoxMesh->OnComponentHit.AddDynamic(this, &ATargetBox::OnHit);

	//static ConstructorHelpers::FObjectFinder<UMaterialInstance> DefaultMaterialAsset(TEXT("/Game/LevelPrototyping/Materials/MI_Solid_Blue"));
	//if (DefaultMaterialAsset.Succeeded())
	//{
	//	DefaultMaterial = DefaultMaterialAsset.Object;
	//}
	//static ConstructorHelpers::FObjectFinder<UMaterialInstance> DamagedMaterialAsset(TEXT("/Game/LevelPrototyping/Materials/MI_Solid_Red"));
	//if (DamagedMaterialAsset.Succeeded())
	//{
	//	DamagedMaterial = DamagedMaterialAsset.Object;
	//}


	//CollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
	//CollisionComp->SetupAttachment(RootComponent);
	//CollisionComp->SetBoxExtent(FVector(55.0f, 55.0f, 55.0f));
	//CollisionComp->SetGenerateOverlapEvents(false);
	//CollisionComp->SetCollisionProfileName(TEXT("BlockAll"));
	//CollisionComp->OnComponentHit.AddDynamic(this, &ATargetBox::OnHit);
}

//FString ATargetBox::GetLuaFilePath_Implementation() const
//{
//	return "ScalableBox";
//}

void ATargetBox::BeginPlay()
{
	Super::BeginPlay();
	int ValueRandom = FMath::RandRange(1, 10);
	if (ValueRandom > ValuableThreshold)
	{
		bValuable = true;
		DefaultMaterial = ValuableMaterial;
		BoxMesh->SetMaterial(0, DefaultMaterial);
	}
}

void ATargetBox::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//if (IsLuaFunctionExist("OnHit"))
	//{
	//	CallLuaFunction("OnHit", HitComp, OtherActor, OtherComp, NormalImpulse, Hit);
	//}
	
	if (AFPS1Projectile* projectile = Cast<AFPS1Projectile>(OtherActor))
	{
		AController* Shooter = projectile->GetShooter();
		if (AFPS1PlayerController* PlayerShooter = Cast<AFPS1PlayerController>(Shooter))
		{
			if (bValuable) PlayerShooter->HitTarget(1.0f * ValuableMultiple);
			else PlayerShooter->HitTarget(1.0f);
			UE_LOG(LogTemp, Warning, TEXT("Hit!"));
		}
		BoxMesh->SetMaterial(0, DamagedMaterial);
		hp -= projectile->ProjectileDamage;
		if (hp <= 0)Destroy();
		GetWorld()->GetTimerManager().SetTimer(DamageTimer, this, &ATargetBox::ResetDamage, 1.5f, false);
		//UGameplayStatics::ApplyDamage(this, 20.0f, Shooter, OtherActor, UDamageType::StaticClass());
		//OnTakeDamage();
	}
	return;
}

void ATargetBox::OnTakeDamage()
{
	BoxMesh->SetMaterial(0, DamagedMaterial);
	GetWorld()->GetTimerManager().SetTimer(DamageTimer, this, &ATargetBox::ResetDamage, 1.5f, false);
}

void ATargetBox::ResetDamage()
{
	BoxMesh->SetMaterial(0, DefaultMaterial);
}

