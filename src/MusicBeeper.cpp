#include "MusicBeeper.hpp"

#ifdef __linux__ 
[[noreturn]] void __ctrl_c_break_handle(sig_atomic_t)
{
	input_event __empty_ie = {timeval({0x0, 0x0}), __EV_SND, __SND_TONE, 0x0};
	int fd = open("/dev/input/by-path/platform-pcspkr-event-spkr", O_WRONLY);
	write(fd, reinterpret_cast<void*>(&__empty_ie), sizeof(__empty_ie));
	close(fd);
	std::exit(0);
};
#endif

void MusicBeeper::BeepGoT(void) noexcept
{
	Beep(Music::GoT);
};
void MusicBeeper::BeepImperialMarch(void) noexcept
{
	Beep(Music::ImperialMarch);
};
void MusicBeeper::BeepSovietAnthem(void) noexcept
{
	Beep(Music::SovietAnthem);
};
void MusicBeeper::BeepOdeToJoy(void) noexcept
{
	Beep(Music::OdeToJoy);
};


void MusicBeeper::Beep(Music::song song) noexcept
{
	#ifdef __linux__
		int fd = open("/dev/input/by-path/platform-pcspkr-event-spkr", O_WRONLY);	
		auto __uni_linux_beep = [=](size_t frequency, size_t duration_milliseconds)
		{
			float fsec, sec;
			fsec = std::modf(time(NULL), &sec);

			input_event ie = 
			{
				timeval({static_cast<time_t>(sec), static_cast<suseconds_t>(fsec * 1000000)}),
				__EV_SND,
				__SND_TONE,
				static_cast<std::int32_t>(frequency)
			};

			// beep
			write(fd, reinterpret_cast<void*>(&ie), sizeof(ie));
			usleep(duration_milliseconds * 1000);
			ie.value = 0;
			write(fd, reinterpret_cast<void*>(&ie), sizeof(ie));
		};

		#define CLOSE_FD_IF_EXISTS close(fd);
	#elif _WIN32
		#define CLOSE_FD_IF_EXISTS
	#endif

	// beep
	for (Music::song_note& song_note : song.second)
	{
	#ifdef __linux__
		__uni_linux_beep(static_cast<size_t>(song_note.first), song_note.second.first);
		usleep(song_note.second.second * 1000);
	#elif _WIN32			
		::Beep(static_cast<size_t>(song_note.first), song_note.second.first);
		::Sleep(song_note.second.second);
	#endif
	};

	CLOSE_FD_IF_EXISTS;
};