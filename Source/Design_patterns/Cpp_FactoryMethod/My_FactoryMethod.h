// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "My_FactoryMethod.generated.h"

//抽象产品类
UCLASS(Abstract)
class DESIGN_PATTERNS_API UMy_FactoryMethod_VirProduction : public UObject
{
	GENERATED_BODY()
public:
	virtual void ShowInfo(){check(0&&"You Must Override this");}
};

UCLASS()
class DESIGN_PATTERNS_API UMy_FactoryMethod_Production_A :public UMy_FactoryMethod_VirProduction
{
	GENERATED_BODY()
public:
	virtual void ShowInfo()override
	{
		UE_LOG(LogTemp,Warning,TEXT(__FUNCTION__"This is Product_A"));
	}
};

UCLASS()
class DESIGN_PATTERNS_API UMy_FactoryMethod_Production_B :public UMy_FactoryMethod_VirProduction
{
	GENERATED_BODY()
public:
	virtual void ShowInfo()override
	{
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"This is Product_B"));
	}
};

UCLASS(Abstract)
class DESIGN_PATTERNS_API UMy_FactoryMethod_VirFActory : public UObject
{
	GENERATED_BODY()
public:
	virtual UMy_FactoryMethod_VirProduction*CreateProduction()
	{
		check(0&&"You Must Override This");
		return nullptr;
	}
};

UCLASS(Blueprintable, BlueprintType)
class DESIGN_PATTERNS_API UMy_FactoryMethod_FActory_A : public UMy_FactoryMethod_VirFActory
{
	GENERATED_BODY()
public:
	virtual UMy_FactoryMethod_VirProduction*CreateProduction()override
	{
		return NewObject<UMy_FactoryMethod_Production_A>();
	}
};

UCLASS(Blueprintable,BlueprintType)
class DESIGN_PATTERNS_API UMy_FactoryMethod_FActory_B : public UMy_FactoryMethod_VirFActory
{
	GENERATED_BODY()
public:
	virtual UMy_FactoryMethod_VirProduction*CreateProduction()override
	{
		return NewObject<UMy_FactoryMethod_Production_B>();
	}
};

UCLASS()
class DESIGN_PATTERNS_API AFactoryMethodTestActor:public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY()
	UMy_FactoryMethod_FActory_A*FactoryA;
	UPROPERTY()
	UMy_FactoryMethod_FActory_B*FactoryB;

	void BeginPlay()override {
		FactoryA = NewObject<UMy_FactoryMethod_FActory_A>();
		UMy_FactoryMethod_VirProduction *ProductA = FactoryA->CreateProduction();
		ProductA->ShowInfo();
		FactoryB = NewObject<UMy_FactoryMethod_FActory_B>();
		UMy_FactoryMethod_VirProduction *ProductB = FactoryB->CreateProduction();
		ProductB->ShowInfo();
	}
};