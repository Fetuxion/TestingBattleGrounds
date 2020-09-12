// Fill out your copyright notice in the Description page of Project Settings.


#include "ChooseNextPatrolPoint.h"
#include "AIController.h"
#include "PatrolRoute.h"
#include "PatrolRoute.h"
#include "behaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseNextPatrolPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Get the patrol Route
	auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();
	//Protect against no patrol route component
	if (!ensure(PatrolRoute)) { return EBTNodeResult::Type::Failed; }
	auto PatrolPoints = PatrolRoute->GetPatrolPoints();
	//Warn against empty patrol Points
	if (PatrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("A Guard is missing patrol points"))
	}
	//Set Next Waypoint
	auto BlackBoardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackBoardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackBoardComp->SetValueAsObject(NextPatrolPointKey.SelectedKeyName, PatrolPoints[Index]);
	
	//Cycle the Index
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackBoardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
	//Try to understand this!!!
	BlackBoardComp->SetValueAsObject(NextPatrolPointKey.SelectedKeyName, PatrolPoints[NextIndex]);
	return EBTNodeResult::Type::Succeeded;
}
