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
		Den *next; // ��������� �����
		Den *prev; // ���������� �����
	};

	struct Komp {
		int dev = dev;
		int mnim = mnim;
		Komp *next; // ��������� �����
		Komp *prev; // ���������� �����
	};
};