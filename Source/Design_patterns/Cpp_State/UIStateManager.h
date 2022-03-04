// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UIStateManager.generated.h"

class UBaseStateWidget;
UCLASS()
class DESIGN_PATTERNS_API AUIStateManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUIStateManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable,Category = "State Pattern")
	void EnterState(TSubclassOf<UBaseStateWidget>StateWidgetClass);

	UFUNCTION(BlueprintCallable, Category = "State Pattern")
	void ExitAllStates();

	UPROPERTY(BlueprintReadWrite,Category = "State Pattern")
	UBaseStateWidget* CurrentStateWidget;
private:
	TMap<TSubclassOf<UBaseStateWidget>,UBaseStateWidget*>WidgetInstances;
};
