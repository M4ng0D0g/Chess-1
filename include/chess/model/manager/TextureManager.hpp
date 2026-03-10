#pragma once
#include <unordered_map>
#include <string>
#include "raylib.h"

#include "chess/utils/Unit.hpp"
#include "../enums/PieceType.hpp"
#include "../enums/Team.hpp"

namespace chess::manager {
	using namespace chess::enums;

	class TextureManager {
	private:
		TextureManager() {}
		~TextureManager() = default;

		HashMap<String, Texture2D> _textureCache;
		
	public:
		static TextureManager& instance() {
			static TextureManager instance;
			return instance;
		}
		TextureManager(const TextureManager& other) = delete;
		TextureManager& operator=(const TextureManager& other) = delete;

		const Texture2D& getTexture(const PieceType& type, Team team) {
            auto key = std::make_pair(&type, color);

            // 2. 檢查是否已經在快取中
            auto it = _textureCache.find(type);
            if (it != _textureCache.end()) {
                return it->second; // 命中快取，直接回傳
            }

            // 3. 快取未命中，執行延遲載入
            // 根據類型與顏色生成檔案路徑，例如 "assets/W_K.png"
            std::string path = generatePath(type, color);
            
            // 假設 LoadTexture 是你底層繪圖庫的函式
            _textureCache[key] = LoadTexture(path.c_str());

            return _textureCache[key];
        }

		

	};
}