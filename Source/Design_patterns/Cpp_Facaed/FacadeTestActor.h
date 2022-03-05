// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FacadeObject.h"
#include "FacadeTestActor.generated.h"

UCLASS()
class DESIGN_PATTERNS_API AFacadeTestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFacadeTestActor(){}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override
	{
		facadeObj = NewObject<UFacadeObject>();
		facadeObj->PlayCutscene();
		UE_LOG(LogTemp,Warning,TEXT("__________________________________"));
		facadeObj->StopCutscene();
	}

private:
	UPROPERTY()
	UFacadeObject * facadeObj;

};
