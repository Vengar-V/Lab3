#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Specialnist { KN, INF, MathEcon, PhysInf, WORK };

string specStr[] = { "����'����� �����", "�����������", "���������� � ��������", "Գ���� �� �����������", "������� ��������" };

struct Student
{
	string prizv;
	int kurs;
	int physics;
	int math;
	Specialnist specialnist;
	union
	{
		int pedagogic;
		int programming;
		int methods;
	};
};
void Create(Student* s, const int N);
void Print(Student* s, const int N);
int MathFourOrFive(Student* s, const int N);
int PhysicsFourOrFive(Student* s, const int N);
int ProgrammingFourOrFive(Student* s, const int N);
int PedagogicFourOrFive(Student* s, const int N);
int MethodsFourOrFive(Student* s, const int N);
void Prizv(Student* s, const int N);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N;
	cout << "������ N: "; cin >> N;
	Student* s = new Student[N];
	Create(s, N);
	Print(s, N);
	cout << "������� ����� � ������: " << PhysicsFourOrFive(s, N) << endl;
	cout << "������� ����� � ����������: " << MathFourOrFive(s, N) << endl;
	cout << "������� ����� � �������������: " << ProgrammingFourOrFive(s, N) << endl;
	cout << "������� ����� � ���������: " << PedagogicFourOrFive(s, N) << endl;
	cout << "������� ����� � ������: " << MethodsFourOrFive(s, N) << endl;
	Prizv(s, N);
	return 0;
}
void Create(Student* s, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "�������: " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << " �������: "; getline(cin, s[i].prizv);
		cout << " ����: "; cin >> s[i].kurs;
		cout << "������������ (0 - ����'����� �����, 1 - �����������, 2 - ���������� � ��������, 3 - Գ���� �� �����������, 4 - ������� ��������): ";
		cin >> spec;
		s[i].specialnist = (Specialnist)spec;
		cout << "Գ����: "; cin >> s[i].physics;
		cout << "����������: "; cin >> s[i].math;
		switch (s[i].specialnist)
		{
		case MathEcon:
		case PhysInf:
		case WORK:
			cout << "��������� : "; cin >> s[i].pedagogic;
			break;
		case KN:
			cout << "������������� : "; cin >> s[i].programming;
			break;
		case INF:
			cout << "������: "; cin >> s[i].methods;
			break;
		}
		cout << endl;
	}
}
void Print(Student* s, const int N)
{
	cout << "================================================================================================================"
		<< endl;
	cout << "| � | ������� | ���� |     ������������     | Գ���� | ���������� | ������������� | ���. ������ | ��������� |"
		<< endl;
	cout << "----------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(9) << left << s[i].prizv
			<< "| " << setw(5) << left << s[i].kurs
			<< "| " << setw(22) << specStr[s[i].specialnist]
			<< "| " << setw(7) << left << s[i].physics
			<< "| " << setw(11) << left << s[i].math;

		switch (s[i].specialnist)
		{
		case KN:
			cout << "| " << setw(13)
				<< s[i].programming << " |" << "             " << "|"
				<< "            " << "|" << endl;
			break;
		case INF:
			cout << "| " << "              " << "| " << setw(11)
				<< s[i].methods << " |" << "            " << "|" << endl;
			break;
		case MathEcon:
		case PhysInf:
		case WORK:
			cout << "| " << "              " << "|" << "             " << "| " << setw(11)
				<< s[i].pedagogic << "|" << endl;
			break;
		}
	}
	cout << "================================================================================================================"
		<< endl;
	cout << endl;
}
int MathFourOrFive(Student* s, const int N) 
{
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (s[i].math == 3)
			count++;
	}
	return count;
}

int PhysicsFourOrFive(Student* s, const int N) 
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		if (s[i].physics == 3)
			count++;
	}
	return count;
}

int ProgrammingFourOrFive(Student* s, const int N) 
{
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (s[i].specialnist == 0)
			if (s[i].programming == 3)
				count++;
	}
	return count;
}

int MethodsFourOrFive(Student* s, const int N)
{
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (s[i].specialnist == 1)
			if (s[i].methods == 3)
				count++;
	}
	return count;
}

int PedagogicFourOrFive(Student* s, const int N) 
{
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (s[i].specialnist >= 2)
			if (s[i].pedagogic == 3)
				count++;
	}
	return count;
}

void Prizv(Student* s, const int N)
{
	cout << "C�������, � ���� � ������ � ���������� 4 ��� 5:" << endl;
	for (int i = 0; i < N; i++)
	{
		if ((s[i].math == 4 || s[i].math == 5) && ((s[i].physics == 4 || s[i].physics == 5)))
		{
			cout << s[i].prizv << endl;
		}
	}
}
