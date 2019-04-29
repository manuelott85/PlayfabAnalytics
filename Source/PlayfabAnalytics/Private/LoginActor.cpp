#include "LoginActor.h"

#include "Core/PlayFabClientAPI.h"

ALoginActor::ALoginActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ALoginActor::BeginPlay()
{
	Super::BeginPlay();

	clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();
	clientAPI->SetTitleId(TEXT("144"));

	PlayFab::ClientModels::FLoginWithCustomIDRequest request;
	request.CustomId = TEXT("GettingStartedGuide");
	request.CreateAccount = true;

	clientAPI->LoginWithCustomID(request,
		PlayFab::UPlayFabClientAPI::FLoginWithCustomIDDelegate::CreateUObject(this, &ALoginActor::OnSuccess),
		PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ALoginActor::OnError)
	);
}

void ALoginActor::OnSuccess(const PlayFab::ClientModels::FLoginResult& Result) const
{
	UE_LOG(LogTemp, Log, TEXT("Congratulations, you made your first successful API call!"));
}

void ALoginActor::OnError(const PlayFab::FPlayFabCppError& ErrorResult) const
{
	UE_LOG(LogTemp, Error, TEXT("Something went wrong with your first API call.\nHere's some debug information:\n%s"), *ErrorResult.GenerateErrorReport());
}

void ALoginActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}