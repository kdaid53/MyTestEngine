#pragma once

namespace kim::enums {

	enum class LayerType {
		None,
		BackGround,
		Player,
		Max = 16
	};

	enum class ResourceType {
		Texture,
		AudioClip,
		Prefab,
		End,
	};

	enum class ComponentType {
		Transform,
		SpriteRenderer,
		Script,
		Camera,
		End
	};
}
