// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Weapon.h"
#include "Hero.generated.h"

/**
 * 
 */
UCLASS()
class DESIGN_PATTERNS_API UHero : public UObject
{
	GENERATED_BODY()
public:
	virtual void UseWeapon()
	{
		if (m_pWeapon)
		{
			m_pWeapon->UseWeapen();
		}
	}
	virtual void ChangeWeapon(UWeapon* pWeapon)
	{
		m_pWeapon = pWeapon;
		UE_LOG(LogTemp,Warning,TEXT(__FUNCTION__"weapen is changed"));
	}
protected:
	UPROPERTY()
	UWeapon*m_pWeapon;
};

UCLASS()
class DESIGN_PATTERNS_API UWarrior : public UHero
{
	GENERATED_BODY()
public:
	UWarrior() {
		m_pWeapon = NewObject<USword>();
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"i am a warrior"));
	}
};

UCLASS()
class DESIGN_PATTERNS_API UArcher : public UHero
{
	GENERATED_BODY()
public:
	UArcher() {
		m_pWeapon = NewObject<ULongbow>();
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"i am a Archer"));
	}
};