// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseStateWidget.h"

void UBaseStateWidget::EnterState()
{
	OnEnterState();
}

void UBaseStateWidget::ExitState()
{
	OnExitState();
}

void UBaseStateWidget::OnEnterState_Implementation()
{
	AddToViewport();
}

void UBaseStateWidget::OnExitState_Implementation()
{
	RemoveFromParent();
}
