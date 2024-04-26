#pragma once
#include "KingdomActor.h"

class USpriteRenderer;

class ABack0 : public AKingdomActor
{
	GENERATED_BODY(AKingdomActor)

public:
	ABack0();
	~ABack0();

	ABack0(const ABack0& _Other) = delete;
	ABack0(ABack0&& _Other) noexcept = delete;
	ABack0& operator=(const ABack0& _Other) = delete;
	ABack0& operator=(ABack0&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Renderer;
	float4 Color;
};