// Fill out your copyright notice in the Description page of Project Settings.


#include "My_SimpleFactory.h"


void UMy_SimpleFactory_Production::ShowInfo()
{
	check(0 && "You Must Override This");
}

void UProductionA::ShowInfo()
{
	UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"this is production A"));
}

void UProductionB::ShowInfo()
{
	UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"this is production B"));
}

UMy_SimpleFactory_Production* UMy_SimpleFactory_Factory::CreateNewProduction(UObject*Outer, TSubclassOf<UMy_SimpleFactory_Production>ProductionClass)
{
	return NewObject<UMy_SimpleFactory_Production>(Outer, ProductionClass);
}


void ASimpleFactoryTestActor::BeginPlay()
{
	UMy_SimpleFactory_Production*Production_A = UMy_SimpleFactory_Factory::CreateNewProduction(this, UProductionA::StaticClass());
	Production_A->ShowInfo();
	UMy_SimpleFactory_Production*Production_B = UMy_SimpleFactory_Factory::CreateNewProduction(this, UProductionB::StaticClass());
	Production_B->ShowInfo();
}
