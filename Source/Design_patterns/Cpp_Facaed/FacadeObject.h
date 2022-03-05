// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CameraSubSystem.h"
#include "VFXSubsystem.h"
#include "SFXSubsystem.h"
#include "FacadeObject.generated.h"

/**
 * 
 */
UCLASS()
class DESIGN_PATTERNS_API UFacadeObject : public UObject
{
	GENERATED_BODY()
public:
	UFacadeObject() {
		CameraSub = NewObject<UCameraSubSystem>();
		VFXSub = NewObject<UVFXSubSystem>();
		SFXSub = NewObject<USFXSubsystem>();
	}

	void PlayCutscene() {
		CameraSub->Play();
		VFXSub->Play();
		SFXSub->Play();
	}

	void StopCutscene() {
		CameraSub->Stop();
		VFXSub->Stop();
		SFXSub->Stop();
	}
private:
	UPROPERTY()
	UCameraSubSystem* CameraSub;
	UPROPERTY()
	UVFXSubSystem *VFXSub;
	UPROPERTY()
	USFXSubsystem *SFXSub;
};
