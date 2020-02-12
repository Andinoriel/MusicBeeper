#include "MusicBeeper.hpp"

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
	for (Music::song_note& song_note : song.second)
	{
	#ifdef __linux__ 
			fprintf(stderr, "\033[10;%d]\033[11;%d]\a", static_cast<size_t>(song_note.first), song_note.second.first);
			usleep(song_note.second.second);
	#elif _WIN32			
			::Beep(static_cast<size_t>(song_note.first), song_note.second.first);
			::Sleep(song_note.second.second);
	#endif
	};
};