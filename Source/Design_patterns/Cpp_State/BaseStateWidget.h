// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StateInterface.h"
#include "BaseStateWidget.generated.h"

/**
 * 
 */


UCLASS()
class DESIGN_PATTERNS_API UBaseStateWidget : public UUserWidget,public IStateInterface
{
	GENERATED_BODY()
public:
	virtual void EnterState()override;
	virtual void ExitState()override;

	UFUNCTION(BlueprintNativeEvent,BlueprintCallable,Category = "State Pattern")
	void OnEnterState();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "State Pattern")
	void OnExitState();
};
