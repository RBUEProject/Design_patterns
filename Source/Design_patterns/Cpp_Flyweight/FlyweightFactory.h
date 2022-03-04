// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FlyweightObject.h"
#include "Kismet/KismetMathLibrary.h"
#include "FlyweightFactory.generated.h"

// 享元工厂类 
UCLASS()
class DESIGN_PATTERNS_API AFlyweightFactory : public AActor
{
	GENERATED_BODY()
public:
	// 初始化多个地鼠和炸弹实例以供使用
	void Init() {
		for (int32 i = 0; i < 3; i++)
		{
			AMole* mole = GetWorld()->SpawnActor<AMole>(FVector::ZeroVector, FRotator::ZeroRotator);
			m_pMolePool.Add(mole->GetName(), mole);

			ABomb* bomb = GetWorld()->SpawnActor<ABomb>(FVector::ZeroVector, FRotator::ZeroRotator);
			m_pBombPool.Add(bomb->GetName(), bomb);
		}
	}

	// 获取未被使用的地鼠实例
	AMole* GetMole() {
		for (TTuple<FString, AMole*>& item : m_pMolePool)
		{
			if (!(item.Value)->IsLiving())
			{
				return item.Value;
			}
		}
		return nullptr;
	}

	// 获取未被使用的炸弹实例
	ABomb* GetBomb() {
		for (TTuple<FString, ABomb*>& item : m_pBombPool)
		{
			if (!(item.Value)->IsLiving())
			{
				return item.Value;
			}
		}
		return nullptr;
	}

	// 随机获取未被使用的地鼠或炸弹实例
	AFlyweightObject* GetRandomElement() {
		if (UKismetMathLibrary::RandomFloat() < 0.7f)
		{
			return GetMole();
		}
		else
		{
			return GetBomb();
		}

	}

private:
	// 存储的地鼠对象池
	UPROPERTY()
		TMap<FString, AMole*> m_pMolePool;

	// 存储的炸弹对象池
	UPROPERTY()
		TMap<FString, ABomb*> m_pBombPool;
};