// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinSpawner.h"
#include "Floor.h"
#include "Coin.h"
#include "EngineUtils.h"
#include "Engine/TargetPoint.h"
#include "Components/SphereComponent.h"
#include "BountyDashPowerUp.h"

// Sets default values
ACoinSpawner::ACoinSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	MaxSetCoins = 5;
	MinSetCoins = 3;
	CoinSetTimeInterval = 4.0f;
	CoinTimeInterval = 0.5f;
	MovementTimeInterval = 1.0f;
}

// Called when the game starts or when spawned
void ACoinSpawner::BeginPlay()
{
	Super::BeginPlay();

	//GetAllActorOfClass
	for (TActorIterator<ATargetPoint>TargetIter(GetWorld()); TargetIter; ++TargetIter)
	{
		SpawnTransforms.Add(*TargetIter);
	}

	for (TActorIterator<AFloor> FloorIter(GetWorld()); FloorIter; ++FloorIter)
	{
		if (FloorIter->GetWorld() == GetWorld())
		{
			killPoint = FloorIter->GetKillPoint();
			SpawnPoint = FloorIter->GetSpawnPoint();
		}
	}

	FTimerManager& worldTimeManager = GetWorld()->GetTimerManager();

	worldTimeManager.SetTimer(CoinSetTimerHandle, this, &ACoinSpawner::SpawnCoinSet, CoinSetTimeInterval, false);
	worldTimeManager.SetTimer(SpawnMoveTimerHandle, this, &ACoinSpawner::MoveSpawner, MovementTimeInterval, true);

}

// Called every frame
void ACoinSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACoinSpawner::SpawnCoin()
{
	if (FMath::Rand() % 100 < PowerUpChance)
	{
		SpawnPowerUp();
		NumCoinsToSpawn--;
	}
	else
	{
		//스폰 위치 가져오기
		FActorSpawnParameters spawnParams;

		FTransform coinTransform = SpawnTransforms[TargetLoc]->GetTransform();

		coinTransform.SetLocation(FVector(SpawnPoint, coinTransform.GetLocation().Y, coinTransform.GetLocation().Z));

		//Acoin 스폰
		ACoin* spawnedCoin = GetWorld()->SpawnActor<ACoin>(CoinObject, coinTransform, spawnParams);

		//스폰된 코인의 컴포넌트 위치값 세팅
		if (spawnedCoin)
		{
			USphereComponent* coinSphere = Cast<USphereComponent>(spawnedCoin->GetComponentByClass(USphereComponent::StaticClass()));

			if (coinSphere)
			{
				float offset = coinSphere->GetUnscaledSphereRadius();
				spawnedCoin->AddActorLocalOffset(FVector(0.0f, 0.0f, offset));
			}

			NumCoinsToSpawn--;
		}
	}
	if (NumCoinsToSpawn <= 0)
	{
		FTimerManager& worldTimeManager = GetWorld()->GetTimerManager();
		worldTimeManager.SetTimer(CoinSetTimerHandle, this, &ACoinSpawner::SpawnCoinSet, CoinSetTimeInterval, false);
		worldTimeManager.ClearTimer(CoinTimerHandle);
	}
}

void ACoinSpawner::SpawnCoinSet()
{
	NumCoinsToSpawn = FMath::RandRange(MinSetCoins, MaxSetCoins);

	FTimerManager& worldTimeManager = GetWorld()->GetTimerManager();

	//활성화 된 타이머 교체
	worldTimeManager.ClearTimer(CoinSetTimerHandle);

	worldTimeManager.SetTimer(CoinTimerHandle, this, &ACoinSpawner::SpawnCoin, CoinTimeInterval, true);

}

void ACoinSpawner::MoveSpawner()
{
	TargetLoc = FMath::Rand() % SpawnTransforms.Num();

}

void ACoinSpawner::SpawnPowerUp()
{
	FActorSpawnParameters SpawnInfo;

	FTransform myTrans = SpawnTransforms[TargetLoc]->GetTransform();
	myTrans.SetLocation(FVector(SpawnPoint, myTrans.GetLocation().Y, myTrans.GetLocation().Z));

	ABountyDashPowerUp* newObs = GetWorld()->SpawnActor<ABountyDashPowerUp>(PowerUpObject, myTrans, SpawnInfo);

	if (newObs)
	{
		newObs->SetKillPoint(killPoint);
		USphereComponent* powerUpSphere = Cast<USphereComponent>(newObs->GetComponentByClass(USphereComponent::StaticClass()));

		if (powerUpSphere)
		{
			float offset = powerUpSphere->GetUnscaledSphereRadius();
			newObs->AddActorLocalOffset(FVector(0.0f, 0.0f, offset));
		}
	}
}

