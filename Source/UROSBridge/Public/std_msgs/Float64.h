#pragma once
#include "ROSBridgeMsg.h"

namespace std_msgs
{
	class Float64 : public FROSBridgeMsg
	{
		double Data;

	public:
		Float64()
		{
			MsgType = "std_msgs/Float64";
		}


		Float64(float InData)
		{
			MsgType = "std_msgs/Float64";
			Data = InData;
		}

		~Float64() override {}

		double GetData()
		{
			return Data;
		}

		void SetData(double InData)
		{
			Data = InData;
		}

		virtual void FromJson(TSharedPtr<FJsonObject> JsonObject) override
		{
			Data = JsonObject->GetNumberField("data");
		}

		virtual FString ToString() const override
		{
			return TEXT("Float64 { data = \"") + FString::SanitizeFloat(Data) + TEXT("\" }");
		}

		virtual TSharedPtr<FJsonObject> ToJsonObject() const override
		{
			TSharedPtr<FJsonObject> Object = MakeShareable<FJsonObject>(new FJsonObject());
			Object->SetNumberField(TEXT("data"), Data);
			return Object;
		}

		virtual FString ToYamlString() const override
		{
			FString OutputString;
			TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
			FJsonSerializer::Serialize(ToJsonObject().ToSharedRef(), Writer);
			return OutputString;
		}
	};
} // namespace std_msgs
