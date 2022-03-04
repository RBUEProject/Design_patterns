// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Production.generated.h"

/**
 * 
 */
UCLASS(Blueprintable,BlueprintType)
class DESIGN_PATTERNS_API UProduction : public UObject
{
	GENERATED_BODY()
public:
	FString NAME = TEXT("None");
	FString SEX = TEXT("None");
	FString Weapen = TEXT("None");
	void ShowInfo()
	{
		UE_LOG(LogTemp,Warning,TEXT(__FUNCTION__"%s %s %s"),*NAME,*SEX,*Weapen);
	}
};
