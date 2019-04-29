//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the UE4 PlayFab plugin.
//
// API: Authentication
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabAuthenticationAPI.h"
#include "PlayFabAuthenticationModels.h"
#include "PlayFabAuthenticationModelDecoder.h"
#include "PlayFabPrivate.h"
#include "PlayFabEnums.h"
#include "PlayFabCommon/Public/PlayFabAuthenticationContext.h"

UPlayFabAuthenticationAPI::UPlayFabAuthenticationAPI(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , CallAuthenticationContext(nullptr)
{
}

void UPlayFabAuthenticationAPI::SetCallAuthenticationContext(UPlayFabAuthenticationContext* InAuthenticationContext)
{
    CallAuthenticationContext = InAuthenticationContext;
}

void UPlayFabAuthenticationAPI::SetRequestObject(UPlayFabJsonObject* JsonObject)
{
    RequestJsonObj = JsonObject;
}

UPlayFabJsonObject* UPlayFabAuthenticationAPI::GetResponseObject()
{
    return ResponseJsonObj;
}

FString UPlayFabAuthenticationAPI::PercentEncode(const FString& Text)
{
    FString OutText = Text;

    OutText = OutText.Replace(TEXT("!"), TEXT("%21"));
    OutText = OutText.Replace(TEXT("\""), TEXT("%22"));
    OutText = OutText.Replace(TEXT("#"), TEXT("%23"));
    OutText = OutText.Replace(TEXT("$"), TEXT("%24"));
    //OutText = OutText.Replace(TEXT("&"), TEXT("%26"));
    OutText = OutText.Replace(TEXT("'"), TEXT("%27"));
    OutText = OutText.Replace(TEXT("("), TEXT("%28"));
    OutText = OutText.Replace(TEXT(")"), TEXT("%29"));
    OutText = OutText.Replace(TEXT("*"), TEXT("%2A"));
    OutText = OutText.Replace(TEXT("+"), TEXT("%2B"));
    OutText = OutText.Replace(TEXT(","), TEXT("%2C"));
    //OutText = OutText.Replace(TEXT("/"), TEXT("%2F"));
    OutText = OutText.Replace(TEXT(":"), TEXT("%3A"));
    OutText = OutText.Replace(TEXT(";"), TEXT("%3B"));
    OutText = OutText.Replace(TEXT("="), TEXT("%3D"));
    //OutText = OutText.Replace(TEXT("?"), TEXT("%3F"));
    OutText = OutText.Replace(TEXT("@"), TEXT("%40"));
    OutText = OutText.Replace(TEXT("["), TEXT("%5B"));
    OutText = OutText.Replace(TEXT("]"), TEXT("%5D"));
    OutText = OutText.Replace(TEXT("{"), TEXT("%7B"));
    OutText = OutText.Replace(TEXT("}"), TEXT("%7D"));

    return OutText;
}

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Authentication API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// API Keys
//////////////////////////////////////////////////////
/** Activates the given API key. Active keys may be used for authentication. */
UPlayFabAuthenticationAPI* UPlayFabAuthenticationAPI::ActivateKey(FAuthenticationActivateAPIKeyRequest request,
    FDelegateOnSuccessActivateKey onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAuthenticationAPI* manager = NewObject<UPlayFabAuthenticationAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessActivateKey = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAuthenticationAPI::HelperActivateKey);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/APIKey/ActivateKey";
    manager->useEntityToken = true;

    // Serialize all the request properties to json
    if (request.APIKeyId.IsEmpty() || request.APIKeyId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("APIKeyId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("APIKeyId"), request.APIKeyId);
    }
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAuthenticationRequestCompleted
void UPlayFabAuthenticationAPI::HelperActivateKey(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessActivateKey.IsBound())
    {
        FAuthenticationActivateAPIKeyResponse ResultStruct = UPlayFabAuthenticationModelDecoder::decodeActivateAPIKeyResponseResponse(response.responseData);
        OnSuccessActivateKey.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Creates an API key for the given entity. */
UPlayFabAuthenticationAPI* UPlayFabAuthenticationAPI::CreateKey(FAuthenticationCreateAPIKeyRequest request,
    FDelegateOnSuccessCreateKey onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAuthenticationAPI* manager = NewObject<UPlayFabAuthenticationAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateKey = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAuthenticationAPI::HelperCreateKey);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/APIKey/CreateKey";
    manager->useEntityToken = true;

    // Serialize all the request properties to json
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAuthenticationRequestCompleted
void UPlayFabAuthenticationAPI::HelperCreateKey(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessCreateKey.IsBound())
    {
        FAuthenticationCreateAPIKeyResponse ResultStruct = UPlayFabAuthenticationModelDecoder::decodeCreateAPIKeyResponseResponse(response.responseData);
        OnSuccessCreateKey.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Deactivates the given API key, causing subsequent authentication attempts with it to fail.Deactivating a key is a way to verify that the key is not in use before deleting it. */
UPlayFabAuthenticationAPI* UPlayFabAuthenticationAPI::DeactivateKey(FAuthenticationDeactivateAPIKeyRequest request,
    FDelegateOnSuccessDeactivateKey onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAuthenticationAPI* manager = NewObject<UPlayFabAuthenticationAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeactivateKey = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAuthenticationAPI::HelperDeactivateKey);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/APIKey/DeactivateKey";
    manager->useEntityToken = true;

    // Serialize all the request properties to json
    if (request.APIKeyId.IsEmpty() || request.APIKeyId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("APIKeyId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("APIKeyId"), request.APIKeyId);
    }
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAuthenticationRequestCompleted
void UPlayFabAuthenticationAPI::HelperDeactivateKey(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeactivateKey.IsBound())
    {
        FAuthenticationDeactivateAPIKeyResponse ResultStruct = UPlayFabAuthenticationModelDecoder::decodeDeactivateAPIKeyResponseResponse(response.responseData);
        OnSuccessDeactivateKey.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Deletes the given API key. */
UPlayFabAuthenticationAPI* UPlayFabAuthenticationAPI::DeleteKey(FAuthenticationDeleteAPIKeyRequest request,
    FDelegateOnSuccessDeleteKey onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAuthenticationAPI* manager = NewObject<UPlayFabAuthenticationAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteKey = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAuthenticationAPI::HelperDeleteKey);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/APIKey/DeleteKey";
    manager->useEntityToken = true;

    // Serialize all the request properties to json
    if (request.APIKeyId.IsEmpty() || request.APIKeyId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("APIKeyId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("APIKeyId"), request.APIKeyId);
    }
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAuthenticationRequestCompleted
void UPlayFabAuthenticationAPI::HelperDeleteKey(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteKey.IsBound())
    {
        FAuthenticationDeleteAPIKeyResponse ResultStruct = UPlayFabAuthenticationModelDecoder::decodeDeleteAPIKeyResponseResponse(response.responseData);
        OnSuccessDeleteKey.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets the API keys associated with the given entity. */
UPlayFabAuthenticationAPI* UPlayFabAuthenticationAPI::GetKeys(FAuthenticationGetAPIKeysRequest request,
    FDelegateOnSuccessGetKeys onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAuthenticationAPI* manager = NewObject<UPlayFabAuthenticationAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetKeys = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAuthenticationAPI::HelperGetKeys);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/APIKey/GetKeys";
    manager->useEntityToken = true;

    // Serialize all the request properties to json
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAuthenticationRequestCompleted
void UPlayFabAuthenticationAPI::HelperGetKeys(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetKeys.IsBound())
    {
        FAuthenticationGetAPIKeysResponse ResultStruct = UPlayFabAuthenticationModelDecoder::decodeGetAPIKeysResponseResponse(response.responseData);
        OnSuccessGetKeys.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}


///////////////////////////////////////////////////////
// Authentication
//////////////////////////////////////////////////////
/** Method to exchange a legacy AuthenticationTicket or title SecretKey for an Entity Token or to refresh a still valid Entity Token. */
UPlayFabAuthenticationAPI* UPlayFabAuthenticationAPI::GetEntityToken(FAuthenticationGetEntityTokenRequest request,
    FDelegateOnSuccessGetEntityToken onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAuthenticationAPI* manager = NewObject<UPlayFabAuthenticationAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetEntityToken = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAuthenticationAPI::HelperGetEntityToken);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Authentication/GetEntityToken";
    manager->useEntityToken = true;
    manager->useSecretKey = true;
    manager->useSessionTicket = true;
    manager->returnsEntityToken = true;

    // Serialize all the request properties to json
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAuthenticationRequestCompleted
void UPlayFabAuthenticationAPI::HelperGetEntityToken(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetEntityToken.IsBound())
    {
        FAuthenticationGetEntityTokenResponse ResultStruct = UPlayFabAuthenticationModelDecoder::decodeGetEntityTokenResponseResponse(response.responseData);
        OnSuccessGetEntityToken.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}



void UPlayFabAuthenticationAPI::OnProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
    // Be sure that we have no data from previous response
    ResetResponseData();

    if (!IsValidLowLevel())
    {
        UE_LOG(LogPlayFab, Error, TEXT("The request object is invalid during OnProcessRequestComplete."));
        return;
    }
    if (!OnPlayFabResponse.IsBound())
    {
        UE_LOG(LogPlayFab, Error, TEXT("OnPlayFabResponse has come un-bound during OnProcessRequestComplete."));
        return;
    }

    FPlayFabBaseModel myResponse;

    // Check we have result to process further
    if (!bWasSuccessful)
    {
        UE_LOG(LogPlayFab, Error, TEXT("Request failed: %s"), *Request->GetURL());

        // Broadcast the result event
        myResponse.responseError.hasError = true;
        myResponse.responseError.ErrorCode = 503;
        myResponse.responseError.ErrorName = "Unable to contact server";
        myResponse.responseError.ErrorMessage = "Unable to contact server";

        OnPlayFabResponse.Broadcast(myResponse, mCustomData, false);

        return;
    }

    // Save response data as a string
    ResponseContent = Response->GetContentAsString();

    // Save response code as int32
    ResponseCode = Response->GetResponseCode();

    // Try to deserialize data to JSON
    TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(ResponseContent);
    FJsonSerializer::Deserialize(JsonReader, ResponseJsonObj->GetRootObject());

    // Decide whether the request was successful
    bIsValidJsonResponse = bWasSuccessful && ResponseJsonObj->GetRootObject().IsValid();

    // Log errors
    if (!bIsValidJsonResponse)
        UE_LOG(LogPlayFab, Warning, TEXT("JSON could not be decoded!"));

    // Log response state
    UE_LOG(LogPlayFab, Log, TEXT("Response : %s"), *ResponseContent);

    myResponse.responseError.decodeError(ResponseJsonObj);
    myResponse.responseData = ResponseJsonObj;
    IPlayFab* pfSettings = &(IPlayFab::Get());

    if (returnsEntityToken)
    {
        CallAuthenticationContext = NewObject<UPlayFabAuthenticationContext>();
        FString NewEntityToken = myResponse.responseData->GetObjectField("data")->GetStringField("EntityToken");
        pfSettings->setEntityToken(NewEntityToken);
        CallAuthenticationContext->SetEntityToken(MoveTemp(NewEntityToken));
    }

    // Broadcast the result event
    OnPlayFabResponse.Broadcast(myResponse, mCustomData, !myResponse.responseError.hasError);
    pfSettings->ModifyPendingCallCount(-1);
}

void UPlayFabAuthenticationAPI::Activate()
{
    IPlayFab* pfSettings = &(IPlayFab::Get());

    FString RequestUrl;
    RequestUrl = pfSettings->getUrl(PlayFabRequestURL);

    TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
    HttpRequest->SetURL(RequestUrl);
    HttpRequest->SetVerb(TEXT("POST"));

    // Headers
    if (useEntityToken)
        HttpRequest->SetHeader(TEXT("X-EntityToken"), CallAuthenticationContext != nullptr ? CallAuthenticationContext->GetEntityToken() : pfSettings->getEntityToken());
    else if (useSessionTicket)
        HttpRequest->SetHeader(TEXT("X-Authorization"), CallAuthenticationContext != nullptr ? CallAuthenticationContext->GetClientSessionTicket() : pfSettings->getSessionTicket());
    else if (useSecretKey)
        HttpRequest->SetHeader(TEXT("X-SecretKey"), CallAuthenticationContext != nullptr ? CallAuthenticationContext->GetDeveloperSecretKey() : pfSettings->getSecretApiKey());
    HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
    HttpRequest->SetHeader(TEXT("X-PlayFabSDK"), pfSettings->getVersionString());
    HttpRequest->SetHeader(TEXT("X-ReportErrorAsSuccess"), TEXT("true")); // FHttpResponsePtr doesn't provide sufficient information when an error code is returned
    for (TMap<FString, FString>::TConstIterator It(RequestHeaders); It; ++It)
        HttpRequest->SetHeader(It.Key(), It.Value());

    // Serialize data to json string
    FString OutputString;
    TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
    FJsonSerializer::Serialize(RequestJsonObj->GetRootObject().ToSharedRef(), Writer);

    // Set Json content
    HttpRequest->SetContentAsString(OutputString);

    UE_LOG(LogPlayFab, Log, TEXT("Request: %s"), *OutputString);

    // Bind event
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &UPlayFabAuthenticationAPI::OnProcessRequestComplete);

    // Execute the request
    pfSettings->ModifyPendingCallCount(1);
    HttpRequest->ProcessRequest();
}

void UPlayFabAuthenticationAPI::ResetResponseData()
{
    if (ResponseJsonObj != nullptr)
        ResponseJsonObj->Reset();
    else
        ResponseJsonObj = NewObject<UPlayFabJsonObject>();
    bIsValidJsonResponse = false;
}
