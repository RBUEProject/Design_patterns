// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MonsterPrototype.h"
#include "MonsterSpawner.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class DESIGN_PATTERNS_API UMonsterSpawner : public UObject
{
	GENERATED_BODY()
public:
	template<class T>
	T*SpawnMonster()
	{
		return NewObject<T>();
	}

	UMonsterPrototype*SpawnMonster(UMonsterPrototype*pMonster)
	{
		return pMonster->Clone();
	}
};
