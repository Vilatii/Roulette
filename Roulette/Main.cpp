#include <iostream>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <ctime>

using namespace std;
int money = 0; //глобальна€ переменна€ money, если запихнуть в любой класс, то пойдут кракоз€бры, а оно нам не надо

class Roulette { //класс Roulette (главный класс, поидее)
private:
	int rate; //ставка
	int number; //число
	int res; //запись результата
public:
	Roulette() {
	}; //конструктор
	Roulette(int Rate, int Number) { // конструктор  с параметрами
		setRate(Rate); // устанавливаем ставку
		setNumber(Number); //устанавливаем число
	}
	void setRate(int Rate) { //функци€ установки ставки
		rate = Rate;
	}
	void setNumber(int Number) { //функци€ установки числа
		number = Number;
	}
	int getRate() { //функци€ возврата ставки
		return rate;
	}
	int getNumber() { //функци€ возврата числа
		return number;
	}
	int spin() { //генератор случайных чисел
		int i = rand() % 36; //диапазон генератора от 0 до 36 включительно
		return i; //статическое значение 15 дл€ проверки
	}
	void game() {
		srand(time(NULL));
		money = money - rate; //отнимаем от денег нашу ставку
		if (spin() == number) { //если генератор = нашему числу, то
			res = rate*number; //ставка умножаетс€ на число и записываетс€ в res
		}
		else {
			res = 0; //если наоборот, то res = 0
		}
		money = money + res;  //к деньгам добавл€етс€ res
	}
	void show() {
		cout << endl;
		cout << "------------------" << endl;
		cout << "Stavka:" << getRate() << " Chislo:" << getNumber() << endl; //выводит: ставка, число
		cout << "Vipalo:" << spin() << endl; //выводит: генератор случайных чисел
		cout << "Dengi:" << money << endl; //выводит: деньги
		cout << "------------------" << endl;
		cout << endl;
		system("pause");
	}
};

class Money { //класс Money дл€ рандомизации денег в начале игры и их вывода
public:
	Money(); //конструктор
	Money(int Money) { //конструктор с одним параметром («ачем? Ќе знаю)
		setMoney(Money); //устанавливаем деньги («ачем ввожу число тоже не знаю)
	}
	void setMoney(int Money) { //функци€ установки денег
		srand(time(NULL));
		Money = rand() % 200 +50; //генератор случайных чисел в диапазоне от 50 до 200 включительно
		money = Money; //в переменную money (котора€ находитс€ в protected класса Roulette) записываем значение генератора
	}
	int getMoney() { //функци€ возврата денег
		return money;
	}
};


int main() {
	Money mon(0); //вызов конструктора класса Money с параметром (Ќе важно какой, но если конструктор без параметра, то getMoney начинает не работать)
	cout << "Vashi dengi: " << mon.getMoney() << endl;
	int a, b; //переменные дл€ ставки и числа
	while (true) {
		if (mon.getMoney() <= 0) { //если деньги меньше или равны 0 то
			cout << "Igra zakonchena!\n" << endl; //прекратить игру
			system("pause");
			return 0; //не знаю как ещЄ выйти, break разве что, но тогда в конец программы оп€ть return 0 нужен
		}
		else {
			cout << "Vvedite stavku: " << endl;
			cin >> a; //ввод ставки
			cout << "Vvedite chislo: " << endl;
			cin >> b; //ввод числа
			Roulette roul(a, b);//вызов конструктора класса Roulette с параметрами
			roul.game(); //продолжить игру
			roul.show(); //вывести значени€ на экран
			system("CLS");
		}
	}
}