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

	// Вставка элемента после заданного
	bool insert(Series::Den * begin, int x, int y, int x1, int y1) {
		Series::Den*pkey = find(begin, x, y);
		if (!pkey) return false;
		Series::Den*cur = new Series::Den;
		cur->rub = x1;
		cur->kop = y1;
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
	bool remove(Series::Den*&begin, int x, int y) {
		Series::Den*cur = find(begin, x, y); // Выделение памяти под локальный указатель cur, которому присваивается результат выполнения функции find 
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
	void printend(Series::Den *Den)
	{
		if (Den) {
			printend(Den->next);
			cout << Den->rub << " ";
			cout << Den->kop << " " << endl;
			Den = Den->next; // Пока последний не будет следующим, выводим
		}
	}
	void add(Series::Den *&begin, int x, int y) { // *& ссылка на указатель
		Series::Den *cur = new Series::Den;
		cur->rub = x;
		cur->kop = y;// -> показывает часть ячейки в которую нам надо попасть
		cur->next = nullptr; // Следующего не существует
		if (!begin) { begin = cur; cur->prev = nullptr; } // begin - первое значение, доходит до первого знаения и говорит, что там пусто
		else {
			Series::Den * temp = begin; // следующее делает предыдущим, предыдущее - следующим
			while ((temp->next))
				temp = temp->next;
			temp->next = cur;
			cur->prev = temp;
		}
	}
	//Вывод списка на экран
	void print(Series::Den * begin) {
		Series::Den* cur = begin;
		while (cur) {
			cout << cur->rub << " rub. ";
			cout << cur->kop << " kop. " << endl;
			cur = cur->next;
		}
	}
};