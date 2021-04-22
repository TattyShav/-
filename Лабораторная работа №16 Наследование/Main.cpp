#include <iostream> // Описания используемых в программе элементов стандартной библиотеки ввода-вывода
#include <clocale>// Стандартный заголовочный файл для функции setlocale
#include "Money.h"
#include "Complex.h"
#include "Series.h"

using namespace std; // Пространство имён

int main() {// Заголовок гавной функции
	setlocale(LC_ALL, "Russian"); // Оператор, устанавливающий русскую локаль
	int e, h, x, y, x1, y1;
	Series::Den*begin = nullptr;
	Series::Komp*cur = nullptr;	
	do {
		cout << "Выберите действие: " << endl;
		cout << "1. Заполнить список денежных элементов " << endl;
		cout << "2. Заполнить список  комплекстных чисел " << endl;
		cout << "3. Вставка комплексного числа " << endl;
		cout << "4. Вставка денежного элемента " << endl;
		cout << "5. Удаление из списка комплекстных чисел " << endl;
		cout << "6. Удаление из списка денежных элементов " << endl;
		cout << "7. Вывод денежных элементов " << endl;
		cout << "8. Вывод комплексных чисел " << endl;
		cin >> e;
		cout << endl;
		Money money;
		Complex complex;
		switch (e)
		{
		case 1: {
			cout << "Введите колиество элементов" << endl;
			cin >> h;
			cout << endl;
			for (int i = 0; i < h; i++) {
				cout << "rub ";
				cin >> x;
				cout << "kop ";
				cin >> y;
				money.add(begin, x, y);

			}
			money.print(begin);
		} break;
		case 2: {
			cout << "Введите колиество элементов" << endl;
			cin >> h;
			cout << endl;
			for (int i = 0; i < h; i++) {
				cout << "dev ";
				cin >> x;
				cout << " mnin ";
				cin >> y;
				complex.add(cur, x, y);
			}
			complex.print(cur);

		} break;
		case 3: {
			cout << "Введите комплекстное число после которого хотите вставить нового" << endl;
			cin >> x;
			cin >> y;
			cout << "ВВедите комплекстное число, которое хотите вставить: " << endl;
			cin >> x1;
			cin >> y1;
			complex.insert(cur, x, y, x1, y1);
			cout << '\n';
			complex.print(cur);

		} break;
		case 4: {
			cout << "Введите денежный элемент после которого хотите вставить новый" << endl;
			cin >> x;
			cin >> y;
			cout << "ВВедите денежны элемент, которое хотите вставить: " << endl;
			cin >> x1;
			cin >> y1;
			money.insert(begin, x, y, x1, y1);
			cout << '\n';
			money.print(begin);
		}break;
		case 5: {
			cout << "ВВедите комплекстное число, которое хотите удалить: " << endl;
			cin >> x;
			cin >> y;
			complex.remove(cur, x, y);
			cout << '\n';
			complex.print(cur);
		} break;
		case 6: {
			cout << "ВВедите денежный элемент, которое хотите удалить: " << endl;
			cin >> x;
			cin >> y;
			money.remove(begin, x, y);
			cout << '\n';
			money.print(begin);
		} break;
		case 7: {
			cout << "Денежные элементы: " << endl;
			money.print(begin);
		} break;
		case 8: {
			cout << "Комплекстные числа: " << endl;
			complex.print(cur);
		} break;
		default:cout << "Нужно нажать клавишу от 1 до 8 " << endl;
			break;
		}
	} while (e != 9);
	system("Pause"); // Команда, которая ждёт любого ввода, чтобы консольное окно, которое не сразу закрывалось
	return 0; // Конец текущей функции

}