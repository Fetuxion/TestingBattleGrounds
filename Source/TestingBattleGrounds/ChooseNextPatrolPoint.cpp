// Fill out your copyright notice in the Description page of Project Settings.


#include "ChooseNextPatrolPoint.h"

EBTNodeResult::Type UChooseNextPatrolPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UE_LOG(LogTemp, Warning, TEXT("Success"));
	return EBTNodeResult::Type::Succeeded;
}
