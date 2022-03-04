// Fill out your copyright notice in the Description page of Project Settings.


#include "BuilderTestActor.h"
#include "Director.h"
// Sets default values
ABuilderTestActor::ABuilderTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABuilderTestActor::BeginPlay()
{
	Super::BeginPlay();
	UDirector*director = NewObject<UDirector>();
	UProduction* player_A = director->Construct(NewObject<UBuilder_A>());
	player_A->ShowInfo();
	UProduction* player_B = director->Construct(NewObject<UBuilder_B>());
	player_B->ShowInfo();
}

// Called every frame
void ABuilderTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

