#pragma once
#include <iostream>
#include "Pair.h"
#include "Series.h"

using namespace std;

class Money
{
public:
	Money();
	~Money();
public:
	Series::Den * find(Series::Den* begin, int x, int y) {
		Series::Den*cur = begin;
		while (cur) {
			if ((cur->rub == x) and (cur->kop == y))
				break;
			cur = cur->next;
		}
		return cur;
	}

	// ������� �������� ����� ���������
	bool insert(Series::Den * begin, int x, int y, int x1, int y1) {
		Series::Den*pkey = find(begin, x, y);
		if (!pkey) return false;
		Series::Den*cur = new Series::Den;
		cur->rub = x1;
		cur->kop = y1;
		// 1 - ������������ ����� ������ ���� � �����������:
		cur->next = pkey->next;
		// 2 - ������������ ����� ������ ���� � ����������:
		cur->prev = pkey;
		// 3 - ������������ ����� ����������� ���� � �����:
		pkey->next = cur;
		// 4 - ������������ ����� ������������ ���� � �����:
		if (cur->next != nullptr) (cur->next)->prev = cur;
		return true;
	}
	// �������� ��������
	bool remove(Series::Den*&begin, int x, int y) {
		Series::Den*cur = find(begin, x, y); // ��������� ������ ��� ��������� ��������� cur, �������� ������������� ��������� ���������� ������� find 
		// (������� ��������� �������� �� �����)
		// ������� find ���������� ��������� �� ������� � ������ ��������� ������ � nullptr, ���� �������� � ����� ������ � ������ ��� 
		// (� ���� ������ ������� ������, � ����������� ����� �� ������� remove �� ��������� false)
		if (!cur) return false;
		// ���� ������� �������� � ������ ������, �� ��������� begin �� ������ ������ ���������� �� ��������� �������
		if (cur == begin) {
			begin = begin->next; // ����� �������� ��������� � ���� next ������� ��������
			begin->prev = nullptr; // ����� ��������� ������� ������ ������ ����� � ����� ���� ��������� �� ���������� ������� nullptr
		}
		else { // ���� �������� ���������� �� �������� ������, ������������ ����������� ���� ����������� � ������������ ���������
			(cur->prev)->next = cur->next;
			if (cur->next != nullptr) (cur->next)->prev = cur->prev; // �������� �������, ��������� ������� ������ �������� ���������� �������� ������
		}
		delete cur; // ������������ ������ ��-��� �������� 
		return true; // ������� ���������� �������� true
	}

	// ����� ��������� ������ �� �����
	void printend(Series::Den *Den)
	{
		if (Den) {
			printend(Den->next);
			cout << Den->rub << " ";
			cout << Den->kop << " " << endl;
			Den = Den->next; // ���� ��������� �� ����� ���������, �������
		}
	}
	void add(Series::Den *&begin, int x, int y) { // *& ������ �� ���������
		Series::Den *cur = new Series::Den;
		cur->rub = x;
		cur->kop = y;// -> ���������� ����� ������ � ������� ��� ���� �������
		cur->next = nullptr; // ���������� �� ����������
		if (!begin) { begin = cur; cur->prev = nullptr; } // begin - ������ ��������, ������� �� ������� ������� � �������, ��� ��� �����
		else {
			Series::Den * temp = begin; // ��������� ������ ����������, ���������� - ���������
			while ((temp->next))
				temp = temp->next;
			temp->next = cur;
			cur->prev = temp;
		}
	}
	//����� ������ �� �����
	void print(Series::Den * begin) {
		Series::Den* cur = begin;
		while (cur) {
			cout << cur->rub << " rub. ";
			cout << cur->kop << " kop. " << endl;
			cur = cur->next;
		}
	}
};