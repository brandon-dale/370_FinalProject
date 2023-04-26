// Fill out your copyright notice in the Description page of Project Settings.


#include "Pistol.h"

APistol::APistol(){
    fireRate = 0.5f;
    weaponRange = 10000.0f;
    gunDamage = 4.0f;
    if(MyPawn){
        Character = Cast<AFinalProjectCharacter>(MyPawn);
    }
    
}


void APistol::OnStartFire(){
    Super::OnStartFire();
    GetWorldTimerManager().SetTimer(timer,this,&APistol::WeaponTrace,fireRate,true,0.0f);
    
}

void APistol::OnStopFire(){
    Super::OnStopFire();
    GetWorldTimerManager().ClearTimer(timer);
}


void APistol::WeaponTrace_Implementation()
{

}
