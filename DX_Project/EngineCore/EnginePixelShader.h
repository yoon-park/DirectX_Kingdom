#pragma once
#include "EngineShader.h"

class UEngineMaterial;

class UEnginePixelShader : public UEngineResources<UEnginePixelShader>, public UEngineShader
{
	friend UEngineMaterial;

public:
	UEnginePixelShader();
	~UEnginePixelShader();

	UEnginePixelShader(const UEnginePixelShader& _Other) = delete;
	UEnginePixelShader(UEnginePixelShader&& _Other) noexcept = delete;
	UEnginePixelShader& operator=(const UEnginePixelShader& _Other) = delete;
	UEnginePixelShader& operator=(UEnginePixelShader&& _Other) noexcept = delete;

	static std::shared_ptr<UEnginePixelShader> Load(
		std::string_view _Path,
		std::string_view _EntryPoint,
		UINT _High = 5,
		UINT _Low = 0)
	{
		std::shared_ptr<UEnginePixelShader> Res = CreateResName(_Path);
		Res->ResLoad(_EntryPoint, _High, _Low);
		return Res;
	}

	static std::shared_ptr<UEnginePixelShader> Load(
		std::string_view _Name,
		std::string_view _Path,
		std::string_view _EntryPoint,
		UINT _High = 5,
		UINT _Low = 0)
	{
		std::shared_ptr<UEnginePixelShader> Res = CreateResName(_Path, _Name);
		Res->ResLoad(_EntryPoint, _High, _Low);
		return Res;
	}

protected:

private:
	ID3D11PixelShader* ShaderPtr = nullptr;

	void ResLoad(std::string_view _EntryPoint, UINT _High, UINT Low);
	void Setting();
};