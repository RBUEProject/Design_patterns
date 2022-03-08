// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VLC.generated.h"

/**
 * 
 */
UCLASS()
class DESIGN_PATTERNS_API UVLC : public UObject
{
	GENERATED_BODY()
public:
	virtual void OpenFile(const FString& Filepath)
	{
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"use VLC sdk to play media"));
	}
};
