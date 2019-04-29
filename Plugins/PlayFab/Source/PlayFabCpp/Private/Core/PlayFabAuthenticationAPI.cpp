//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "Core/PlayFabAuthenticationAPI.h"
#include "Core/PlayFabSettings.h"
#include "Core/PlayFabResultHandler.h"
#include "PlayFab.h"

using namespace PlayFab;
using namespace PlayFab::AuthenticationModels;

UPlayFabAuthenticationAPI::UPlayFabAuthenticationAPI() {}

UPlayFabAuthenticationAPI::~UPlayFabAuthenticationAPI() {}

int UPlayFabAuthenticationAPI::GetPendingCalls() const
{
    return PlayFabRequestHandler::GetPendingCalls();
}

FString UPlayFabAuthenticationAPI::GetBuildIdentifier() const
{
    return PlayFabSettings::buildIdentifier;
}

void UPlayFabAuthenticationAPI::SetTitleId(const FString& titleId)
{
    PlayFabSettings::SetTitleId(titleId);
}

void UPlayFabAuthenticationAPI::SetDevSecretKey(const FString& developerSecretKey)
{
    PlayFabSettings::SetDeveloperSecretKey(developerSecretKey);
}

bool UPlayFabAuthenticationAPI::ActivateKey(
    AuthenticationModels::FActivateAPIKeyRequest& request,
    const FActivateKeyDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if ((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetEntityToken().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && PlayFabSettings::GetEntityToken().Len() == 0)) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::GetUrl(TEXT("/APIKey/ActivateKey")), request.toJSONString(), TEXT("X-EntityToken"), !request.AuthenticationContext.IsValid() ? PlayFabSettings::GetEntityToken() : request.AuthenticationContext->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabAuthenticationAPI::OnActivateKeyResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabAuthenticationAPI::OnActivateKeyResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FActivateKeyDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    AuthenticationModels::FActivateAPIKeyResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabAuthenticationAPI::CreateKey(
    AuthenticationModels::FCreateAPIKeyRequest& request,
    const FCreateKeyDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if ((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetEntityToken().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && PlayFabSettings::GetEntityToken().Len() == 0)) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::GetUrl(TEXT("/APIKey/CreateKey")), request.toJSONString(), TEXT("X-EntityToken"), !request.AuthenticationContext.IsValid() ? PlayFabSettings::GetEntityToken() : request.AuthenticationContext->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabAuthenticationAPI::OnCreateKeyResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabAuthenticationAPI::OnCreateKeyResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FCreateKeyDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    AuthenticationModels::FCreateAPIKeyResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabAuthenticationAPI::DeactivateKey(
    AuthenticationModels::FDeactivateAPIKeyRequest& request,
    const FDeactivateKeyDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if ((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetEntityToken().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && PlayFabSettings::GetEntityToken().Len() == 0)) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::GetUrl(TEXT("/APIKey/DeactivateKey")), request.toJSONString(), TEXT("X-EntityToken"), !request.AuthenticationContext.IsValid() ? PlayFabSettings::GetEntityToken() : request.AuthenticationContext->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabAuthenticationAPI::OnDeactivateKeyResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabAuthenticationAPI::OnDeactivateKeyResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FDeactivateKeyDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    AuthenticationModels::FDeactivateAPIKeyResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabAuthenticationAPI::DeleteKey(
    AuthenticationModels::FDeleteAPIKeyRequest& request,
    const FDeleteKeyDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if ((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetEntityToken().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && PlayFabSettings::GetEntityToken().Len() == 0)) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::GetUrl(TEXT("/APIKey/DeleteKey")), request.toJSONString(), TEXT("X-EntityToken"), !request.AuthenticationContext.IsValid() ? PlayFabSettings::GetEntityToken() : request.AuthenticationContext->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabAuthenticationAPI::OnDeleteKeyResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabAuthenticationAPI::OnDeleteKeyResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FDeleteKeyDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    AuthenticationModels::FDeleteAPIKeyResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabAuthenticationAPI::GetEntityToken(
    AuthenticationModels::FGetEntityTokenRequest& request,
    const FGetEntityTokenDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    FString authKey; FString authValue;
    if (request.AuthenticationContext.IsValid()) {
        if (request.AuthenticationContext->GetEntityToken().Len() > 0) {
            authKey = TEXT("X-EntityToken"); authValue = request.AuthenticationContext->GetEntityToken();
        } else if (request.AuthenticationContext->GetClientSessionTicket().Len() > 0) {
            authKey = TEXT("X-Authorization"); authValue = request.AuthenticationContext->GetClientSessionTicket();
        } else if (request.AuthenticationContext->GetDeveloperSecretKey().Len() > 0) {
            authKey = TEXT("X-SecretKey"); authValue = request.AuthenticationContext->GetDeveloperSecretKey();
        }
    }
    else {
        if (PlayFabSettings::GetEntityToken().Len() > 0) {
            authKey = TEXT("X-EntityToken"); authValue = PlayFabSettings::GetEntityToken();
        } else if (PlayFabSettings::GetClientSessionTicket().Len() > 0) {
            authKey = TEXT("X-Authorization"); authValue = PlayFabSettings::GetClientSessionTicket();
        } else if (PlayFabSettings::GetDeveloperSecretKey().Len() > 0) {
            authKey = TEXT("X-SecretKey"); authValue = PlayFabSettings::GetDeveloperSecretKey();
        }
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::GetUrl(TEXT("/Authentication/GetEntityToken")), request.toJSONString(), authKey, authValue);
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabAuthenticationAPI::OnGetEntityTokenResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabAuthenticationAPI::OnGetEntityTokenResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetEntityTokenDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    AuthenticationModels::FGetEntityTokenResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        if (outResult.EntityToken.Len() > 0)
            PlayFabSettings::SetEntityToken(outResult.EntityToken);
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabAuthenticationAPI::GetKeys(
    AuthenticationModels::FGetAPIKeysRequest& request,
    const FGetKeysDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if ((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetEntityToken().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && PlayFabSettings::GetEntityToken().Len() == 0)) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::GetUrl(TEXT("/APIKey/GetKeys")), request.toJSONString(), TEXT("X-EntityToken"), !request.AuthenticationContext.IsValid() ? PlayFabSettings::GetEntityToken() : request.AuthenticationContext->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabAuthenticationAPI::OnGetKeysResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabAuthenticationAPI::OnGetKeysResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetKeysDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    AuthenticationModels::FGetAPIKeysResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}