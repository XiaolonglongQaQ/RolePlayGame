

#include "Actor/GMagicProjectile.h"

#include "Kismet/GameplayStatics.h"

AGMagicProjectile::AGMagicProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetCollisionProfileName("Projectile");
	RootComponent = SphereComp;

	EffectComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("EffectComp"));
	EffectComp->SetupAttachment(SphereComp);

	MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovementComp"));
	MovementComp->InitialSpeed = 1000.0f;
	MovementComp->bRotationFollowsVelocity = true;
	MovementComp->bInitialVelocityInLocalSpace = true;
	MovementComp->ProjectileGravityScale = 0.f;
}
void AGMagicProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGMagicProjectile::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	SphereComp->OnComponentHit.AddDynamic(this,&AGMagicProjectile::OnActorHit);
}

void AGMagicProjectile::OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),HitWorldParticle,GetActorLocation(),GetActorRotation(),FVector(1.0f,1.0f,1.0f),true,EPSCPoolMethod::None,true);
	Destroy();
}


void AGMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

