// Fill out your copyright notice in the Description page of Project Settings.


#include "ObserverActor.h"
#include "Observe.h"
#include "Subject.h"
// Sets default values
AObserverActor::AObserverActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AObserverActor::BeginPlay()
{
	Super::BeginPlay();
	UNuclearRadiation*nuclearRadiation = NewObject<UNuclearRadiation>();

	UWorker*worker_0 = NewObject<UWorker>();
	worker_0->SetNuclearRadiation(nuclearRadiation);
	nuclearRadiation->BindNotify(worker_0);

	UWorker*worker_1 = NewObject<UWorker>();
	worker_1->SetNuclearRadiation(nuclearRadiation);
	nuclearRadiation->BindNotify(worker_1);

	UWorker*worker_2 = NewObject<UWorker>();
	worker_2->SetNuclearRadiation(nuclearRadiation);
	nuclearRadiation->BindNotify(worker_2);

	nuclearRadiation->UpdateRadiationDegree(1);
	nuclearRadiation->UpdateRadiationDegree(2);
	nuclearRadiation->UpdateRadiationDegree(3);

	nuclearRadiation->UnbindNotify(worker_0);

	nuclearRadiation->UpdateRadiationDegree(4);
	nuclearRadiation->UpdateRadiationDegree(5);
	nuclearRadiation->UpdateRadiationDegree(6);

	GEngine->ForceGarbageCollection(true);

}

// Called every frame
void AObserverActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

