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
	clientAPI->SetTitleId(TEXT("D2F08"));

	PlayFab::ClientModels::FLoginWithCustomIDRequest request_LoginWithCustomID;
	request_LoginWithCustomID.CustomId = TEXT("GettingStartedGuide");
	request_LoginWithCustomID.CreateAccount = true;

	clientAPI->LoginWithCustomID(request_LoginWithCustomID,
		PlayFab::UPlayFabClientAPI::FLoginWithCustomIDDelegate::CreateUObject(this, &ALoginActor::OnSuccess),
		PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ALoginActor::OnError)
	);
}

void ALoginActor::OnSuccess(const PlayFab::ClientModels::FLoginResult& Result) const
{
	UE_LOG(LogTemp, Log, TEXT("Congratulations, you made your first successful API call!"));
	PlayFab::ClientModels::FGetTitleDataRequest request_GetTitleData;
	clientAPI->GetTitleData(request_GetTitleData,
		PlayFab::UPlayFabClientAPI::FGetTitleDataDelegate::CreateUObject(this, &ALoginActor::ShowTitelData)
		);
}

void ALoginActor::OnError(const PlayFab::FPlayFabCppError& ErrorResult) const
{
	UE_LOG(LogTemp, Error, TEXT("Something went wrong with your first API call.\nHere's some debug information:\n%s"), *ErrorResult.GenerateErrorReport());
}

void ALoginActor::ShowTitelData(const PlayFab::ClientModels::FGetTitleDataResult& Result) const
{
	int numberOfData = Result.Data.Num();
	UE_LOG(LogTemp, Log, TEXT("Number of Data gatherd: %d"), numberOfData);
}

void ALoginActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}