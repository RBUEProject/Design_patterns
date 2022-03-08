// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Weapon.generated.h"

/**
 * 
 */
UCLASS()
class DESIGN_PATTERNS_API UWeapon : public UObject
{
	GENERATED_BODY()
public:
	virtual void UseWeapen(){}
};

UCLASS()
class DESIGN_PATTERNS_API USword : public UWeapon
{
	GENERATED_BODY()
public:
	virtual void UseWeapen()override {
		UE_LOG(LogTemp,Warning,TEXT(__FUNCTION__"Sword is weared"));
	}
};
UCLASS()
class DESIGN_PATTERNS_API ULongbow : public UWeapon
{
	GENERATED_BODY()
public:
	virtual void UseWeapen()override {
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"Longbow is weared"));
	}
};