#pragma once
#include "chess/utils/Unit.hpp"

namespace chess::controller::gamemode {
	using namespace utils;

	class IGamemode {
	private:
	public:
		~IGamemode() = default;

		virtual const Size2& getCellSize() const = 0;
		virtual const Size2& getCellCount() const = 0;
		virtual const String& getTitle() const = 0;

		virtual void init() = 0;
	};
}