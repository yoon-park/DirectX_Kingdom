#pragma once
#include "Renderer.h"
#include "EngineSprite.h"

#include "EngineEnums.h"

struct FCuttingData
{
	float4 CuttingPosition;
	float4 CuttingSize;
};

class UEngineSprite;

class USpriteAnimation : public UNameObject
{
public:
	std::shared_ptr<UEngineSprite> Sprite;
	std::vector<float> Inter;
	std::vector<int> Frame;
	int CurFrame = 0;
	float CurTime = 0.0f;
	bool Loop = true;
	bool IsEnd = false;

	std::map<int, std::function<void()>> FrameCallback;

	FSpriteInfo GetCurSpriteInfo()
	{
		return Sprite->GetSpriteInfo(Frame[CurFrame]);
	}

	void FrameCallBackCheck();

	void Reset()
	{
		CurTime = 0.0f;
		CurFrame = 0;
	}

	void Update(float _DeltaTime);
};

class UEngineTexture;

class USpriteRenderer : public URenderer
{
	GENERATED_BODY(URenderer);

public:
	USpriteRenderer();
	~USpriteRenderer();

	USpriteRenderer(const USpriteRenderer& _Other) = delete;
	USpriteRenderer(USpriteRenderer&& _Other) noexcept = delete;
	USpriteRenderer& operator=(const USpriteRenderer& _Other) = delete;
	USpriteRenderer& operator=(USpriteRenderer&& _Other) noexcept = delete;

	inline EEngineDir GetDir() const
	{
		return Dir;
	}

	void SetSprite(std::string_view _Name, UINT _Index = 0);
	void SetPlusColor(float4 _Color);
	void SetSamplering(ETextureSampling _Value);
	void SetAutoSize(float _ScaleRatio, bool _AutoSize);
	void SetSpriteInfo(const FSpriteInfo& _Info);
	void SetDir(EEngineDir _Dir);
	void SetFrameCallback(std::string_view _AnimationName, int _Index, std::function<void()> _Function);

	void CreateAnimation(
		std::string_view _AnimationName,
		std::string_view _SpriteName, 
		float _Inter = 0.1f,
		bool _Loop = true, 
		int _Start = -1, 
		int _End = -1);

	void CreateAnimation(
		std::string_view _AnimationName, 
		std::string_view _SpriteName, 
		std::vector<float> _Inter, 
		std::vector<int> _Frame, 
		bool _Loop = true);

	void ChangeAnimation(std::string_view _AnimationName);

	bool IsCurAnimationEnd();

protected:
	void MaterialSettingEnd() override;

	void Tick(float _DeltaTime) override;

private:
	FCuttingData CuttingDataValue;
	float4 PlusColor = float4::Zero;
	ETextureSampling SamplingValue = ETextureSampling::POINT;
	bool AutoSize = false;
	float ScaleRatio = 1.0f;
	FSpriteInfo CurInfo;
	EEngineDir Dir = EEngineDir::MAX;
	std::shared_ptr<UEngineTexture> CurTexture = nullptr;
	std::shared_ptr<USpriteAnimation> CurAnimation = nullptr;

	std::map<std::string, std::shared_ptr<USpriteAnimation>> Animations;
};