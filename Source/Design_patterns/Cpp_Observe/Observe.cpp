// Fill out your copyright notice in the Description page of Project Settings.


#include "Observe.h"
#include "Subject.h"
void UWorker::SetNuclearRadiation(UNuclearRadiation*pNuclearRadiation)
{
	m_pNuclearRadiation = pNuclearRadiation;
}

void UWorker::Update()
{
	if (m_pNuclearRadiation)
	{
		int32 CurrentLevel = m_pNuclearRadiation->GetRadiationDegree();
		if (CurrentLevel < 1) {
			UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"%s <1"), *this->GetName());

		}
		else if (CurrentLevel < 2) {
			UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"%s <2"), *this->GetName());

		}
		else if (CurrentLevel < 3) {
			UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"%s <3"), *this->GetName());

		}
		else if (CurrentLevel < 4) {
			UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"%s <4"), *this->GetName());

		}
		else if (CurrentLevel < 5) {
			UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"%s <5"), *this->GetName());

		}
		else {
			UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"%s >5"), *this->GetName());
			this->ConditionalBeginDestroy();
		}

	}
}

