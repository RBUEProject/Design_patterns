// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MonsterPrototype.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class DESIGN_PATTERNS_API UMonsterPrototype : public UObject
{
	GENERATED_BODY()
public:
	virtual UMonsterPrototype * Clone()
	{
		UE_LOG(LogTemp,Error,TEXT("please implement this"));
		return nullptr;
	}
	virtual void ShowInfo()
	{
		UE_LOG(LogTemp,Warning,TEXT(__FUNCTION__"%s [Health]%d,[Speed]%d"), *this->GetName(), m_Health, m_Speed);
	}
protected:
	int32 m_Health = 100;
	int32 m_Speed = 30;
};

UCLASS(Blueprintable,BlueprintType)
class DESIGN_PATTERNS_API UGhost : public UMonsterPrototype
{
	GENERATED_BODY()
public:
	virtual UMonsterPrototype * Clone()override
	{
		UGhost*CloneIns = NewObject<UGhost>();
		CloneIns->m_Health = m_Health;
		CloneIns->m_Speed = m_Speed;
		return CloneIns;
	}
};

UCLASS(Blueprintable, BlueprintType)
class DESIGN_PATTERNS_API UDevil : public UMonsterPrototype
{
	GENERATED_BODY()
public:
	UDevil()
	{
		m_Speed = 20;
		m_Health = 200;
	}

	virtual UMonsterPrototype * Clone()override
	{
		UDevil*CloneIns = NewObject<UDevil>();
		CloneIns->m_Health = m_Health;
		CloneIns->m_Speed = m_Speed;
		return CloneIns;
	}

	virtual void ShowInfo()override
	{
		UE_LOG(LogTemp,Warning,TEXT(__FUNCTION__"%s [Health]%d,[Speed]%d,[Attack]%d"),*this->GetName(),m_Health,m_Speed,m_Attack);
	}
private:
	int32 m_Attack = 20;
};

