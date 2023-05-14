// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"

// Sets default values
AWeapon::AWeapon()
{
     // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    
    WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("RootComponent"));
    RootComponent = WeaponMesh;
    

}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
    Super::BeginPlay();
    if (EquipSound) {
        EquipAC = PlayWeaponSound(EquipSound);
    }
    
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void AWeapon::OnStartFire(){
    FireAC = PlayWeaponSound(FireLoopSound);
    MuzzleAC = UGameplayStatics::SpawnEmitterAttached(MuzzleFX,RootComponent,TEXT("MuzzleFlashSocket"));
   
}

void AWeapon::OnStopFire(){
    if(FireAC){
        FireAC->Stop();
    }
    if(MuzzleAC){
        MuzzleAC->DeactivateSystem();
    }
    
    PlayWeaponSound(FireFinishSound);
}

UAudioComponent* AWeapon::PlayWeaponSound(USoundCue* Sound)
{
    UAudioComponent* AC = NULL;
    if (Sound)
    {
        AC = UGameplayStatics::SpawnSoundAttached(Sound, RootComponent);
    }
    return AC;
}


void AWeapon::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Hello, World!"));
    if (EquipAC) {
        EquipAC->Stop();
    }
    else if (EquipAC == nullptr){
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("ITS NULLLL!!!!!"));
    }
    
    Super::EndPlay(EndPlayReason);

}