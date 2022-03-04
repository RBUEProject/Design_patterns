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
	// 用于每次重新调用时，初始化各个参数
	virtual void Init(FVector pInitPos) {
		bIsLiving = true;
		UE_LOG(LogTemp, Warning, TEXT("----------------------------------"));
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__" %s is used. Pos%s"),
			*this->GetName(),
			*UKismetStringLibrary::Conv_VectorToString(pInitPos));

		GetWorld()->GetTimerManager().SetTimer(m_pTimerHandle, this, &AFlyweightObject::End, 1.0f, false);

	}

	// 自定义销毁程序，不是真正的销毁实例
	virtual void End() {
		if (bIsLiving)
		{
			UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__" ******** %s is destroyed."), *this->GetName());
			bIsLiving = false;
			GetWorld()->GetTimerManager().ClearTimer(m_pTimerHandle);
		}
	}

	// 击中
	virtual void Hit() PURE_VIRTUAL(AFlyweightObject::IsValid, );

	// 用于判断是否已经在使用、空闲状态
	bool IsLiving() {
		return bIsLiving;
	}

protected:
	bool bIsLiving;
	FTimerHandle m_pTimerHandle;
};


// 具体享元类 —— 地鼠
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

// 具体享元类 —— 炸弹
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