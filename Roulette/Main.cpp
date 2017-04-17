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
		cout << "Stavka:" << getRate() << " Chislo:" << getNumber() << endl; //�������: ������, �����
		cout << "Vipalo:" << spin() << endl; //�������: ��������� ��������� �����
		cout << "Dengi:" << money << endl; //�������: ������
	}
};

class Money : Roulette { //����� Money ��������� ������ Roulette
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
	cout << "Vashi dengi: " << money << endl;
	int a, b; //���������� ��� ������ � �����
loop:
	cout << "Vvedite stavku: " << endl;
	cin >> a; //���� ������
	if (a > mon.getMoney()) {
		cout << "Vi ne mozhete sdelat stavku!" << endl;
		goto loop;
	}
	else {
		cout << "Vvedite chislo: " << endl;
		cin >> b; //���� �����
		Roulette roul(a, b);//����� ������������ ������ Roulette � �����������
		if (mon.getMoney() <= 0) { //���� ������� ������� getMoney <= 0 ��
			cout << "Igra zakonchena!" << endl; //���������� ����
			return 0;
		}
		else { //���� ����� ��
			roul.game(); //���������� ����
			roul.show(); //������� �������� �� �����
		}
		system("pause");
		goto loop; //����� ���� ������ switch ��� while
		system("pause");
	}
}