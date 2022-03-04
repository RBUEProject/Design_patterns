// Fill out your copyright notice in the Description page of Project Settings.


#include "My_Singleton.h"

UMy_Singleton*UMy_Singleton::SingletonObject = nullptr;//¿¡∫∫ Ω

UMy_Singleton*UMy_Singleton::GetSingletonInstance()
{
	if(SingletonObject==nullptr)
	{
		//SingletonObject = NewObject<UMy_Singleton>();
		SingletonObject = Cast<UMy_Singleton>(GEngine->GameSingleton);
	}
	return SingletonObject;
}

void UMy_Singleton::SetValue(int32 NewValue)
{
	intval = NewValue;
}

int32 UMy_Singleton::GetValue()
{
	UE_LOG(LogTemp,Warning,TEXT(__FUNCTION__"Value = %d"),intval);
	return intval;
}