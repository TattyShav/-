#pragma once
#include "Pair.h"
class Series
{
	Series();
	~Series();
public:

	struct Den {
		int rub = rub;
		int kop = kop;
		Den *next; // Следующее число
		Den *prev; // Предыдущее число
	};

	struct Komp {
		int dev = dev;
		int mnim = mnim;
		Komp *next; // Следующее число
		Komp *prev; // Предыдущее число
	};
};