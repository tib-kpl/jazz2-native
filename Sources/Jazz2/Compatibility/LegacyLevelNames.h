#pragma once

#include <Containers/StringView.h>

namespace Jazz2::Compatibility
{
	/** Names written into saves before the original levels lost their numeric/bonus prefixes. */
	inline Death::Containers::StringView ResolveLegacyLevelName(Death::Containers::StringView name)
	{
		using namespace Death::Containers::Literals;
		struct Alias { Death::Containers::StringView Old, Current; };
		static const Alias aliases[] = {
			{ "prince/01_castle1"_s, "prince/castle1"_s },
			{ "prince/02_castle1n"_s, "prince/castle1n"_s },
			{ "prince/03_carrot1"_s, "prince/carrot1"_s },
			{ "prince/04_carrot1n"_s, "prince/carrot1n"_s },
			{ "prince/05_labrat1"_s, "prince/labrat1"_s },
			{ "prince/06_labrat2"_s, "prince/labrat2"_s },
			{ "prince/bonus_labrat3"_s, "prince/labrat3"_s },
			{ "rescue/01_colon1"_s, "rescue/colon1"_s },
			{ "rescue/02_colon2"_s, "rescue/colon2"_s },
			{ "rescue/03_psych1"_s, "rescue/psych1"_s },
			{ "rescue/04_psych2"_s, "rescue/psych2"_s },
			{ "rescue/05_beach"_s, "rescue/beach"_s },
			{ "rescue/06_beach2"_s, "rescue/beach2"_s },
			{ "rescue/bonus_psych3"_s, "rescue/psych3"_s },
			{ "flash/01_diam1"_s, "flash/diam1"_s },
			{ "flash/02_diam3"_s, "flash/diam3"_s },
			{ "flash/03_tube1"_s, "flash/tube1"_s },
			{ "flash/04_tube2"_s, "flash/tube2"_s },
			{ "flash/05_medivo1"_s, "flash/medivo1"_s },
			{ "flash/06_medivo2"_s, "flash/medivo2"_s },
			{ "flash/bonus_garglair"_s, "flash/garglair"_s },
			{ "flash/bonus_tube3"_s, "flash/tube3"_s },
			{ "monk/01_jung1"_s, "monk/jung1"_s },
			{ "monk/02_jung2"_s, "monk/jung2"_s },
			{ "monk/03_hell"_s, "monk/hell"_s },
			{ "monk/04_hell2"_s, "monk/hell2"_s },
			{ "monk/05_damn"_s, "monk/damn"_s },
			{ "monk/06_damn2"_s, "monk/damn2"_s },
			{ "share/01_share1"_s, "share/share1"_s },
			{ "share/02_share2"_s, "share/share2"_s },
			{ "share/03_share3"_s, "share/share3"_s },
			{ "xmas99/01_xmas1"_s, "xmas99/xmas1"_s },
			{ "xmas99/02_xmas2"_s, "xmas99/xmas2"_s },
			{ "xmas99/03_xmas3"_s, "xmas99/xmas3"_s },
			{ "secretf/01_easter1"_s, "secretf/easter1"_s },
			{ "secretf/02_easter2"_s, "secretf/easter2"_s },
			{ "secretf/03_easter3"_s, "secretf/easter3"_s },
			{ "secretf/04_haunted1"_s, "secretf/haunted1"_s },
			{ "secretf/05_haunted2"_s, "secretf/haunted2"_s },
			{ "secretf/06_haunted3"_s, "secretf/haunted3"_s },
			{ "secretf/07_town1"_s, "secretf/town1"_s },
			{ "secretf/08_town2"_s, "secretf/town2"_s },
			{ "secretf/09_town3"_s, "secretf/town3"_s },
		};
		for (const auto& alias : aliases) {
			if (name == alias.Old) {
				return alias.Current;
			}
		}
		return name;
	}
}
