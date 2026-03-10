#pragma once
#include <unordered_map>
#include <map>
#include <string>
#include <memory>

namespace chess::utils {

	template <typename K, typename V>
	using HashMap = std::unordered_map<K, V>;

	template <typename K, typename V>
	using TreeMap = std::map<K, V>;

	using String = std::string;

	template <typename T>
	using UPtr = std::unique_ptr<T>;

	template <typename T>
	using SPtr = std::shared_ptr<T>;

	template <typename T>
	using WPtr = std::weak_ptr<T>;

	template <typename T>
	struct Loc2 {
		T x, y;
	};

	struct Size2 {
		unsigned int x, y;
	};

}
