#pragma once

namespace dotnetworks
{
	public enum class VoiceResult
	{
		OK = 0,
		NotInitialized = 1,
		NotRecording = 2,
		NoData = 3,
		BufferTooSmall = 4,
		DataCorrupted = 5,
	};
}