// Fill out your copyright notice in the Description page of Project Settings.


#include "AssaultWeapon.h"

AAssaultWeapon::AAssaultWeapon(){
    fireRate = 0.5f;
    weaponRange = 10000.0f;
    gunDamage = 4.0f;
    
}


void AAssaultWeapon::OnStartFire(){
    Super::OnStartFire();
    //GEngine->AddOnScreenDebugMessage(-1,3.0f,FColor::Blue,FString::Printf(TEXT("SHOOTING")));
    GetWorldTimerManager().SetTimer(timer,this,&AAssaultWeapon::WeaponTrace,fireRate,true,0.0f);
    
}

void AAssaultWeapon::OnStopFire(){
    Super::OnStopFire();
//    GEngine->AddOnScreenDebugMessage(-1,3.0f,FColor::Blue,FString::Printf(TEXT("STOPPED SHOOTING")));
    GetWorldTimerManager().ClearTimer(timer);
}


void AAssaultWeapon::WeaponTrace()
{
    static FName WeaponFireTag = FName(TEXT("WeaponTrace"));
    static FName MuzzleSocket = FName(TEXT("MuzzleFlashSocket"));
    // Start from the muzzle's position
    FVector StartPos = WeaponMesh->GetSocketLocation(MuzzleSocket);
    // Get forward vector of MyPawn
    FVector Forward = MyPawn->GetActorForwardVector();
    // Calculate end position
    FVector EndPos = StartPos + (Forward * weaponRange);/*TODO: Figure out vector math based on the WeaponRange*/
    // Perform line trace to retrieve hit info
    FCollisionQueryParams TraceParams(WeaponFireTag, true, GetInstigator());
    // This fires the ray and checks against all objects w/ collision
    FHitResult Hit(ForceInit);
    GetWorld()->LineTraceSingleByObjectType(Hit, StartPos, EndPos,
                                            FCollisionObjectQueryParams::AllObjects, TraceParams);
    // Did this hit anything?
    if (Hit.bBlockingHit)
    {
        UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),hitEffect,Hit.ImpactPoint,Hit.ImpactNormal.Rotation());
    }
}
