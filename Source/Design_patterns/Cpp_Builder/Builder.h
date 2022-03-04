// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Production.h"
#include "Builder.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class DESIGN_PATTERNS_API UBuilder : public UObject
{
	GENERATED_BODY()
public:
	UBuilder(){Player = NewObject<UProduction>();}
	virtual void BuilderName(){}
	virtual void BuilderSex(){}
	virtual void BuilderWeapen(){}
	UProduction* getProduction(){return Player;}
protected:
	UProduction*Player;
};

UCLASS(BlueprintType,Blueprintable)
class DESIGN_PATTERNS_API UBuilder_A : public UBuilder
{
	GENERATED_BODY()
public:
	virtual void BuilderName()override {Player->NAME = TEXT("playerA");}
	virtual void BuilderSex()override {Player->SEX = TEXT("boy");}
	virtual void BuilderWeapen()override {Player->Weapen = TEXT("gun");}
};

UCLASS(BlueprintType, Blueprintable)
class DESIGN_PATTERNS_API UBuilder_B : public UBuilder
{
	GENERATED_BODY()
public:
	virtual void BuilderName()override { Player->NAME = TEXT("СplayerB"); }
	virtual void BuilderSex()override { Player->SEX = TEXT("girl"); }
	virtual void BuilderWeapen()override { Player->Weapen = TEXT("tooth"); }
};