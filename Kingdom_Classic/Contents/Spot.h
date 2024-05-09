#pragma once
#include "BuildingObject.h"

class ASpot : public ABuildingObject
{
	GENERATED_BODY(ABuildingObject)

public:
	ASpot();
	~ASpot();

	ASpot(const ASpot& _Other) = delete;
	ASpot(ASpot&& _Other) noexcept = delete;
	ASpot& operator=(const ASpot& _Other) = delete;
	ASpot& operator=(ASpot&& _Other) noexcept = delete;

	ESpotUpgrade GetCurTier()
	{
		return CurTier;
	}

	bool GetIsUpgradable()
	{
		return IsUpgradable;
	}

	void SetIsUpgradable(bool _IsUpgradable)
	{
		IsUpgradable = _IsUpgradable;
	}

protected:
	ESpotUpgrade CurTier = ESpotUpgrade::Tier0;
	bool IsUpgradable = true;
	bool SkipUpgradeProgress = false;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	virtual void SettingUpgrade() {};

	// State
	virtual void StateInit();

	virtual void InactiveStart();
	virtual void ActiveStart();
	virtual void UpgradeStart();
	virtual void UpgradeDoneStart();

	virtual void Inactive(float _DeltaTime);
	virtual void Active(float _DeltaTime);
	virtual void Upgrade(float _DeltaTime);
	virtual void UpgradeDone(float _DeltaTime);

private:

};