#include "MusicBeeper.hpp"

void MusicBeeper::BeepGoT(void) noexcept
{
	for (size_t t = 0; t < Music::GoT.second.size(); ++t)
	{
		Beeper::Beep(static_cast<size_t>(Music::GoT.second.at(t).first), Music::GoT.second.at(t).second.first);
		#ifdef __linux__ 
			// usleep(Music::GoT.second.at(t).second.second);
		#elif _WIN32
			//::Sleep(Music::GoT.second.at(t).second.second);
		#endif
	};
};
void MusicBeeper::BeepImperialMarch(void) noexcept
{
	for (size_t t = 0; t < Music::ImperialMarch.second.size(); ++t)
	{
		Beeper::Beep(static_cast<size_t>(Music::ImperialMarch.second.at(t).first), Music::ImperialMarch.second.at(t).second.first);
		#ifdef __linux__ 
			// usleep(Music::ImperialMarch.second.at(t).second.second);
		#elif _WIN32
			//::Sleep(Music::ImperialMarch.second.at(t).second.second);
		#endif
	};
};

void MusicBeeper::Beeper::Beep(size_t frequency, size_t time) noexcept
{
#ifdef __linux__ 
	fprintf(stderr,"\033[10;%d]\033[11;%d]\a", frequency, time);
#elif _WIN32
	::Beep(frequency, time);
#endif
};
MusicBeeper::Music::song MusicBeeper::Music::GoT =
{
	"GoT",
	{
		{Music::Note::G4 ,	{500,0}},
		{Music::Note::C4 ,	{500,0}},
		{Music::Note::DS4,	{250,0}},
		{Music::Note::F4 ,	{250,0}},
		{Music::Note::G4 ,	{500,0}},
		{Music::Note::C4 ,	{500,0}},
		{Music::Note::DS4,	{250,0}},
		{Music::Note::F4 ,	{250,0}},
		{Music::Note::G4 ,	{500,0}},
		{Music::Note::C4 ,	{500,0}},
		{Music::Note::DS4,	{250,0}},
		{Music::Note::F4 ,	{250,0}},
		{Music::Note::G4 ,	{500,0}},
		{Music::Note::C4 ,	{500,0}},
		{Music::Note::DS4,	{250,0}},
		{Music::Note::F4 ,	{250,0}},
		{Music::Note::G4 ,	{500,0}},
		{Music::Note::C4 ,	{500,0}},
		{Music::Note::E4 ,	{250,0}},
		{Music::Note::F4 ,	{250,0}},
		{Music::Note::G4 ,	{500,0}},
		{Music::Note::C4 ,	{500,0}},
		{Music::Note::E4 ,	{250,0}},
		{Music::Note::F4 ,	{250,0}},
		{Music::Note::G4 ,	{500,0}},
		{Music::Note::C4 ,	{500,0}},
		{Music::Note::E4 ,	{250,0}},
		{Music::Note::F4 ,	{250,0}},
		{Music::Note::G4 ,	{500,0}},
		{Music::Note::C4 ,	{500,0}},
		{Music::Note::E4 ,	{250,0}},
		{Music::Note::F4 ,	{250,0}},
		{Music::Note::G4 ,	{500,0}},
		{Music::Note::C4 ,	{500,0}},
		{Music::Note::DS4,	{250,0}},
		{Music::Note::F4 ,	{250,0}},
		{Music::Note::D4 ,	{500,0}},
		{Music::Note::G3 ,	{500,0}},
		{Music::Note::AS3,	{250,0}},
		{Music::Note::C4 ,	{250,0}},
		{Music::Note::D4 ,	{500,0}},
		{Music::Note::G3 ,	{500,0}},
		{Music::Note::AS3,	{250,0}},
		{Music::Note::C4 ,	{250,0}},
		{Music::Note::D4 ,	{500,0}},
		{Music::Note::G3 ,	{500,0}},
		{Music::Note::AS3,	{250,0}},
		{Music::Note::C4 ,	{250,0}},
		{Music::Note::D4 ,	{500,0}},
		{Music::Note::G3 ,	{500,0}},
		{Music::Note::AS3,	{250,0}},
		{Music::Note::C4 ,	{250,0}},
		{Music::Note::D4 ,	{1000,0}},
		{Music::Note::F4 ,	{1000,0}},
		{Music::Note::AS3,	{100,0}},
		{Music::Note::DS4,	{250,0}},
		{Music::Note::D4 ,	{250,0}},
		{Music::Note::F4 ,	{1000,0}},
		{Music::Note::AS3,	{100,0}},
		{Music::Note::DS4,	{250,0}},
		{Music::Note::D4 ,	{250,0}},
		{Music::Note::C4 ,	{500,0}},
		{Music::Note::GS3,	{250,0}},
		{Music::Note::AS3,	{250,0}},
		{Music::Note::C4 ,	{500,0}},
		{Music::Note::F3 ,	{500,0}},
		{Music::Note::GS3,	{250,0}},
		{Music::Note::AS3,	{250,0}},
		{Music::Note::C4 ,	{500,0}},
		{Music::Note::F3 ,	{500,0}},
		{Music::Note::GS3,	{250,0}},
		{Music::Note::AS3,	{250,0}},
		{Music::Note::C4 ,	{500,0}},
		{Music::Note::F3 ,	{500,0}},
		{Music::Note::G4 ,	{1000,0}},
		{Music::Note::C4 ,	{1000,0}},
		{Music::Note::DS4,	{250,0}},
		{Music::Note::F4 ,	{250,0}},
		{Music::Note::G4 ,	{1000,0}},
		{Music::Note::C4 ,	{1000,0}},
		{Music::Note::DS4,	{250,0}},
		{Music::Note::F4 ,	{250,0}},
		{Music::Note::D4 ,	{500,0}},
		{Music::Note::G3 ,	{500,0}},
		{Music::Note::AS3,	{250,0}},
		{Music::Note::C4 ,	{250,0}},
		{Music::Note::D4 ,	{500,0}},
		{Music::Note::G3 ,	{500,0}},
		{Music::Note::AS3,	{250,0}},
		{Music::Note::C4 ,	{250,0}},
		{Music::Note::D4 ,	{500,0}},
		{Music::Note::G3 ,	{500,0}},
		{Music::Note::AS3,	{250,0}},
		{Music::Note::C4 ,	{250,0}},
		{Music::Note::D4 ,	{500,0}},
		{Music::Note::G3 ,	{500,0}},
		{Music::Note::AS3,	{250,0}},
		{Music::Note::C4 ,	{250,0}},
		{Music::Note::D4 ,	{500,0}},
	}
};
MusicBeeper::Music::song MusicBeeper::Music::ImperialMarch =
{
	"ImperialMarch",
	{
		{Music::Note::G4,	{350,100}},
		{Music::Note::G4,	{350,100}},
		{Music::Note::DS4,	{250,100}},
		{Music::Note::BB4,	{75 ,100}},
		{Music::Note::G4,	{350,100}},
		{Music::Note::DS4,	{250,100}},
		{Music::Note::BB4,	{75 ,100}},
		{Music::Note::G4,	{700,100}},
		{Music::Note::D5,	{350,100}},
		{Music::Note::D5,	{350,100}},
		{Music::Note::D5,	{350,100}},
		{Music::Note::EB5,	{250,100}},
		{Music::Note::BB4,	{75 ,100}},
		{Music::Note::GB4,	{350,100}},
		{Music::Note::DS4,	{250,100}},
		{Music::Note::BB4,	{75 ,100}},
		{Music::Note::G4,	{700,100}},
		{Music::Note::G5,	{350,100}},
		{Music::Note::G4,	{250,100}},
		{Music::Note::G4,	{75 ,100}},
		{Music::Note::G5,	{350,100}},
		{Music::Note::GB5,	{250,100}},
		{Music::Note::F5,	{75 ,100}},
		{Music::Note::E5,	{75 ,100}},
		{Music::Note::EB5,	{75 ,100}},
		{Music::Note::E5,	{50 ,100}},
		{Music::Note::AB4,	{75 ,400}},
		{Music::Note::DB5,	{350,200}},
		{Music::Note::C5,	{250,100}},
		{Music::Note::B4,	{75 ,100}},
		{Music::Note::BB4,	{75 ,100}},
		{Music::Note::A4,	{75 ,100}},
		{Music::Note::BB4,	{50 ,100}},
		{Music::Note::DS4,	{75 ,400}},
		{Music::Note::GB4,	{350,200}},
		{Music::Note::DS4,	{250,100}},
		{Music::Note::G4,	{75 ,100}},
		{Music::Note::BB4,	{350,100}},
		{Music::Note::G4,	{250,100}},
		{Music::Note::BB4,	{75 ,100}},
		{Music::Note::D5,	{700,100}},
		{Music::Note::G5,	{350,100}},
		{Music::Note::G4,	{250,100}},
		{Music::Note::G4,	{75 ,100}},
		{Music::Note::G5,	{350,100}},
		{Music::Note::GB5,	{250,100}},
		{Music::Note::F5,	{75 ,100}},
		{Music::Note::E5,	{75 ,100}},
		{Music::Note::EB5,	{75 ,100}},
		{Music::Note::E5,	{50 ,100}},
		{Music::Note::AB4,	{75 ,400}},
		{Music::Note::DB5,	{350,200}},
		{Music::Note::C5,	{250,100}},
		{Music::Note::B4,	{75 ,100}},
		{Music::Note::BB4,	{75 ,100}},
		{Music::Note::A4,	{75 ,100}},
		{Music::Note::BB4,	{50 ,100}},
		{Music::Note::DS4,	{75 ,400}},
		{Music::Note::G4,	{350,200}},
		{Music::Note::DS4,	{250,100}},
		{Music::Note::BB4,	{75 ,100}},
		{Music::Note::G4,	{300,100}},
		{Music::Note::DS4,	{250,150}},
		{Music::Note::BB4,	{75 ,100}},
		{Music::Note::G4,	{700,100}},
	}
};