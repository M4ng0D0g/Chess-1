#pragma once
#include <string>
#include "Palette.hpp";

namespace chess::view {
	
	class Theme {
	private:
		explicit Theme(
			const std::string& texturePath,
			const Color& light,
			const Color& dark
		) : _texturePath(texturePath), _light(light), _dark(dark) {}
		~Theme() = default;

		const std::string _texturePath;
		const Color _light;
		const Color _dark;


	public:
		static Theme& CLASSIC() {
			static Theme instance("classic/", CLASSIC_LIGHT, CLASSIC_DARK);
			return instance;
		}

		Theme(const Theme& other) = delete;
		Theme& operator=(const Theme& other) = delete;

		bool operator==(const Theme& other) const {
			return this == &other; 
		}

		bool operator!=(const Theme& other) const {
			return !(*this == other);
		}

		const std::string& getTexturePath() const {
			return _texturePath;
		}

		const Color& getLightColor() const {
			return _light;
		}

		const Color& getDarkColor() const {
			return _dark;
		}
	};
}