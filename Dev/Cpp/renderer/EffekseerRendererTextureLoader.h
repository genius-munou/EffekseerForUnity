
#pragma once

#include <Effekseer.h>
#include <map>
#include <string>
#include "../common/IUnityInterface.h"
#include "../common/EffekseerPluginTexture.h"

namespace EffekseerRendererUnity
{
	class TextureLoader 
		: public Effekseer::TextureLoader
	{
	protected:
		EffekseerPlugin::TextureLoaderLoad load;
		EffekseerPlugin::TextureLoaderUnload unload;

		struct TextureResource {
			int referenceCount = 1;
			Effekseer::TextureData texture = {};
		};
		std::map<std::u16string, TextureResource> resources;
		std::map<void*, void*> textureData2NativePtr;


	public:
		static TextureLoader* Create(
			EffekseerPlugin::TextureLoaderLoad load,
			EffekseerPlugin::TextureLoaderUnload unload);
		TextureLoader(
			EffekseerPlugin::TextureLoaderLoad load,
			EffekseerPlugin::TextureLoaderUnload unload)
			: load(load), unload(unload) {}
		virtual ~TextureLoader() {}
		Effekseer::TextureData* Load(const EFK_CHAR* path, Effekseer::TextureType textureType) override;
		void Unload(Effekseer::TextureData* source) override;
	};
};

