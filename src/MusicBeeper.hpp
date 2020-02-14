#pragma once
#ifndef __MUSIC_BEEPER_HPP__
#define __MUSIC_BEEPER_HPP__

#include <vector>
#include <string>
#include <functional>

#ifdef __linux__ 
	#include <unistd.h>
	#include <fcntl.h>

	#include <ctime>
	#include <cmath>
	#include <cstdint>

	#include <signal.h>

	// from linux/input-event-codes.h
	#define __EV_SND 0x12
	#define __SND_TONE 0x2

	typedef struct
	{
		timeval time;
		uint16_t type;
		uint16_t code;
		int32_t value;
	} input_event;

	[[noreturn]] void __ctrl_c_break_handle(sig_atomic_t);
	#define __PREVENT_BEEP_LOOP(callback) signal(SIGINT, (callback));
	#define PREVENT_BEEP_LOOP __PREVENT_BEEP_LOOP(__ctrl_c_break_handle)
#elif _WIN32
    #include <Windows.h>
	#define PREVENT_BEEP_LOOP
#endif

class MusicBeeper final
{
public:
	MusicBeeper() = delete;
	~MusicBeeper(void) = delete;

	static void BeepGoT(void) noexcept;
	static void BeepImperialMarch(void) noexcept;
	static void BeepSovietAnthem(void) noexcept;
	static void BeepOdeToJoy(void) noexcept;
private:
	class Music
	{
	public:
		enum class Note
		{
			F3 = 175,			G3 = 196,			GS3 = 208,			A3 = 220,			AS3 = 233,			
			C4 = 262,			D4 = 294,			DS4 = 311,			E4 = 330,			F4 = 349,			
			GB4 = 369,			G4 = 392,			AB4 = 415,			A4 = 440,			BB4 = 466,			
			B4 = 493,			C5 = 523,			DB5 = 554,			D5 = 587,			EB5 = 622,			
			E5 = 659,			F5 = 698,			GB5 = 739,			G5 = 784,			A5 = 880,
			B5 = 987,			C6 = 1046,			D6 = 1174,
		};

		// pair of Note and pair of beep time and pause after beep
		using song_note = std::pair<Music::Note, std::pair<size_t, size_t>>;
		// pair of Music name and vector of song_note
		using song = std::pair<std::string, std::vector<song_note>>;

