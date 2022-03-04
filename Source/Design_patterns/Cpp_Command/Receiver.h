// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Receiver.generated.h"

/**
 * 
 */
UCLASS()
class DESIGN_PATTERNS_API UReceiver : public UObject
{
	GENERATED_BODY()
public:
	virtual void Action()
	{
		check(0&&"you must override this");
	}
};

UCLASS()
class DESIGN_PATTERNS_API ULevelPortal : public UReceiver
{
	GENERATED_BODY()
public:
	virtual void Action()
	{
		UE_LOG(LogTemp,Warning,TEXT(__FUNCTION__" travel to next level"));
	}
};

UCLASS()
class DESIGN_PATTERNS_API UCutscene : public UReceiver
{
	GENERATED_BODY()
public:
	virtual void Action()
	{
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__" play animation"));
	}
};