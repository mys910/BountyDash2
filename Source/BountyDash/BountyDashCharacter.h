// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
	//�̵� ���� �迭

	UPROPERTY(EditAnywhere, Category = Logic)
	float CharSpeed;
	//ĳ���� �� �ٲ� �ӵ�

	UPROPERTY(EditAnywhere, Category = Sound)
	UAudioComponent* hitObstacleSound;
	//�浹 ���带 ���� ����� ������Ʈ

	UPROPERTY(EditAnywhere, Category = Sound)
	UAudioComponent* dingSound;
	//���� ȹ�� ���带 ���� ����� ������Ʈ

protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class USpringArmComponent* CameraBoom;
	//�÷��̾�� ī�޶� �Ÿ� ���� ���� ī�޶� ��

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class UCameraComponent* FollowCamera;
	//Ÿ�� ��� ��� �� ī�޶�

	UPROPERTY(BlueprintReadOnly)
	int32 Score;
	//�÷��̾� ����

private:
	short CurrentLocation;
	FVector DesiredLocation;
	bool bBeingPushed;
	//ĳ���� �� �ִ� ��ġ ������

public:
	void ScoreUp();

protected:

	void MoveRight();
	void MoveLeft();
	//�÷��̾� �¿��� Ÿ�� ��ġ �̵��� ����

	UFUNCTION()
	void MyOnComponentBeginOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void MyOnComponentEndOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	//������Ʈ �ݸ��� ĸ���� ��� �Ǵ� ������ �Լ�
};
