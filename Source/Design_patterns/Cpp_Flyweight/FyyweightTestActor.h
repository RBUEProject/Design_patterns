// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FlyweightFactory.h"
#include "Kismet/KismetSystemLibrary.h"
#include "FyyweightTestActor.generated.h"

UCLASS()
class DESIGN_PATTERNS_API AFlyweightTestActor : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY()
		AFlyweightFactory* m_pFlyweightFactory;

	UPROPERTY()
		FTimerHandle TimerHandle;

	// 定时生成地鼠或炸弹
	UFUNCTION()
		void AutoSpawner();


};

void AFlyweightTestActor::BeginPlay()
{
	Super::BeginPlay();

	// 享元工厂实例
	m_pFlyweightFactory = GetWorld()->SpawnActor<AFlyweightFactory>(AFlyweightFactory::StaticClass());
	m_pFlyweightFactory->Init();

	// 定时器
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AFlyweightTestActor::AutoSpawner, 0.4f, true);
}

void AFlyweightTestActor::AutoSpawner()
{
	// 随机位置
	int32 RandomInt = UKismetMathLibrary::RandomInteger(16);
	FVector RandomPos = FVector::ZeroVector + FVector(1, 0, 0) * (RandomInt / 4) + FVector(0, 1, 0) * (RandomInt % 4);
	// 获取随机空闲的地鼠或炸弹
	AFlyweightObject* FlyweightObj = m_pFlyweightFactory->GetRandomElement();
	if (FlyweightObj)
	{
		// 初始化享元对象
		FlyweightObj->Init(RandomPos);

		// 假定一定概率击中
		if (UKismetMathLibrary::RandomFloat() < 0.2)
		{
			FLatentActionInfo LatentActionInfo;
			UKismetSystemLibrary::Delay(GetWorld(), 0.1, LatentActionInfo);
			FlyweightObj->Hit();
		}

	}

}
