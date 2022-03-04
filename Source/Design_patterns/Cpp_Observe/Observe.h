// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Observe.generated.h"

/**
 * 
 */
 class UNuclearRadiation;

UCLASS(Abstract)
class DESIGN_PATTERNS_API UObserve : public UObject
{
	GENERATED_BODY()
public:
	virtual void Update()PURE_VIRTUAL(UObserve::IsValid);
};


UCLASS(Blueprintable, BlueprintType)
class DESIGN_PATTERNS_API  UWorker: public UObserve
{
	GENERATED_BODY()
public:
	void SetNuclearRadiation(UNuclearRadiation*pNuclearRadiation);

	virtual void Update()override;
	

private:
	UNuclearRadiation * m_pNuclearRadiation;
};


