#include <iostream>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <ctime>

using namespace std;
class Money { //����� Money ��� ������������ ����� � ������ ���� � �� ������
	int money;
public:
	Money(); //�����������
	Money(int Money) { //����������� � ����� ���������� (�����? �� ����)
		money = 0;
		setRandMoney(); //������������� ������ (����� ����� ����� ���� �� ����)
	}
	void setMoney(int aMoney) { //������� ��������� �����
		money = aMoney;
	}
	void setRandMoney()
	{
		srand(time(NULL));
		money = rand() % 200 + 50; //��������� ��������� ����� � ��������� �� 50 �� 200 ������������
								   //� ���������� money (������� ��������� � protected ������ Roulette(��� ���)) ���������� �������� ����������
	}
	int getMoney() { //������� �������� �����
		return money;
	}
};

class Roulette { //����� Roulette (������� �����, ������)
private:
	int rate; //������
	int number; //�����
	int res; //������ ����������
public:
	Roulette(); //�����������
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
	void game(Money *money) {
		srand(time(NULL));
		money->setMoney((money->getMoney()) - rate); //�������� �� ����� ���� ������

		if (spin() == number) { //���� ��������� = ������ �����, ��
			res = rate*number; //������ ���������� �� ����� � ������������ � res
		}
		else {
			res = 0; //���� ��������, �� res = 0
		}
		money->setMoney((money->getMoney()) + res);  //� ������� ����������� res
	}
	void show(Money money) {
		cout << endl;
		cout << "------------------" << endl;
		cout << "������:" << getRate() << " �����:" << getNumber() << endl; //�������: ������, �����
		cout << "������:" << spin() << endl; //�������: ��������� ��������� �����
		cout << "������:" << money.getMoney() << endl; //�������: ������
		cout << "------------------" << endl;
		cout << endl;
		system("pause");
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	Money mon(0); //����� ������������ ������ Money � ���������� (�� ����� �����, �� ���� ����������� ��� ���������, �� getMoney �������� �� ��������)
	int a, b; //���������� ��� ������ � �����
	while (true) {
		if (mon.getMoney() <= 0) { //���� ������ ������ ��� ����� 0 ��
			cout << "���� ���������!\n" << endl; //���������� ����
			system("pause");
			return 0; //�� ���� ��� ��� �����, break ����� ���, �� ����� � ����� ��������� ����� return 0 �����
		}
		else {
			cout << "���� ������: " << mon.getMoney() << endl;
			cout << "������� ������: " << endl;
			cin >> a; //���� ������
			cout << "������� ����� (0-36): " << endl;
			cin >> b; //���� �����
			Roulette roul(a, b);//����� ������������ ������ Roulette � �����������
			roul.game(&mon); //���������� ����
			roul.show(mon); //������� �������� �� �����
			system("CLS");
		}
	}
}