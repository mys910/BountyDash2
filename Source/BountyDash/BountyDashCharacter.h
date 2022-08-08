// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BountyDash.h"
#include "GameFramework/Character.h"
#include "BountyDashCharacter.generated.h"

UCLASS()
class BOUNTYDASH_API ABountyDashCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABountyDashCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:

	UPROPERTY(EditAnywhere, Category = Logic)
	TArray<class ATargetPoint*> TargetArray;
	//이동 방향 배열

	UPROPERTY(EditAnywhere, Category = Logic)
	float CharSpeed;
	//캐릭터 줄 바꿈 속도

	UPROPERTY(EditAnywhere, Category = Sound)
	UAudioComponent* hitObstacleSound;
	//충돌 사운드를 위한 오디오 컴포넌트

	UPROPERTY(EditAnywhere, Category = Sound)
	UAudioComponent* dingSound;
	//코인 획득 사운드를 위한 오디오 컴포넌트

protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class USpringArmComponent* CameraBoom;
	//플레이어와 카메라 거리 유지 위한 카메라 붐

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class UCameraComponent* FollowCamera;
	//타겟 뷰로 사용 할 카메라

	UPROPERTY(BlueprintReadOnly)
	int32 Score;
	//플레이어 점수

private:
	short CurrentLocation;
	FVector DesiredLocation;
	bool bBeingPushed;
	//캐릭터 서 있는 위치 데이터

public:
	void ScoreUp();

protected:

	void MoveRight();
	void MoveLeft();
	//플레이어 좌우의 타깃 위치 이동을 조정

	UFUNCTION()
	void MyOnComponentBeginOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void MyOnComponentEndOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	//컴포넌트 콜리전 캡슐에 사용 되는 오버랩 함수
};
