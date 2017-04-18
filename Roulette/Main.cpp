#include <iostream>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <ctime>

using namespace std;
class Money { //класс Money для рандомизации денег в начале игры и их вывода
	int money;
public:
	Money(); //конструктор
	Money(int Money) { //конструктор с одним параметром (Зачем? Не знаю)
		money = 0;
		setRandMoney(); //устанавливаем деньги (Зачем ввожу число тоже не знаю)
	}
	void setMoney(int aMoney) { //функция установки денег
		money = aMoney;
	}
	void setRandMoney()
	{
		srand(time(NULL));
		money = rand() % 200 + 50; //генератор случайных чисел в диапазоне от 50 до 200 включительно
								   //в переменную money (которая находится в protected класса Roulette(уже нет)) записываем значение генератора
	}
	int getMoney() { //функция возврата денег
		return money;
	}
};

class Roulette { //класс Roulette (главный класс, поидее)
private:
	int rate; //ставка
	int number; //число
	int res; //запись результата
public:
	Roulette(); //конструктор
	Roulette(int Rate, int Number) { // конструктор  с параметрами
		setRate(Rate); // устанавливаем ставку
		setNumber(Number); //устанавливаем число
	}
	void setRate(int Rate) { //функция установки ставки
		rate = Rate;
	}
	void setNumber(int Number) { //функция установки числа
		number = Number;
	}
	int getRate() { //функция возврата ставки
		return rate;
	}
	int getNumber() { //функция возврата числа
		return number;
	}
	int spin() { //генератор случайных чисел
		int i = rand() % 36; //диапазон генератора от 0 до 36 включительно
		return i; //статическое значение 15 для проверки
	}
	void game(Money *money) {
		srand(time(NULL));
		money->setMoney((money->getMoney()) - rate); //отнимаем от денег нашу ставку

		if (spin() == number) { //если генератор = нашему числу, то
			res = rate*number; //ставка умножается на число и записывается в res
		}
		else {
			res = 0; //если наоборот, то res = 0
		}
		money->setMoney((money->getMoney()) + res);  //к деньгам добавляется res
	}
	void show(Money money) {
		cout << endl;
		cout << "------------------" << endl;
		cout << "Ставка:" << getRate() << " Число:" << getNumber() << endl; //выводит: ставка, число
		cout << "Выпало:" << spin() << endl; //выводит: генератор случайных чисел
		cout << "Деньги:" << money.getMoney() << endl; //выводит: деньги
		cout << "------------------" << endl;
		cout << endl;
		system("pause");
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	Money mon(0); //вызов конструктора класса Money с параметром (Не важно какой, но если конструктор без параметра, то getMoney начинает не работать)
	int a, b; //переменные для ставки и числа
	while (true) {
		if (mon.getMoney() <= 0) { //если деньги меньше или равны 0 то
			cout << "Игра закончена!\n" << endl; //прекратить игру
			system("pause");
			return 0; //не знаю как ещё выйти, break разве что, но тогда в конец программы опять return 0 нужен
		}
		else {
			cout << "Ваши деньги: " << mon.getMoney() << endl;
			cout << "Введите ставку: " << endl;
			cin >> a; //ввод ставки
			cout << "Введите число (0-36): " << endl;
			cin >> b; //ввод числа
			Roulette roul(a, b);//вызов конструктора класса Roulette с параметрами
			roul.game(&mon); //продолжить игру
			roul.show(mon); //вывести значения на экран
			system("CLS");
		}
	}
}