	#pragma region songs
		inline static song GoT = 
		{
			"GoT",
			{
				{Music::Note::G4 ,	{500,0}},				{Music::Note::C4 ,	{500,0}},				{Music::Note::DS4,	{250,0}},				{Music::Note::F4 ,	{250,0}},
				{Music::Note::G4 ,	{500,0}},				{Music::Note::C4 ,	{500,0}},				{Music::Note::DS4,	{250,0}},				{Music::Note::F4 ,	{250,0}},
				{Music::Note::G4 ,	{500,0}},				{Music::Note::C4 ,	{500,0}},				{Music::Note::DS4,	{250,0}},				{Music::Note::F4 ,	{250,0}},
				{Music::Note::G4 ,	{500,0}},				{Music::Note::C4 ,	{500,0}},				{Music::Note::DS4,	{250,0}},				{Music::Note::F4 ,	{250,0}},
				{Music::Note::G4 ,	{500,0}},				{Music::Note::C4 ,	{500,0}},				{Music::Note::E4 ,	{250,0}},				{Music::Note::F4 ,	{250,0}},
				{Music::Note::G4 ,	{500,0}},				{Music::Note::C4 ,	{500,0}},				{Music::Note::E4 ,	{250,0}},				{Music::Note::F4 ,	{250,0}},
				{Music::Note::G4 ,	{500,0}},				{Music::Note::C4 ,	{500,0}},				{Music::Note::E4 ,	{250,0}},				{Music::Note::F4 ,	{250,0}},
				{Music::Note::G4 ,	{500,0}},				{Music::Note::C4 ,	{500,0}},				{Music::Note::E4 ,	{250,0}},				{Music::Note::F4 ,	{250,0}},
				{Music::Note::G4 ,	{500,0}},				{Music::Note::C4 ,	{500,0}},				{Music::Note::DS4,	{250,0}},				{Music::Note::F4 ,	{250,0}},
				{Music::Note::D4 ,	{500,0}},				{Music::Note::G3 ,	{500,0}},				{Music::Note::AS3,	{250,0}},				{Music::Note::C4 ,	{250,0}},
				{Music::Note::D4 ,	{500,0}},				{Music::Note::G3 ,	{500,0}},				{Music::Note::AS3,	{250,0}},				{Music::Note::C4 ,	{250,0}},
				{Music::Note::D4 ,	{500,0}},				{Music::Note::G3 ,	{500,0}},				{Music::Note::AS3,	{250,0}},				{Music::Note::C4 ,	{250,0}},
				{Music::Note::D4 ,	{500,0}},				{Music::Note::G3 ,	{500,0}},				{Music::Note::AS3,	{250,0}},				{Music::Note::C4 ,	{250,0}},
				{Music::Note::D4 ,	{1000,0}},				{Music::Note::F4 ,	{1000,0}},				{Music::Note::AS3,	{100,0}},				{Music::Note::DS4,	{250,0}},
				{Music::Note::D4 ,	{250,0}},				{Music::Note::F4 ,	{1000,0}},				{Music::Note::AS3,	{100,0}},				{Music::Note::DS4,	{250,0}},
				{Music::Note::D4 ,	{250,0}},				{Music::Note::C4 ,	{500,0}},				{Music::Note::GS3,	{250,0}},				{Music::Note::AS3,	{250,0}},
				{Music::Note::C4 ,	{500,0}},				{Music::Note::F3 ,	{500,0}},				{Music::Note::GS3,	{250,0}},				{Music::Note::AS3,	{250,0}},
				{Music::Note::C4 ,	{500,0}},				{Music::Note::F3 ,	{500,0}},				{Music::Note::GS3,	{250,0}},				{Music::Note::AS3,	{250,0}},
				{Music::Note::C4 ,	{500,0}},				{Music::Note::F3 ,	{500,0}},				{Music::Note::G4 ,	{1000,0}},				{Music::Note::C4 ,	{1000,0}},
				{Music::Note::DS4,	{250,0}},				{Music::Note::F4 ,	{250,0}},				{Music::Note::G4 ,	{1000,0}},				{Music::Note::C4 ,	{1000,0}},				
				{Music::Note::DS4,	{250,0}},				{Music::Note::F4 ,	{250,0}},				{Music::Note::D4 ,	{500,0}},				{Music::Note::G3 ,	{500,0}},				
				{Music::Note::AS3,	{250,0}},				{Music::Note::C4 ,	{250,0}},				{Music::Note::D4 ,	{500,0}},				{Music::Note::G3 ,	{500,0}},				
				{Music::Note::AS3,	{250,0}},				{Music::Note::C4 ,	{250,0}},				{Music::Note::D4 ,	{500,0}},				{Music::Note::G3 ,	{500,0}},				
				{Music::Note::AS3,	{250,0}},				{Music::Note::C4 ,	{250,0}},				{Music::Note::D4 ,	{500,0}},				{Music::Note::G3 ,	{500,0}},				
				{Music::Note::AS3,	{250,0}},				{Music::Note::C4 ,	{250,0}},				{Music::Note::D4 ,	{500,0}},
			}
		};
		inline static song ImperialMarch = 
		{
			"ImperialMarch",
			{
				{Music::Note::G4,	{350,100}},				{Music::Note::G4,	{350,100}},				{Music::Note::DS4,	{250,100}},				{Music::Note::BB4,	{75 ,100}},
				{Music::Note::G4,	{350,100}},				{Music::Note::DS4,	{250,100}},				{Music::Note::BB4,	{75 ,100}},				{Music::Note::G4,	{700,100}},
				{Music::Note::D5,	{350,100}},				{Music::Note::D5,	{350,100}},				{Music::Note::D5,	{350,100}},				{Music::Note::EB5,	{250,100}},
				{Music::Note::BB4,	{75 ,100}},				{Music::Note::GB4,	{350,100}},				{Music::Note::DS4,	{250,100}},				{Music::Note::BB4,	{75 ,100}},
				{Music::Note::G4,	{700,100}},				{Music::Note::G5,	{350,100}},				{Music::Note::G4,	{250,100}},				{Music::Note::G4,	{75 ,100}},
				{Music::Note::G5,	{350,100}},				{Music::Note::GB5,	{250,100}},				{Music::Note::F5,	{75 ,100}},				{Music::Note::E5,	{75 ,100}},
				{Music::Note::EB5,	{75 ,100}},				{Music::Note::E5,	{50 ,100}},				{Music::Note::AB4,	{75 ,400}},				{Music::Note::DB5,	{350,200}},
				{Music::Note::C5,	{250,100}},				{Music::Note::B4,	{75 ,100}},				{Music::Note::BB4,	{75 ,100}},				{Music::Note::A4,	{75 ,100}},
				{Music::Note::BB4,	{50 ,100}},				{Music::Note::DS4,	{75 ,400}},				{Music::Note::GB4,	{350,200}},				{Music::Note::DS4,	{250,100}},
				{Music::Note::G4,	{75 ,100}},				{Music::Note::BB4,	{350,100}},				{Music::Note::G4,	{250,100}},				{Music::Note::BB4,	{75 ,100}},
				{Music::Note::D5,	{700,100}},				{Music::Note::G5,	{350,100}},				{Music::Note::G4,	{250,100}},				{Music::Note::G4,	{75 ,100}},
				{Music::Note::G5,	{350,100}},				{Music::Note::GB5,	{250,100}},				{Music::Note::F5,	{75 ,100}},				{Music::Note::E5,	{75 ,100}},
				{Music::Note::EB5,	{75 ,100}},				{Music::Note::E5,	{50 ,100}},				{Music::Note::AB4,	{75 ,400}},				{Music::Note::DB5,	{350,200}},
				{Music::Note::C5,	{250,100}},				{Music::Note::B4,	{75 ,100}},				{Music::Note::BB4,	{75 ,100}},				{Music::Note::A4,	{75 ,100}},
				{Music::Note::BB4,	{50 ,100}},				{Music::Note::DS4,	{75 ,400}},				{Music::Note::G4,	{350,200}},				{Music::Note::DS4,	{250,100}},
				{Music::Note::BB4,	{75 ,100}},				{Music::Note::G4,	{300,100}},				{Music::Note::DS4,	{250,150}},				{Music::Note::BB4,	{75 ,100}},
				{Music::Note::G4,	{700,100}},
			}
		};
		inline static song SovietAnthem =
		{
			"Soviet Anthem",
			{
				{Music::Note::G4 , {375 ,0}},				{Music::Note::C5 , {750 ,0}},				{Music::Note::G4 , {463 ,0}},				{Music::Note::A4 , {187 ,0}},
				{Music::Note::B4 , {750 ,0}},				{Music::Note::E4 , {375 ,0}},				{Music::Note::E4 , {375 ,0}},				{Music::Note::A4 , {750 ,0}},
				{Music::Note::G4 , {463 ,0}},				{Music::Note::F4 , {187 ,0}},				{Music::Note::G4 , {750 ,0}},				{Music::Note::C4 , {463 ,0}},
				{Music::Note::C4 , {187 ,0}},				{Music::Note::D4 , {750 ,0}},				{Music::Note::D4 , {463 ,0}},				{Music::Note::E4 , {187 ,0}},
				{Music::Note::F4 , {750 ,0}},				{Music::Note::F4 , {463 ,0}},				{Music::Note::G4 , {187 ,0}},				{Music::Note::A4 , {750 ,0}},
				{Music::Note::B4 , {375 ,0}},				{Music::Note::C5 , {375 ,0}},				{Music::Note::D5 , {1125,0}},
			}
		};
		inline static song OdeToJoy =
		{
			"Ode to Joy",
			{
				{Music::Note::GB4, {250,0}},				{Music::Note::GB4, {250,0}},				{Music::Note::G4,  {250,0}},				{Music::Note::A4,  {250,0}},		
				{Music::Note::A4,  {250,0}},				{Music::Note::G4,  {250,0}},				{Music::Note::GB4, {250,0}},				{Music::Note::E4,  {250,0}},
				{Music::Note::D4,  {250,0}},				{Music::Note::D4,  {250,0}},				{Music::Note::E4,  {250,0}},				{Music::Note::GB4, {250,0}},
				{Music::Note::GB4, {375,0}},				{Music::Note::E4,  {125,0}},				{Music::Note::E4,  {500,0}},				{Music::Note::GB4, {250,0}},
				{Music::Note::GB4, {250,0}},				{Music::Note::G4,  {250,0}},				{Music::Note::A4,  {250,0}},				{Music::Note::A4,  {250,0}},
				{Music::Note::G4,  {250,0}},				{Music::Note::GB4, {250,0}},				{Music::Note::E4,  {250,0}},				{Music::Note::D4,  {250,0}},
				{Music::Note::D4,  {250,0}},				{Music::Note::E4,  {250,0}},				{Music::Note::GB4, {250,0}},				{Music::Note::E4,  {375,0}},
				{Music::Note::D4,  {125,0}},				{Music::Note::D4,  {500,0}},				{Music::Note::E4,  {250,0}},				{Music::Note::E4,  {250,0}},
				{Music::Note::GB4, {250,0}},				{Music::Note::D4,  {250,0}},				{Music::Note::E4,  {250,0}},				{Music::Note::GB4, {125,0}},
				{Music::Note::G4,  {125,0}},				{Music::Note::GB4, {250,0}},				{Music::Note::D4,  {250,0}},				{Music::Note::E4,  {250,0}},
				{Music::Note::GB4, {125,0}},				{Music::Note::G4,  {125,0}},				{Music::Note::GB4, {250,0}},				{Music::Note::E4,  {250,0}},
				{Music::Note::D4,  {250,0}},				{Music::Note::E4,  {250,0}},				{Music::Note::A3,  {250,0}},
			}								
		};
	#pragma endregion
	};

	static void Beep(Music::song song) noexcept;
};

#endif // !__MUSIC_BEEPER_HPP__