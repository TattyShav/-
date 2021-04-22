#pragma once
#include <iostream>
#include "Pair.h"
#include "Series.h"

using namespace std;

class Complex
{
public:
	Complex();
	~Complex();
public:
	Series::Komp * find(Series::Komp* begin, int x, int y) {
		Series::Komp*cur = begin;
		while (cur) {
			if ((cur->dev == x) and (cur->mnim == y))
				break;
			cur = cur->next;
		}
		return cur;
	}

	// Вставка элемента после заданного
	bool insert(Series::Komp * begin, int x, int y, int x1, int y1) {
		Series::Komp*pkey = find(begin, x, y);
		if (!pkey) return false;
		Series::Komp*cur = new Series::Komp;
		cur->dev = x1;
		cur->mnim = y1;
		// 1 - установление связи нового узла с последующим:
		cur->next = pkey->next;
		// 2 - установление связи нового узла с предыдущим:
		cur->prev = pkey;
		// 3 - установление связи предыдущего узла с новым:
		pkey->next = cur;
		// 4 - установление связи последующего узла с новым:
		if (cur->next != nullptr) (cur->next)->prev = cur;
		return true;
	}
	// Удаление элемента
	bool remove(Series::Komp*&begin, int x, int y) {
		Series::Komp*cur = find(begin, x, y); // Выделение памяти под локальный указатель cur, которому присваивается результат выполнения функции find 
		// (функция находения элемента по ключу)
		// Функция find возвращает указатель на элемент в случае успешного поиска и nullptr, если элемента с таким ключом в списке нет 
		// (в этом случае удалять нечего, и выполняется выход из функции remove со значением false)
		if (!cur) return false;
		// Если элемент находитс в начале списка, то указатель begin на начало списка сдвигается на следующий элемент
		if (cur == begin) {
			begin = begin->next; // Адрес которого находится в поле next первого элемента
			begin->prev = nullptr; // Новый начальный элемент списка должен иметь в своем поле указателя на предыдущий элемент nullptr
		}
		else { // Если удаление происходит из середины списка, обеспечиваем двусторонюю свзь предыдущего и последующего элементов
			(cur->prev)->next = cur->next;
			if (cur->next != nullptr) (cur->next)->prev = cur->prev; // Проверка условия, обработка особого случая удаления последнего элемента списка
		}
		delete cur; // Освобождение памяти из-под элемента 
		return true; // Функция возвращает значение true
	}

	// Вывод обратного списка на экран
	void printend(Series::Komp *Komp)
	{
		if (Komp) {
			printend(Komp->next);
			cout << Komp->dev << " ";
			if (Komp->mnim > 0)
				cout << "+";
			else cout << "-";
			cout << Komp->mnim << "i " << endl;
			Komp = Komp->next; // Пока последний не будет следующим, выводим
		}
	}
	void add(Series::Komp *&begin, int x, int y) { // *& ссылка на указатель
		Series::Komp *cur = new Series::Komp;
		cur->dev = x;
		cur->mnim = y;// -> показывает часть ячейки в которую нам надо попасть
		cur->next = nullptr; // Следующего не существует
		if (!begin) { begin = cur; cur->prev = nullptr; } // begin - первое значение, доходит до первого знаения и говорит, что там пусто
		else {
			Series::Komp * temp = begin; // следующее делает предыдущим, предыдущее - следующим
			while ((temp->next))
				temp = temp->next;
			temp->next = cur;
			cur->prev = temp;
		}
	}
	//Вывод списка на экран
	void print(Series::Komp * begin) {
		Series::Komp* cur = begin;
		while (cur) {
			cout << cur->dev << " ";
			if (cur->mnim > 0)
				cout << "+";
			cout << cur->mnim << "i " << endl;
			cur = cur->next;
		}
	}
};
