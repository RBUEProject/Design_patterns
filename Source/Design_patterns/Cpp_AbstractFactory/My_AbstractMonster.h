// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "My_AbstractMonster.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class DESIGN_PATTERNS_API UMy_AbstractMonster : public UObject
{
	GENERATED_BODY()
public:
	virtual void ShowInfo(){check(0&&"You must Override This");}
};

UCLASS(Blueprintable,BlueprintType)
class DESIGN_PATTERNS_API UMy_SoldierMonster : public UMy_AbstractMonster
{
	GENERATED_BODY()
public:
	void ShowInfo()override
	{
		UE_LOG(LogTemp,Warning,TEXT(__FUNCTION__"This is a Soldier"));
	}
};

UCLASS(Blueprintable, BlueprintType)
class DESIGN_PATTERNS_API UMy_ArcherMonster : public UMy_AbstractMonster
{
	GENERATED_BODY()
public:
	void ShowInfo()override
	{
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"This is a Archer"));
	}
};

UCLASS(Blueprintable, BlueprintType)
class DESIGN_PATTERNS_API UMy_KulouSolider : public UMy_SoldierMonster
{
	GENERATED_BODY()
public:
	void ShowInfo()override
	{
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"This is a KuLou Soldier"));
	}
};

UCLASS(Blueprintable, BlueprintType)
class DESIGN_PATTERNS_API UMy_GoblinSolider : public UMy_SoldierMonster
{
	GENERATED_BODY()
public:
	void ShowInfo()override
	{
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"This is a Goblin Soldier"));
	}
};

UCLASS(Blueprintable, BlueprintType)
class DESIGN_PATTERNS_API UMy_KuLouArcher : public UMy_ArcherMonster
{
	GENERATED_BODY()
public:
	void ShowInfo()override
	{
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"This is a KuLou Archer"));
	}
};

UCLASS(Blueprintable, BlueprintType)
class DESIGN_PATTERNS_API UMy_GoblinArcher : public UMy_ArcherMonster
{
	GENERATED_BODY()
public:
	void ShowInfo()override
	{
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"This is a Goblin Archer"));
	}
};