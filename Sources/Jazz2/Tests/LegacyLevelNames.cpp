// Standalone regression test; link against the engine (or StringView.cpp with dead-code elimination).
#include "../Compatibility/LegacyLevelNames.h"
#include <cassert>
#include <cstdio>
#include <initializer_list>

int main()
{
	using namespace Death::Containers::Literals;
	using Jazz2::Compatibility::ResolveLegacyLevelName;
	// Save names from the old converter, including the reported Odin2 resume and bonus stages.
	assert(ResolveLegacyLevelName("rescue/05_beach"_s) == "rescue/beach"_s);
	assert(ResolveLegacyLevelName("prince/01_castle1"_s) == "prince/castle1"_s);
	assert(ResolveLegacyLevelName("prince/bonus_labrat3"_s) == "prince/labrat3"_s);
	assert(ResolveLegacyLevelName("flash/bonus_tube3"_s) == "flash/tube3"_s);
	assert(ResolveLegacyLevelName("monk/06_damn2"_s) == "monk/damn2"_s);
	assert(ResolveLegacyLevelName("share/01_share1"_s) == "share/share1"_s);
	assert(ResolveLegacyLevelName("xmas99/03_xmas3"_s) == "xmas99/xmas3"_s);
	assert(ResolveLegacyLevelName("secretf/09_town3"_s) == "secretf/town3"_s);
	// Custom numbered levels, existing current names, and unaffected holiday packs retain their identity.
	for (auto name : { "unknown/05_beach"_s, "rescue/99_beach"_s, "custom/01_castle1"_s,
		"rescue/beach"_s, "hh17/hh17_level01"_s, ""_s }) {
		assert(ResolveLegacyLevelName(name) == name);
	}
	std::puts("Legacy level name regression tests passed");
}
