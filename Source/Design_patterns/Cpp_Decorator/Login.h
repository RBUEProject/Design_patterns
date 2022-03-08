// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Login.generated.h"

/**
 * 
 */
UCLASS()
class DESIGN_PATTERNS_API ULogin : public UObject
{
	GENERATED_BODY()
public:
	virtual bool LoginVerify(const FString& pName, const FString& pPassword)
	{
		return true;
	}
};

UCLASS()
class DESIGN_PATTERNS_API UWebLogin :public ULogin
{
	GENERATED_BODY()
public:
	virtual bool LoginVerify(const FString& pName, const FString& pPassword)override {
		bool result;
		UE_LOG(LogTemp,Warning,TEXT(__FUNCTION__"LinkWeb:Account ID Verify"));
		result = true;
		return result;
	}
};
