// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "My_Singleton.generated.h"

/**
 * 
 */
UCLASS(BlueprintType,Blueprintable)
class DESIGN_PATTERNS_API UMy_Singleton : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	static UMy_Singleton*GetSingletonInstance();

	UFUNCTION(BlueprintCallable)
	void SetValue(int32 NewValue);

	UFUNCTION(BlueprintCallable)
	int32 GetValue();

private:
	static UMy_Singleton*SingletonObject;
	int32 intval;
};
