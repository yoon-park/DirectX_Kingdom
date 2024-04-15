#pragma once
#include "EngineResources.h"

class UEngineSoundPlayer
{
	friend class UEngineSound;

public:
	void SetVolume(float _Volume);

	void On()
	{
		Control->setPaused(false);
	}

	void Off()
	{
		Control->setPaused(true);
	}

	void OnOffSwitch()
	{
		bool Check = false;
		Control->getPaused(&Check);

		if (Check == true)
		{
			Control->setPaused(false);
		}
		else {
			Control->setPaused(true);
		}
	}

	void Loop(int Count = -1)
	{
		Control->setLoopCount(Count);
	}

	void Replay()
	{
		Control->setPosition(0, FMOD_TIMEUNIT_MS);
	}

private:
	FMOD::Channel* Control = nullptr;
};

class UEngineSound : public UEngineResources<UEngineSound>
{
	friend class ResControl;

private:
	friend UEngineSoundPlayer;

	static float GlobalVolume;

public:
	UEngineSound();
	~UEngineSound();

	UEngineSound(const UEngineSound& _Other) = delete;
	UEngineSound(UEngineSound&& _Other) noexcept = delete;
	UEngineSound& operator=(const UEngineSound& _Other) = delete;
	UEngineSound& operator=(UEngineSound&& _Other) noexcept = delete;

	static void SetGlobalVolume(float _Value);

	static void Load(std::string_view _Path)
	{
		UEnginePath NewPath = UEnginePath(std::filesystem::path(_Path));
		std::string FileName = NewPath.GetFileName();
		return Load(_Path, FileName);
	}

	static void Load(std::string_view _Path, std::string_view _Name);
	static void Update();

	static UEngineSoundPlayer SoundPlay(std::string_view _Name);

protected:
	void ResLoad(std::string_view _Path);

private:
	FMOD::Sound* SoundHandle = nullptr;
};