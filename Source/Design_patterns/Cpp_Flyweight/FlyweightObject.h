// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetStringLibrary.h"
#include "FlyweightObject.generated.h"

UCLASS(Abstract)
class DESIGN_PATTERNS_API AFlyweightObject : public AActor
{
	GENERATED_BODY()
public:
	// ����ÿ�����µ���ʱ����ʼ����������
	virtual void Init(FVector pInitPos) {
		bIsLiving = true;
		UE_LOG(LogTemp, Warning, TEXT("----------------------------------"));
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__" %s is used. Pos%s"),
			*this->GetName(),
			*UKismetStringLibrary::Conv_VectorToString(pInitPos));

		GetWorld()->GetTimerManager().SetTimer(m_pTimerHandle, this, &AFlyweightObject::End, 1.0f, false);

	}

	// �Զ������ٳ��򣬲�������������ʵ��
	virtual void End() {
		if (bIsLiving)
		{
			UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__" ******** %s is destroyed."), *this->GetName());
			bIsLiving = false;
			GetWorld()->GetTimerManager().ClearTimer(m_pTimerHandle);
		}
	}

	// ����
	virtual void Hit() PURE_VIRTUAL(AFlyweightObject::IsValid, );

	// �����ж��Ƿ��Ѿ���ʹ�á�����״̬
	bool IsLiving() {
		return bIsLiving;
	}

protected:
	bool bIsLiving;
	FTimerHandle m_pTimerHandle;
};


// ������Ԫ�� ���� ����
UCLASS()
class DESIGN_PATTERNS_API AMole : public AFlyweightObject
{
	GENERATED_BODY()
public:

	virtual void Hit() {
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__" %s is hit. Add 10 score"), *this->GetName());
		End();
	}

};

// ������Ԫ�� ���� ը��
UCLASS()
class DESIGN_PATTERNS_API ABomb : public AFlyweightObject
{
	GENERATED_BODY()
public:
	virtual void Hit() {
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__" %s is hit. Add -5 score"), *this->GetName());
		End();
	}
};