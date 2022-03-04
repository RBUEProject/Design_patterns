// Fill out your copyright notice in the Description page of Project Settings.


#include "ACommandActor.h"
#include "Command.h"
// Sets default values
AACommandActor::AACommandActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AACommandActor::BeginPlay()
{
	Super::BeginPlay();
	ULevelPortal*levelportal = NewObject<ULevelPortal>();
	UPortalCommand * portalcommand = NewObject<UPortalCommand>();
	portalcommand->SetReceiver(levelportal);
	portalcommand->Execute();

	UCutscene*cutscene = NewObject<UCutscene>();
	UCutsceneCommand * cutscenecommand = NewObject<UCutsceneCommand>();
	cutscenecommand->SetReceiver(cutscene);
	cutscenecommand->Execute();
}

// Called every frame
void AACommandActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

