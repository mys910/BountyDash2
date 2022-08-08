// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PowerUpPlugin/Public/PowerUpObject.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePowerUpObject() {}
// Cross Module References
	POWERUPPLUGIN_API UClass* Z_Construct_UClass_UPowerUpObject_NoRegister();
	POWERUPPLUGIN_API UClass* Z_Construct_UClass_UPowerUpObject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_PowerUpPlugin();
// End Cross Module References
	void UPowerUpObject::StaticRegisterNativesUPowerUpObject()
	{
	}
	UClass* Z_Construct_UClass_UPowerUpObject_NoRegister()
	{
		return UPowerUpObject::StaticClass();
	}
	struct Z_Construct_UClass_UPowerUpObject_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPowerUpObject_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_PowerUpPlugin,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPowerUpObject_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "PowerUpObject.h" },
		{ "ModuleRelativePath", "Public/PowerUpObject.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPowerUpObject_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPowerUpObject>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPowerUpObject_Statics::ClassParams = {
		&UPowerUpObject::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UPowerUpObject_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPowerUpObject_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPowerUpObject()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPowerUpObject_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPowerUpObject, 3059111474);
	template<> POWERUPPLUGIN_API UClass* StaticClass<UPowerUpObject>()
	{
		return UPowerUpObject::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPowerUpObject(Z_Construct_UClass_UPowerUpObject, &UPowerUpObject::StaticClass, TEXT("/Script/PowerUpPlugin"), TEXT("UPowerUpObject"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPowerUpObject);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
