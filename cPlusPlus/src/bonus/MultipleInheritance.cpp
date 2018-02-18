#include "MultipleInheritance.h"

class MusicalInstrument
{
public:
	virtual void play() { cout << "Playing instrument ..." << endl; } // unique to MusicalInstrument
	virtual void reset() { cout << "Resetting instrument ..." << endl; } // both MusicalInstrument and Machine
	virtual ~MusicalInstrument() {};
};

class Machine
{
public:
	virtual void start() { cout << "Starting machine ..." << endl; } // unique to Machine
	virtual void reset() { cout << "Resetting machine ..." << endl; } // both MusicalInstrument and Machine
	virtual ~Machine() {};
};

class Synthesizer : public Machine, public MusicalInstrument
{
public:
	virtual ~Synthesizer() {};
};

void runMultipleInheritance()
{
	// best to avoid, but useful to know for interviews

	Synthesizer *pSynth = new Synthesizer();

	pSynth->play(); // unique to MusicalInstrument
	pSynth->start(); // unique to Machine
	// both MusicalInstrument and Machine - need to specify scope
	pSynth->Machine::reset();
	pSynth->MusicalInstrument::reset();

	// this requires you to know how synthesizer is implemented
	// but we want to hide away or encapsulate the implementation.
	// User shouldn't have to know super classes
	// Called the "Diamond problem" of resolving ambiguous methods

	delete pSynth;
}