// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MediaInterface.h"
#include "ffmpeg.h"
#include "ffmpegAdapter.generated.h"

/**
 * 
 */
UCLASS()
class DESIGN_PATTERNS_API UffmpegAdapter : public UObject , public IMediaInterface
{
	GENERATED_BODY()
public:
	UPROPERTY()
	Uffmpeg* m_pffmpegSDK;

	UffmpegAdapter(){
		m_pffmpegSDK = NewObject<Uffmpeg>();
	}
	virtual void PlayVideo(const FString& Filepath)override {
		m_pffmpegSDK->OpenFile(Filepath);
	}
};
