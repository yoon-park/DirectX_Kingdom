#pragma once
#include "KingdomActor.h"

class USpriteRenderer;

class AGround : public AKingdomActor
{
	GENERATED_BODY(AKingdomActor)

public:
	AGround();
	~AGround();

	AGround(const AGround& _Other) = delete;
	AGround(AGround&& _Other) noexcept = delete;
	AGround& operator=(const AGround& _Other) = delete;
	AGround& operator=(AGround&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Renderer;
	float4 Color;
};