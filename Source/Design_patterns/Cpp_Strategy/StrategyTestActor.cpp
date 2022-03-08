// Fill out your copyright notice in the Description page of Project Settings.


#include "StrategyTestActor.h"
#include "hero.h"
// Sets default values
AStrategyTestActor::AStrategyTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStrategyTestActor::BeginPlay()
{
	Super::BeginPlay();
	UWarrior*warrior = NewObject<UWarrior>();
	warrior->UseWeapon();
	warrior->ChangeWeapon(NewObject<ULongbow>());
	warrior->UseWeapon();
}

// Called every frame
void AStrategyTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

