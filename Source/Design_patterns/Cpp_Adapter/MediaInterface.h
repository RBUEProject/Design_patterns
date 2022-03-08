// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MediaInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMediaInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class DESIGN_PATTERNS_API IMediaInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void PlayVideo(const FString& Filepath) = 0;
};
