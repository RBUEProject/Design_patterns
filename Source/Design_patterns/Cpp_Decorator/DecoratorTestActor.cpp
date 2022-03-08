// Fill out your copyright notice in the Description page of Project Settings.


#include "DecoratorTestActor.h"
#include "Login.h"
#include "WebLoginWithFaceID.h"
// Sets default values


// Called when the game starts or when spawned
void ADecoratorTestActor::BeginPlay()
{
	Super::BeginPlay();
	ULogin*webLogin = NewObject<UWebLogin>();
	//UE_LOG(LogTemp,Warning,TEXT(__FUNCTION__"# old style login"));
	//webLogin->LoginVerify("admin","123456");
	UWebLoginWithFaceID*webLoginWithFaceID = NewObject<UWebLoginWithFaceID>();
	webLoginWithFaceID->Init(webLogin);
	UE_LOG(LogTemp, Warning,TEXT(__FUNCTION__"# new style login") );
	webLoginWithFaceID->LoginVerify("admin","123456");
}


