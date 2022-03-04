// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Builder.h"
#include "Director.generated.h"

/**
 * 
 */
UCLASS()
class DESIGN_PATTERNS_API UDirector : public UBuilder
{
	GENERATED_BODY()
public:
	UProduction*Construct(UBuilder* builder)
	{
		builder->BuilderName();
		builder->BuilderSex();
		builder->BuilderWeapen();
		return builder->getProduction();
	}
};
