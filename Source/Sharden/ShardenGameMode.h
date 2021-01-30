#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShardenGameMode.generated.h"

USTRUCT(BlueprintType)
struct SHARDEN_API FSpawnParameters
{
    GENERATED_BODY()

    float Width;
    float Size;
    int32 MinCount;
    int32 MaxCount;
    float MinAngleDelta;
    float MaxAngleDelta;
};

UCLASS()
class SHARDEN_API AShardenGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    void Tick_Impl(float DeltaSeconds);

    UFUNCTION(BlueprintCallable)
    void PlayStart();

    UFUNCTION(BlueprintCallable)
    void PlayEnd();

    UFUNCTION(BlueprintCallable)
    void SpawnObstacle(const FSpawnParameters Parameters);

    UFUNCTION(BlueprintCallable)
    void SetObstaclesSpawnable(bool Spawnable);

    void RegisterPlayerHit();

public:
    UPROPERTY(EditAnywhere)
    TSubclassOf<class AObstacle> ObstacleClass;

private:
    float SpawnTime = 0.0f;
    bool ObstaclesSpawnable = false;
};