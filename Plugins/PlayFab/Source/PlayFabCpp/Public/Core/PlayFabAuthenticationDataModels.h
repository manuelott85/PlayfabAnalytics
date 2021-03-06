//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabCppBaseModel.h"

namespace PlayFab
{
namespace AuthenticationModels
{

    struct PLAYFABCPP_API FEntityKey : public PlayFab::FPlayFabCppBaseModel
    {
        // Unique ID of the entity.
        FString Id;

        // [optional] Entity type. See https://api.playfab.com/docs/tutorials/entities/entitytypes
        FString Type;

        FEntityKey() :
            FPlayFabCppBaseModel(),
            Id(),
            Type()
            {}

        FEntityKey(const FEntityKey& src) :
            FPlayFabCppBaseModel(),
            Id(src.Id),
            Type(src.Type)
            {}

        FEntityKey(const TSharedPtr<FJsonObject>& obj) : FEntityKey()
        {
            readFromValue(obj);
        }

        ~FEntityKey();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FActivateAPIKeyRequest : public PlayFab::FPlayFabCppRequestCommon
    {
        // [optional] Unique identifier for the entity API key to activate.
        FString APIKeyId;

        // [optional] The entity to perform this action on.
        TSharedPtr<FEntityKey> Entity;

        FActivateAPIKeyRequest() :
            FPlayFabCppRequestCommon(),
            APIKeyId(),
            Entity(nullptr)
            {}

        FActivateAPIKeyRequest(const FActivateAPIKeyRequest& src) :
            FPlayFabCppRequestCommon(),
            APIKeyId(src.APIKeyId),
            Entity(src.Entity.IsValid() ? MakeShareable(new FEntityKey(*src.Entity)) : nullptr)
            {}

        FActivateAPIKeyRequest(const TSharedPtr<FJsonObject>& obj) : FActivateAPIKeyRequest()
        {
            readFromValue(obj);
        }

        ~FActivateAPIKeyRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FActivateAPIKeyResponse : public PlayFab::FPlayFabCppResultCommon
    {
        FActivateAPIKeyResponse() :
            FPlayFabCppResultCommon()
            {}

        FActivateAPIKeyResponse(const FActivateAPIKeyResponse& src) :
            FPlayFabCppResultCommon()
            {}

        FActivateAPIKeyResponse(const TSharedPtr<FJsonObject>& obj) : FActivateAPIKeyResponse()
        {
            readFromValue(obj);
        }

        ~FActivateAPIKeyResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FCreateAPIKeyDetails : public PlayFab::FPlayFabCppBaseModel
    {
        /**
         * Whether the key is active for authentication. Inactive keys cannot be used to authenticate.Keys can be activated or
         * deactivate using the ActivateKey and DeactivateKey APIs.Deactivating a key is a way to verify that the key is not in use
         * before deleting it.
         */
        bool Active;

        // [optional] Unique identifier for the entity API key. Set in the "X - EntityAPIKeyId" in authentication requests.
        FString APIKeyId;

        /**
         * [optional] Secret used to authenticate requests with the key. Set in the "X - EntityAPIKeyId" in authentication requests.The secret
         * value is returned only once in this response and cannot be retrieved afterward, either via API or in Game Manager.API
         * key secrets should be stored securely only on trusted servers and never distributed in code or configuration to
         * untrusted clients.
         */
        FString APIKeySecret;

        // The time the API key was generated, in UTC.
        FDateTime Created;

        FCreateAPIKeyDetails() :
            FPlayFabCppBaseModel(),
            Active(false),
            APIKeyId(),
            APIKeySecret(),
            Created(0)
            {}

        FCreateAPIKeyDetails(const FCreateAPIKeyDetails& src) :
            FPlayFabCppBaseModel(),
            Active(src.Active),
            APIKeyId(src.APIKeyId),
            APIKeySecret(src.APIKeySecret),
            Created(src.Created)
            {}

        FCreateAPIKeyDetails(const TSharedPtr<FJsonObject>& obj) : FCreateAPIKeyDetails()
        {
            readFromValue(obj);
        }

        ~FCreateAPIKeyDetails();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FCreateAPIKeyRequest : public PlayFab::FPlayFabCppRequestCommon
    {
        // [optional] The entity to perform this action on.
        TSharedPtr<FEntityKey> Entity;

        FCreateAPIKeyRequest() :
            FPlayFabCppRequestCommon(),
            Entity(nullptr)
            {}

        FCreateAPIKeyRequest(const FCreateAPIKeyRequest& src) :
            FPlayFabCppRequestCommon(),
            Entity(src.Entity.IsValid() ? MakeShareable(new FEntityKey(*src.Entity)) : nullptr)
            {}

        FCreateAPIKeyRequest(const TSharedPtr<FJsonObject>& obj) : FCreateAPIKeyRequest()
        {
            readFromValue(obj);
        }

        ~FCreateAPIKeyRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FCreateAPIKeyResponse : public PlayFab::FPlayFabCppResultCommon
    {
        // [optional] The entity id and type.
        TSharedPtr<FEntityKey> Entity;

        // [optional] The created API key
        TSharedPtr<FCreateAPIKeyDetails> Key;

        FCreateAPIKeyResponse() :
            FPlayFabCppResultCommon(),
            Entity(nullptr),
            Key(nullptr)
            {}

        FCreateAPIKeyResponse(const FCreateAPIKeyResponse& src) :
            FPlayFabCppResultCommon(),
            Entity(src.Entity.IsValid() ? MakeShareable(new FEntityKey(*src.Entity)) : nullptr),
            Key(src.Key.IsValid() ? MakeShareable(new FCreateAPIKeyDetails(*src.Key)) : nullptr)
            {}

        FCreateAPIKeyResponse(const TSharedPtr<FJsonObject>& obj) : FCreateAPIKeyResponse()
        {
            readFromValue(obj);
        }

        ~FCreateAPIKeyResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FDeactivateAPIKeyRequest : public PlayFab::FPlayFabCppRequestCommon
    {
        // [optional] Unique identifier for the entity API key to activate.
        FString APIKeyId;

        // [optional] The entity to perform this action on.
        TSharedPtr<FEntityKey> Entity;

        FDeactivateAPIKeyRequest() :
            FPlayFabCppRequestCommon(),
            APIKeyId(),
            Entity(nullptr)
            {}

        FDeactivateAPIKeyRequest(const FDeactivateAPIKeyRequest& src) :
            FPlayFabCppRequestCommon(),
            APIKeyId(src.APIKeyId),
            Entity(src.Entity.IsValid() ? MakeShareable(new FEntityKey(*src.Entity)) : nullptr)
            {}

        FDeactivateAPIKeyRequest(const TSharedPtr<FJsonObject>& obj) : FDeactivateAPIKeyRequest()
        {
            readFromValue(obj);
        }

        ~FDeactivateAPIKeyRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FDeactivateAPIKeyResponse : public PlayFab::FPlayFabCppResultCommon
    {
        FDeactivateAPIKeyResponse() :
            FPlayFabCppResultCommon()
            {}

        FDeactivateAPIKeyResponse(const FDeactivateAPIKeyResponse& src) :
            FPlayFabCppResultCommon()
            {}

        FDeactivateAPIKeyResponse(const TSharedPtr<FJsonObject>& obj) : FDeactivateAPIKeyResponse()
        {
            readFromValue(obj);
        }

        ~FDeactivateAPIKeyResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FDeleteAPIKeyRequest : public PlayFab::FPlayFabCppRequestCommon
    {
        // [optional] Unique identifier for the entity API key to delete.
        FString APIKeyId;

        // [optional] The entity to perform this action on.
        TSharedPtr<FEntityKey> Entity;

        FDeleteAPIKeyRequest() :
            FPlayFabCppRequestCommon(),
            APIKeyId(),
            Entity(nullptr)
            {}

        FDeleteAPIKeyRequest(const FDeleteAPIKeyRequest& src) :
            FPlayFabCppRequestCommon(),
            APIKeyId(src.APIKeyId),
            Entity(src.Entity.IsValid() ? MakeShareable(new FEntityKey(*src.Entity)) : nullptr)
            {}

        FDeleteAPIKeyRequest(const TSharedPtr<FJsonObject>& obj) : FDeleteAPIKeyRequest()
        {
            readFromValue(obj);
        }

        ~FDeleteAPIKeyRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FDeleteAPIKeyResponse : public PlayFab::FPlayFabCppResultCommon
    {
        FDeleteAPIKeyResponse() :
            FPlayFabCppResultCommon()
            {}

        FDeleteAPIKeyResponse(const FDeleteAPIKeyResponse& src) :
            FPlayFabCppResultCommon()
            {}

        FDeleteAPIKeyResponse(const TSharedPtr<FJsonObject>& obj) : FDeleteAPIKeyResponse()
        {
            readFromValue(obj);
        }

        ~FDeleteAPIKeyResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FGetAPIKeyDetails : public PlayFab::FPlayFabCppBaseModel
    {
        /**
         * Whether the key is active for authentication. Inactive keys cannot be used to authenticate.Keys can be activated or
         * deactivate using the SetAPIActivation API.Deactivating a key is a way to verify that the key is not in use be before
         * deleting it.
         */
        bool Active;

        // [optional] Unique identifier for the entity API key. Set in the "X - EntityAPIKeyId" in authentication requests.
        FString APIKeyId;

        // The time the API key was generated, in UTC.
        FDateTime Created;

        FGetAPIKeyDetails() :
            FPlayFabCppBaseModel(),
            Active(false),
            APIKeyId(),
            Created(0)
            {}

        FGetAPIKeyDetails(const FGetAPIKeyDetails& src) :
            FPlayFabCppBaseModel(),
            Active(src.Active),
            APIKeyId(src.APIKeyId),
            Created(src.Created)
            {}

        FGetAPIKeyDetails(const TSharedPtr<FJsonObject>& obj) : FGetAPIKeyDetails()
        {
            readFromValue(obj);
        }

        ~FGetAPIKeyDetails();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FGetAPIKeysRequest : public PlayFab::FPlayFabCppRequestCommon
    {
        // [optional] The entity to perform this action on.
        TSharedPtr<FEntityKey> Entity;

        FGetAPIKeysRequest() :
            FPlayFabCppRequestCommon(),
            Entity(nullptr)
            {}

        FGetAPIKeysRequest(const FGetAPIKeysRequest& src) :
            FPlayFabCppRequestCommon(),
            Entity(src.Entity.IsValid() ? MakeShareable(new FEntityKey(*src.Entity)) : nullptr)
            {}

        FGetAPIKeysRequest(const TSharedPtr<FJsonObject>& obj) : FGetAPIKeysRequest()
        {
            readFromValue(obj);
        }

        ~FGetAPIKeysRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FGetAPIKeysResponse : public PlayFab::FPlayFabCppResultCommon
    {
        // [optional] The entity id and type.
        TSharedPtr<FEntityKey> Entity;

        // [optional] The API keys associated with the given entity.
        TArray<FGetAPIKeyDetails> Keys;
        FGetAPIKeysResponse() :
            FPlayFabCppResultCommon(),
            Entity(nullptr),
            Keys()
            {}

        FGetAPIKeysResponse(const FGetAPIKeysResponse& src) :
            FPlayFabCppResultCommon(),
            Entity(src.Entity.IsValid() ? MakeShareable(new FEntityKey(*src.Entity)) : nullptr),
            Keys(src.Keys)
            {}

        FGetAPIKeysResponse(const TSharedPtr<FJsonObject>& obj) : FGetAPIKeysResponse()
        {
            readFromValue(obj);
        }

        ~FGetAPIKeysResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FGetEntityTokenRequest : public PlayFab::FPlayFabCppRequestCommon
    {
        // [optional] The entity to perform this action on.
        TSharedPtr<FEntityKey> Entity;

        FGetEntityTokenRequest() :
            FPlayFabCppRequestCommon(),
            Entity(nullptr)
            {}

        FGetEntityTokenRequest(const FGetEntityTokenRequest& src) :
            FPlayFabCppRequestCommon(),
            Entity(src.Entity.IsValid() ? MakeShareable(new FEntityKey(*src.Entity)) : nullptr)
            {}

        FGetEntityTokenRequest(const TSharedPtr<FJsonObject>& obj) : FGetEntityTokenRequest()
        {
            readFromValue(obj);
        }

        ~FGetEntityTokenRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FGetEntityTokenResponse : public PlayFab::FPlayFabCppResultCommon
    {
        // [optional] The entity id and type.
        TSharedPtr<FEntityKey> Entity;

        // [optional] The token used to set X-EntityToken for all entity based API calls.
        FString EntityToken;

        // [optional] The time the token will expire, if it is an expiring token, in UTC.
        Boxed<FDateTime> TokenExpiration;

        FGetEntityTokenResponse() :
            FPlayFabCppResultCommon(),
            Entity(nullptr),
            EntityToken(),
            TokenExpiration()
            {}

        FGetEntityTokenResponse(const FGetEntityTokenResponse& src) :
            FPlayFabCppResultCommon(),
            Entity(src.Entity.IsValid() ? MakeShareable(new FEntityKey(*src.Entity)) : nullptr),
            EntityToken(src.EntityToken),
            TokenExpiration(src.TokenExpiration)
            {}

        FGetEntityTokenResponse(const TSharedPtr<FJsonObject>& obj) : FGetEntityTokenResponse()
        {
            readFromValue(obj);
        }

        ~FGetEntityTokenResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

}
}
