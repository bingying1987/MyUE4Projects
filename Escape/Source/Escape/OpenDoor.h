// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenDoorRequest);//����ί��,����OC.

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	UPROPERTY(BlueprintAssignable)
	FOnOpenDoorRequest Openquest;
	UPROPERTY(BlueprintAssignable)
	FOnOpenDoorRequest Closequest;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
private:
	void OpenDoor();
	void CloseDoor();
private:
	UPROPERTY(EditAnyWhere)
		float OpenAngle = 0.0f;
	UPROPERTY(EditAnyWhere)
		ATriggerVolume *PressurePlate;
	UPROPERTY(EditAnyWhere)
		float DoorCloseDelay = 1.0f;
	
	float LastDoorOpenTime;
	float GetTotalMassOfActorsInPlate();
};
