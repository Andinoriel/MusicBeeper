#pragma once
#ifndef __MUSIC_BEEPER_HPP__
#define __MUSIC_BEEPER_HPP__

#include <vector>
#include <string>
#include <functional>

#include "Song.hpp"

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
	MusicBeeper(void) = delete;
	~MusicBeeper(void) = delete;

	static void BeepGoT(void) noexcept;
	static void BeepImperialMarch(void) noexcept;
	static void BeepSovietAnthem(void) noexcept;
	static void BeepOdeToJoy(void) noexcept;
private:
	static void Beep(Music::song song) noexcept;
};

#endif // !__MUSIC_BEEPER_HPP__