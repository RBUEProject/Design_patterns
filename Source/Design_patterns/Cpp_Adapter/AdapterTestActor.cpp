// Fill out your copyright notice in the Description page of Project Settings.


#include "AdapterTestActor.h"
#include "MediaInterface.h"
#include "VLCAdapter.h"
#include "ffmpegAdapter.h"
// Sets default values
AAdapterTestActor::AAdapterTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAdapterTestActor::BeginPlay()
{
	Super::BeginPlay();
	IMediaInterface* MediaPlayer = Cast<IMediaInterface>(NewObject<UffmpegAdapter>());
	MediaPlayer->PlayVideo(TEXT("asd.mp4"));
	MediaPlayer = Cast<IMediaInterface>(NewObject<UVLCAdapter>());
	MediaPlayer->PlayVideo(TEXT("saffd.mp4"));
}

// Called every frame
void AAdapterTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

