// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Subject.generated.h"

/**
 * 
 */
 class UObserve;

UCLASS(Abstract)
class DESIGN_PATTERNS_API USubject : public UObject
{
	GENERATED_BODY()
public:
	virtual void BindNotify(UObserve*Observer);


	virtual void UnbindNotify(UObserve*Observer);


	virtual void Notify();

protected:
	TArray<UObserve*> ObserveList;
};

UCLASS(Blueprintable,BlueprintType)
class DESIGN_PATTERNS_API  UNuclearRadiation : public USubject
{
	GENERATED_BODY()
public:
	void UpdateRadiationDegree(int32 pLevel);

	int32 GetRadiationDegree();

private:
	int32 m_pLevel;
};