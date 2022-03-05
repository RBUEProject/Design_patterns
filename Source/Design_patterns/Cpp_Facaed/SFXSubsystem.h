// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SFXSubsystem.generated.h"

/**
 * 
 */
 UCLASS()
class DESIGN_PATTERNS_API USFXSubsystem : public UObject
{
	GENERATED_BODY()
public:
	void Play() {
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"SFX start Moving"));
	}

	void Stop()
	{
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"SFX stop Moving"));
	}
};
