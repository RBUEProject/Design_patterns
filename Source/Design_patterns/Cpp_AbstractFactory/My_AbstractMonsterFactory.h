// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "My_AbstractMonster.h"
#include "My_AbstractMonsterFactory.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class DESIGN_PATTERNS_API UMy_AbstractMonsterFactory : public UObject
{
	GENERATED_BODY()
public:
	virtual UMy_SoldierMonster*CreateSoldierMonster()
	{
		check(0&&"you must override this");
		return nullptr;
	}
	virtual UMy_ArcherMonster*CreateArcherMonster()
	{
		check(0 && "you must override this");
		return nullptr;
	}
};

UCLASS(Blueprintable,BlueprintType)
class DESIGN_PATTERNS_API UMy_KolouMonsterFactory :public UMy_AbstractMonsterFactory
{
	GENERATED_BODY()
public:
	virtual UMy_SoldierMonster*CreateSoldierMonster()override
	{
		return NewObject<UMy_KulouSolider>();
	}
	virtual UMy_ArcherMonster*CreateArcherMonster()override
	{
		return NewObject<UMy_KuLouArcher>();
	}
};

UCLASS(Blueprintable, BlueprintType)
class DESIGN_PATTERNS_API UMy_GoblinMonsterFactory :public UMy_AbstractMonsterFactory
{
	GENERATED_BODY()
public:
	virtual UMy_SoldierMonster*CreateSoldierMonster()override
	{
		return NewObject<UMy_GoblinSolider>();
	}
	virtual UMy_ArcherMonster*CreateArcherMonster()override
	{
		return NewObject<UMy_GoblinArcher>();
	}
};