// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Login.h"
#include "WebLoginWithFaceID.generated.h"

/**
 * 
 */
UCLASS()
class DESIGN_PATTERNS_API UWebLoginWithFaceID :public ULogin
{
	GENERATED_BODY()
public:
	void Init(ULogin* pLoginObj)
	{
		m_pLoginObj = pLoginObj;
	}

	bool faceIDVerify(const FString& pName)
	{
		UE_LOG(LogTemp,Warning,TEXT(__FUNCTION__"%s Face ID Verify"),*pName);
		return true;
	}

	virtual bool LoginVerify(const FString& pName, const FString& pPassword)override
	{
		bool result;
		result = m_pLoginObj->LoginVerify(pName,pPassword);
		result = result && faceIDVerify(pName);
		return result;
	}
private:
	UPROPERTY()
	ULogin*m_pLoginObj;
};
