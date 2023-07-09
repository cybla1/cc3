// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionComponent.h"
#include "AI_CON_.generated.h"

/**
 * 
 */
UCLASS()
class CLICK_API AAI_CON_ : public AAIController
{
	GENERATED_BODY()


public:
	AAI_CON_();
	virtual void OnPossess(APawn* InPawn) override;


	class UAISenseConfig_Sight* SightConfig;
public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AISightRadius = 500.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AILoseSightRadius = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AIFieldOfView = 90.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AISightAge = 5.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AILastSeenLocation = 900.f;

	UFUNCTION()
		void OnTargetDetected(AActor* actor, FAIStimulus const Stimulus);
	UFUNCTION()
		void OnUpdated(TArray<AActor*> const& updated_actors);
};
