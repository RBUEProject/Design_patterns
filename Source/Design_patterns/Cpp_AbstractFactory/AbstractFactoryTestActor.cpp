// Fill out your copyright notice in the Description page of Project Settings.


#include "AbstractFactoryTestActor.h"

// Sets default values
AAbstractFactoryTestActor::AAbstractFactoryTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAbstractFactoryTestActor::BeginPlay()
{
	Super::BeginPlay();
	UMy_KolouMonsterFactory*kuloumonster = NewObject<UMy_KolouMonsterFactory>();
	kuloumonster->CreateSoldierMonster()->ShowInfo();
	kuloumonster->CreateArcherMonster()->ShowInfo();

	UMy_GoblinMonsterFactory*goblinmonster = NewObject<UMy_GoblinMonsterFactory>();
	goblinmonster->CreateSoldierMonster()->ShowInfo();
	goblinmonster->CreateArcherMonster()->ShowInfo();

}

// Called every frame
void AAbstractFactoryTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

