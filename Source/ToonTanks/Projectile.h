// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Bullet Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Bullet Components", meta = (AllowPrivateAccess = "true"))
	class UProjectileMovementComponent* ProjectileMovement;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bullet Components", meta = (AllowPrivateAccess = "true"))
	float InitialSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bullet Components", meta = (AllowPrivateAccess = "true"))
	float MaxSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bullet Components", meta = (AllowPrivateAccess = "true"))
	float Damage = 50.f;
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp,AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bullet Components", meta = (AllowPrivateAccess = "true"))
	class UParticleSystem* HitParticles;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bullet Components", meta = (AllowPrivateAccess = "true"))
	class UParticleSystemComponent* TrailParticles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bullet Components", meta = (AllowPrivateAccess = "true"))
	class USoundBase* LaunchSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bullet Components", meta = (AllowPrivateAccess = "true"))
	 USoundBase* HitSound;

	 UPROPERTY(EditAnywhere, Category = "Bullet Components")
	 TSubclassOf<class UCameraShakeBase> HitCameraShakeClass;
};
