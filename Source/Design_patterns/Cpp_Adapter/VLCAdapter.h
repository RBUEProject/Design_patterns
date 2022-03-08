// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MediaInterface.h"
#include "VLC.h"
#include "VLCAdapter.generated.h"

/**
 * 
 */
UCLASS()
class DESIGN_PATTERNS_API UVLCAdapter : public UObject,public IMediaInterface
{
	GENERATED_BODY()
public:
	UPROPERTY()
	UVLC* m_pVLCSDK;
	UVLCAdapter() {
		m_pVLCSDK = NewObject<UVLC>();
	}
	virtual void PlayVideo(const FString& Filepath)override {
		m_pVLCSDK->OpenFile(Filepath);
	}
};
