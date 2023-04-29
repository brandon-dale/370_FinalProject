// Fill out your copyright notice in the Description page of Project Settings.


#include "Chiansaw.h"

AChiansaw::AChiansaw(){
    fireRate = 100.0f;
    weaponRange = 100.0f;
    gunDamage = 20.0f;
    if(MyPawn){
        Character = Cast<AFinalProjectCharacter>(MyPawn);
    }
    
}


void AChiansaw::OnStartFire(){
    Super::OnStartFire();
    GetWorldTimerManager().SetTimer(timer,this,&AChiansaw::WeaponTrace,fireRate,true,0.0f);
    
}

void AChiansaw::OnStopFire(){
    Super::OnStopFire();
    GetWorldTimerManager().ClearTimer(timer);
}


void AChiansaw::WeaponTrace_Implementation()
{

}
