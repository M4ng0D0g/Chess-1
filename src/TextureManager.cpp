#include "chess/model/manager/TextureManager.hpp"
#include "chess/view/Theme.hpp"
#include "chess/model/piece/PieceType.hpp"

namespace chess::model::manager {

	const Texture2D& TextureManager::getTexture(
		const chess::view::Theme& theme,
		const piece::PieceType& type,
		Team team
	) {
		// key = "{themePath}{typeName}_{team}" e.g. "classic/bishop_b"
		String teamStr = (team == Team::White) ? "w" : "b";
		String key = theme.getTexturePath() + type.getName() + "_" + teamStr;

		auto it = _cache.find(key);
		if (it != _cache.end())
			return it->second;

		// Lazy load: build full path from key
		String path = "assets/textures/piece/" + key + ".png";
		_cache[key] = LoadTexture(path.c_str());
		return _cache[key];
	}

}
