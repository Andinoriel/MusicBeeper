#pragma once
#ifndef __MUSIC_BEEPER_HPP__
#define __MUSIC_BEEPER_HPP__

#include <vector>
#include <string>

#ifdef __linux__ 
    #include <unistd.h>
#elif _WIN32
    #include <Windows.h>
#endif

class MusicBeeper
{
public:
	MusicBeeper() = delete;
	~MusicBeeper(void) = delete;

	static void BeepGoT(void) noexcept;
	static void BeepImperialMarch(void) noexcept;
private:
	class Music
	{
	public:
		enum class Note
		{
			F3 = 175,
			G3 = 196,
			GS3 = 208,
			AS3 = 233,
			C4 = 262,
			D4 = 294,
			DS4 = 311,
			E4 = 330,
			F4 = 349,
			GB4 = 369,
			G4 = 392,
			AB4 = 415,
			A4 = 440,
			BB4 = 466,
			B4 = 493,
			C5 = 523,
			DB5 = 554,
			D5 = 587,
			EB5 = 622,
			E5 = 659,
			F5 = 698,
			GB5 = 739,
			G5 = 784,
		};
		using song = std::pair<std::string, std::vector<std::pair<Music::Note, std::pair<size_t, size_t>>>>;

		static song GoT;
		static song ImperialMarch;
	};
	class Beeper
	{
	public:
		static void Beep(size_t frequency, size_t time) noexcept;
	};
};

#endif // !__MUSIC_BEEPER_HPP__