// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SkeletalMeshComponent.h"
#include "UObject/Object.h"
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"

#include "Particles/ParticleSystemComponent.h"
#include "Weapon.generated.h"

UCLASS()
class FINALPROJECT_API AWeapon : public AActor
{
    GENERATED_BODY()
    
public:
    // Sets default values for this actor's properties
    AWeapon();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    UPROPERTY(Transient)
    UAudioComponent* FireAC;
    UAudioComponent* PlayWeaponSound(USoundCue* Sound);
    
    UPROPERTY(Transient)
    UParticleSystemComponent* MuzzleAC;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
    
    virtual void OnStartFire();
    virtual void OnStopFire();
    
    
    UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly,Category = "Weapon")
    USkeletalMeshComponent* WeaponMesh;
    
    
    UPROPERTY(EditDefaultsOnly, Category = "Sound")
    USoundCue* FireLoopSound;

    UPROPERTY(EditDefaultsOnly, Category = "Sound")
    USoundCue* FireFinishSound;

    UPROPERTY(EditDefaultsOnly, Category = "Sound")
    USoundCue* EquipSound;

    UPROPERTY(EditDefaultsOnly, Category = "Sound")
    USoundCue* HitSound;
    
    UPROPERTY(EditDefaultsOnly,Category = "Effects")
    UParticleSystem* MuzzleFX;
    UPROPERTY(BlueprintReadWrite)
    APawn* MyPawn;
    //AFinalProjectCharacter* myChar;
    
    
    


};
