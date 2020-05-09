// Fill out your copyright notice in the Description page of Project Settings.


#include "ChooseNextPatrolPoint.h"
#include "behaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseNextPatrolPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto BlackBoardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackBoardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	
	UE_LOG(LogTemp, Warning, TEXT("Index: %i"), Index)
	
	return EBTNodeResult::Type::Succeeded;
}
