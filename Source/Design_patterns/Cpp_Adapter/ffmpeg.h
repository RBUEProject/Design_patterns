// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ffmpeg.generated.h"

/**
 * 
 */
UCLASS()
class DESIGN_PATTERNS_API Uffmpeg : public UObject
{
	GENERATED_BODY()
public:
	virtual void OpenFile(const FString& Filepath)
	{
		UE_LOG(LogTemp,Warning,TEXT(__FUNCTION__"use ffmpeg sdk to play media"));
	}
};
