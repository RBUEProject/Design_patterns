// Fill out your copyright notice in the Description page of Project Settings.
#include "PrototypeActor.h"
#include "MonsterSpawner.h"


// Sets default values
APrototypeActor::APrototypeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APrototypeActor::BeginPlay()
{
	Super::BeginPlay();
	UMonsterSpawner * monster = NewObject<UMonsterSpawner>();
	UGhost * ghost = NewObject<UGhost>();
	UGhost* ghost_cpy = Cast<UGhost>(monster->SpawnMonster(ghost));
	UDevil* devil = NewObject<UDevil>();
	UDevil * devil_cpy = Cast<UDevil>(monster->SpawnMonster(devil));
	ghost->ShowInfo();
	ghost_cpy->ShowInfo();
	devil->ShowInfo();
	devil_cpy->ShowInfo();
}

// Called every frame
void APrototypeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

