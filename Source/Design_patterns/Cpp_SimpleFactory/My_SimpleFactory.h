// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "My_SimpleFactory.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class DESIGN_PATTERNS_API UMy_SimpleFactory_Production : public UObject
{
	GENERATED_BODY()
public:
	virtual void ShowInfo();
};

UCLASS()
class DESIGN_PATTERNS_API UProductionA : public UMy_SimpleFactory_Production
{
	GENERATED_BODY()
public:
	virtual void ShowInfo() override;

};

UCLASS()
class DESIGN_PATTERNS_API UProductionB : public UMy_SimpleFactory_Production
{
	GENERATED_BODY()
public:
	virtual void ShowInfo() override;

};

UCLASS()
class DESIGN_PATTERNS_API UMy_SimpleFactory_Factory : public UObject
{
	GENERATED_BODY()
public:
	static UMy_SimpleFactory_Production*CreateNewProduction(UObject*Outer, TSubclassOf<UMy_SimpleFactory_Production>ProductionClass);
};

UCLASS()
class DESIGN_PATTERNS_API ASimpleFactoryTestActor : public AActor
{
	GENERATED_BODY()
public:
	void BeginPlay()override;
};