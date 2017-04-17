#include <iostream>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <ctime>

using namespace std;
int money = 0; //���������� ���������� money, ���� ��������� � ����� �����, �� ������ ����������, � ��� ��� �� ����

class Roulette { //����� Roulette (������� �����, ������)
private:
	int rate; //������
	int number; //�����
	int res; //������ ����������
public:
	Roulette() {
	}; //�����������
	Roulette(int Rate, int Number) { // �����������  � �����������
		setRate(Rate); // ������������� ������
		setNumber(Number); //������������� �����
	}
	void setRate(int Rate) { //������� ��������� ������
		rate = Rate;
	}
	void setNumber(int Number) { //������� ��������� �����
		number = Number;
	}
	int getRate() { //������� �������� ������
		return rate;
	}
	int getNumber() { //������� �������� �����
		return number;
	}
	int spin() { //��������� ��������� �����
		int i = rand() % 36; //�������� ���������� �� 0 �� 36 ������������
		return i; //����������� �������� 15 ��� ��������
	}
	void game() {
		srand(time(NULL));
		money = money - rate; //�������� �� ����� ���� ������
		if (spin() == number) { //���� ��������� = ������ �����, ��
			res = rate*number; //������ ���������� �� ����� � ������������ � res
		}
		else {
			res = 0; //���� ��������, �� res = 0
		}
		money = money + res;  //� ������� ����������� res
	}
	void show() {
		cout << endl;
		cout << "------------------" << endl;
		cout << "Stavka:" << getRate() << " Chislo:" << getNumber() << endl; //�������: ������, �����
		cout << "Vipalo:" << spin() << endl; //�������: ��������� ��������� �����
		cout << "Dengi:" << money << endl; //�������: ������
		cout << "------------------" << endl;
		cout << endl;
		system("pause");
	}
};

class Money { //����� Money ��� ������������ ����� � ������ ���� � �� ������
public:
	Money(); //�����������
	Money(int Money) { //����������� � ����� ���������� (�����? �� ����)
		setMoney(Money); //������������� ������ (����� ����� ����� ���� �� ����)
	}
	void setMoney(int Money) { //������� ��������� �����
		srand(time(NULL));
		Money = rand() % 200 +50; //��������� ��������� ����� � ��������� �� 50 �� 200 ������������
		money = Money; //� ���������� money (������� ��������� � protected ������ Roulette) ���������� �������� ����������
	}
	int getMoney() { //������� �������� �����
		return money;
	}
};


int main() {
	Money mon(0); //����� ������������ ������ Money � ���������� (�� ����� �����, �� ���� ����������� ��� ���������, �� getMoney �������� �� ��������)
	cout << "Vashi dengi: " << mon.getMoney() << endl;
	int a, b; //���������� ��� ������ � �����
	while (true) {
		if (mon.getMoney() <= 0) { //���� ������ ������ ��� ����� 0 ��
			cout << "Igra zakonchena!\n" << endl; //���������� ����
			system("pause");
			return 0; //�� ���� ��� ��� �����, break ����� ���, �� ����� � ����� ��������� ����� return 0 �����
		}
		else {
			cout << "Vvedite stavku: " << endl;
			cin >> a; //���� ������
			cout << "Vvedite chislo: " << endl;
			cin >> b; //���� �����
			Roulette roul(a, b);//����� ������������ ������ Roulette � �����������
			roul.game(); //���������� ����
			roul.show(); //������� �������� �� �����
			system("CLS");
		}
	}
}