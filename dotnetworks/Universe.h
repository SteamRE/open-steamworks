#pragma once

using namespace System;

namespace dotnetworks
{
	public enum class Universe
	{
		Invalid = 0,
		Public = 1,
		Beta = 2,
		Internal = 3,
		Dev = 4,
		RC = 5,

		//k_EUniverseMax
	};
}