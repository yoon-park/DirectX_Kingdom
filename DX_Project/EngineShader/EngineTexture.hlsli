#define TextureSet(Name, Slot) Texture2D Name : register(t##Slot##); SamplerState Name##_Sampler : register(s##Slot##);

#define Sampling(Name, TEXCOORD) Name##.Sample(##Name##_Sampler, ##TEXCOORD##.xy);