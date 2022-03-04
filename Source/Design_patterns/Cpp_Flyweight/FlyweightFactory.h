// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FlyweightObject.h"
#include "Kismet/KismetMathLibrary.h"
#include "FlyweightFactory.generated.h"

// ��Ԫ������ 
UCLASS()
class DESIGN_PATTERNS_API AFlyweightFactory : public AActor
{
	GENERATED_BODY()
public:
	// ��ʼ����������ը��ʵ���Թ�ʹ��
	void Init() {
		for (int32 i = 0; i < 3; i++)
		{
			AMole* mole = GetWorld()->SpawnActor<AMole>(FVector::ZeroVector, FRotator::ZeroRotator);
			m_pMolePool.Add(mole->GetName(), mole);

			ABomb* bomb = GetWorld()->SpawnActor<ABomb>(FVector::ZeroVector, FRotator::ZeroRotator);
			m_pBombPool.Add(bomb->GetName(), bomb);
		}
	}

	// ��ȡδ��ʹ�õĵ���ʵ��
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

	// ��ȡδ��ʹ�õ�ը��ʵ��
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

	// �����ȡδ��ʹ�õĵ����ը��ʵ��
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
	// �洢�ĵ�������
	UPROPERTY()
		TMap<FString, AMole*> m_pMolePool;

	// �洢��ը�������
	UPROPERTY()
		TMap<FString, ABomb*> m_pBombPool;
};