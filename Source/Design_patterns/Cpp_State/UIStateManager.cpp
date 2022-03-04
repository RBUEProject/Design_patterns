// Fill out your copyright notice in the Description page of Project Settings.


#include "UIStateManager.h"
#include "BaseStateWidget.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
AUIStateManager::AUIStateManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUIStateManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUIStateManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AUIStateManager::EnterState(TSubclassOf<UBaseStateWidget>StateWidgetClass)
{
	if (CurrentStateWidget != nullptr)
	{
		CurrentStateWidget->ExitState();
	}
	if (WidgetInstances.Contains(StateWidgetClass))
	{
		CurrentStateWidget = WidgetInstances.FindRef(StateWidgetClass);
	}
	else
	{
		APlayerController*PC = UGameplayStatics::GetPlayerController(GetWorld(),0);
		CurrentStateWidget = CreateWidget<UBaseStateWidget>(PC,StateWidgetClass);
		WidgetInstances.Add(StateWidgetClass,CurrentStateWidget);
	}
	CurrentStateWidget->EnterState();
}

void AUIStateManager::ExitAllStates()
{
	for (auto& Elem : WidgetInstances)
	{
		(Elem.Value)->ExitState();
	}
}

