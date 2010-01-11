#pragma once

using namespace System;

namespace dotnetworks
{
	public enum class SNetSocketConnectionType
	{
		NotConnected = 0,
		UDP = 1,
		UDPRelay = 2,
	};
}