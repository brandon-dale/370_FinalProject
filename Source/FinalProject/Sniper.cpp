// Fill out your copyright notice in the Description page of Project Settings.


#include "Sniper.h"

ASniper::ASniper(){
    fireRate = 0.1f;
    weaponRange = 100000.0f;
    gunDamage = 200.0f;
    if(MyPawn){
        Character = Cast<AFinalProjectCharacter>(MyPawn);
    }
    
}


void ASniper::OnStartFire(){
    Super::OnStartFire();
    GetWorldTimerManager().SetTimer(timer,this,&ASniper::WeaponTrace,fireRate,true,0.0f);
    
}

void ASniper::OnStopFire(){
    Super::OnStopFire();
    GetWorldTimerManager().ClearTimer(timer);
}


void ASniper::WeaponTrace_Implementation()
{

}
