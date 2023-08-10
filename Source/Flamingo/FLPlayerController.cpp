#include "FLPlayerController.h"
#include "Kismet/KismetMathLibrary.h"
#include "Flamingo.h"

AFLPlayerController::AFLPlayerController()
{
	bShowMouseCursor = true;
}

void AFLPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	APawn* FLPawn = GetPawn();

	if (FLPawn)
	{
		if (bUpdateMovement)
		{
			FHitResult HitResult;
			GetHitResultUnderCursorByChannel(FLConst::TraceTypeQuery_Visibility, true, HitResult);

			FVector Form = FLPawn->GetActorLocation();
			FVector To = HitResult.Location;
			FVector Direction = UKismetMathLibrary::GetDirectionUnitVector(Form, To);

			FLPawn->AddMovementInput(Direction);
		}
	}

	
}
