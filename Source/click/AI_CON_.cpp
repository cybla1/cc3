// Fill out your copyright notice in the Description page of Project Settings.

#include "Math/UnrealMathUtility.h"
#include "AI_CON_.h"

AAI_CON_::AAI_CON_()
{
	SightConfig = CreateOptionalDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	SetPerceptionComponent(*CreateOptionalDefaultSubobject<UAIPerceptionComponent>(TEXT("AI Perception")));


	SightConfig->SightRadius = AISightRadius;
	SightConfig->LoseSightRadius = SightConfig->SightRadius + AILoseSightRadius;
	SightConfig->PeripheralVisionAngleDegrees = AIFieldOfView;
	SightConfig->SetMaxAge(AISightAge);
	//SightConfig->AutoSuccessRangeFromLastSeenLocation = AILastSeenLocation;

	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;

	GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
	GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &AAI_CON_::OnTargetDetected);
	GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &AAI_CON_::OnUpdated);
	GetPerceptionComponent()->ConfigureSense(*SightConfig);

}

void AAI_CON_::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
}

void AAI_CON_::OnTargetDetected(AActor* actor, FAIStimulus const Stimulus)
{
//	UE_LOG(LogTemp, Warning, TEXT("?? %s"), *actor->GetName());

	
	UE_LOG(LogTemp, Warning, TEXT("?? receiver[%f %f %f] , location [%f %f %f]"), Stimulus.ReceiverLocation[0],Stimulus.ReceiverLocation[1],Stimulus.ReceiverLocation[2],Stimulus.StimulusLocation[0],Stimulus.StimulusLocation[1],Stimulus.StimulusLocation[2]);
	float x = Stimulus.ReceiverLocation[0] - Stimulus.StimulusLocation[0];
	float y = Stimulus.ReceiverLocation[1] - Stimulus.StimulusLocation[1];
	float z = Stimulus.ReceiverLocation[2] - Stimulus.StimulusLocation[2];
	float dist = FMath::Sqrt(x * x + y * y + z * z);
	UE_LOG(LogTemp, Warning, TEXT("?? dist %f"), dist);

	if (Stimulus.WasSuccessfullySensed()) {
		UE_LOG(LogTemp, Warning, TEXT("?? %s OKK"), *actor->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("?? %s NONONONO"), *actor->GetName());
	}


}

void AAI_CON_::OnUpdated(TArray<AActor*> const& updated_actors)
{

	UE_LOG(LogTemp, Warning, TEXT("?? %d"), updated_actors.Num());
}