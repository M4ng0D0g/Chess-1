#pragma once
#include <unordered_map>
#include <string>
#include "raylib.h"
#include "chess/utils/Unit.hpp"
#include "chess/model/enums/Team.hpp"

namespace chess::view { class Theme; }
namespace chess::model::piece { class PieceType; }

namespace chess::model::manager {
	using namespace chess::utils;
	using namespace chess::model::enums;

	class TextureManager {
	private:
		TextureManager() = default;
		~TextureManager() {
			for (auto& [key, tex] : _cache)
				UnloadTexture(tex);
		}

		HashMap<String, Texture2D> _cache;

	public:
		static TextureManager& instance() {
			static TextureManager inst;
			return inst;
		}
		TextureManager(const TextureManager&) = delete;
		TextureManager& operator=(const TextureManager&) = delete;

		const Texture2D& getTexture(
			const chess::view::Theme& theme,
			const piece::PieceType& type,
			Team team
		);
	};
}