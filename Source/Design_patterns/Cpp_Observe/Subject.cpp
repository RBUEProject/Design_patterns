// Fill out your copyright notice in the Description page of Project Settings.


#include "Subject.h"
#include "Observe.h"
void USubject::BindNotify(UObserve*Observer)
{
	if (!ObserveList.Contains(Observer))
	{
		ObserveList.Add(Observer);
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"%s,is firstly contained"), *Observer->GetName());
		Observer->Update();
	}
}

void USubject::UnbindNotify(UObserve*Observer)
{
	if (ObserveList.Contains(Observer))
	{
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"%s,is unbind"), *Observer->GetName());
		ObserveList.Remove(Observer);
	}
}

void USubject::Notify()
{
	for (auto it = ObserveList.CreateConstIterator(); it; ++it)
	{
		if (IsValid(*it))
			(*it)->Update();
	}
}

void UNuclearRadiation::UpdateRadiationDegree(int32 pLevel)
{
	m_pLevel = pLevel;
	Notify();
}

int32 UNuclearRadiation::GetRadiationDegree()
{
	return m_pLevel;
}

