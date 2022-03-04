// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Receiver.h"
#include "Command.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class DESIGN_PATTERNS_API UCommand : public UObject
{
	GENERATED_BODY()
public:
	void SetReceiver(UReceiver*pReceiver)
	{
		m_receiver = pReceiver;
	}

	virtual void Execute()
	{
		if(m_receiver)
			m_receiver->Action();
	}
protected:
	UReceiver*m_receiver;
};

UCLASS()
class DESIGN_PATTERNS_API UPortalCommand : public UCommand
{
	GENERATED_BODY()

};

UCLASS()
class DESIGN_PATTERNS_API UCutsceneCommand : public UCommand
{
	GENERATED_BODY()

};