#include "PreCompile.h"
#include "TitleLogo.h"

ATitleLogo::ATitleLogo()
{
	Renderer = CreateDefaultSubObject<URenderer>("Renderer");
	Renderer->SetMesh("Rect");
	Renderer->SetMaterial("2DImage");
}

ATitleLogo::~ATitleLogo()
{

}

void ATitleLogo::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(700.0f, 300.0f, 100.0f));

	DelayCallback(1.0f, std::bind(&ATitleLogo::RendererOff, this));

	Renderer->Resources->SettingTexture("Image", "KingdomTitle.png", "POINT");
}

void ATitleLogo::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void ATitleLogo::RendererOn()
{
	Renderer->SetActive(true);
	DelayCallback(1.0f, std::bind(&ATitleLogo::RendererOff, this));
}

void ATitleLogo::RendererOff()
{
	Renderer->SetActive(false);
	DelayCallback(1.0f, std::bind(&ATitleLogo::RendererOn, this));
}