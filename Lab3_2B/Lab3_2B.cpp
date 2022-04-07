//1. �������� �� ���� ������������ ��������� ������� ������������ ����� � ����� ����� � �� ��������� ������ � ������,
//� ����� �����(��� ��������� ������ � ������) � �� ������ ������������, � ������� �����(��� ��������� ������ � ������
//� ��������������) � �� �������� �� ���������� � � ���������� �������.
//2. �������� �� �������� ��������� �����, ���� ��������� �������� �������� ������������� : 
//� ����� ����� � �� ��������� ������ � ������, � ����� �����(��� ��������� ������ � ������) � �� ������ ������������, 
//� ������� �����(��� ��������� ������ � ������ � ��������������) � �� ��������. 3. �� ��������� �������� ������ ���������, 
//�� ��������� ������� �� �������� ������������ �������� �� ������� ������������ �� �������� ������� � ������.

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
	Specialnist specialnist;
	int physics;
	int math;
	union
	{
		int pedagogic;
		int programming;
		int methods;
	};
};

void Create(Student* s, const int N);
void Print(Student* s, const int N);
void Sort(Student* s, const int N);
int BinarP(Student* s, const int N, const string prizv, const Specialnist specialnist, const int physics);
int* Index(Student* s, const int N);
void PrintIndex(Student* s, int* I, const int N);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N;
	cout << "������ N: "; cin >> N;
	Student* s = new Student[N];
	int indexSpec;
	enum Specialnist specialnist;
	string prizv;
	int physics;
	int found;
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - ������� ������������� ����� �� " << endl;
		cout << " ������� � ������/�����������/��������" << endl << endl;
		cout << " [4] - �������� ������������� �� ���� �����" << endl;
		cout << " [5] - ������� ����� �� ��������, ������������ �� ������� � ������" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(s, N);
			break;
		case 2:
			Print(s, N);
			break;
		case 3:
			Sort(s, N);
			break;
		case 4:
			PrintIndex(s, Index(s, N), N);
			break;
		case 5:
			cout << "������ ����� ������:" << endl;
			cout << "������������ (0 - ����'����� �����, 1 - �����������, 2 - ���������� � ��������, 3 - Գ���� �� �����������, 4 - ������� ��������): ";
			cin >> indexSpec;
			specialnist = (Specialnist)indexSpec;
			cin.get();
			cin.sync();

			cout << "������� : "; getline(cin, prizv);
			cout << endl;
			cout << "������ � ������: "; cin >> physics;
			cout << endl;
			if ((found = BinarP(s, N, prizv, specialnist, physics)) != -1)
				cout << "�������� �������� �� ������� " << found + 1 << endl;
			else
				cout << "�������� �� ��������" << endl;
			break;
		case 0:
			break;
		default:
			cout << "�������! �������� ������" << endl;
		}
	} while (menuItem != 0);


	return 0;
}
void Create(Student* s, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();

		cout << "�������: "; getline(cin, s[i].prizv);
		cout << "����: "; cin >> s[i].kurs;
		cout << "������������ (0 - ����'����� �����, 1 - �����������, 2 - ���������� � ��������, 3 - Գ���� �� ����������� 4 - ������� ��������): ";
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
			cout << "������ : "; cin >> s[i].methods;
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
void Sort(Student* s, const int N)
{
	Student tmp;
	for (int i0 = 0; i0 < N - 1; i0++) 
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if ((s[i1].physics < s[i1 + 1].physics)
				||
				(s[i1].physics == s[i1 + 1].physics &&
					s[i1].specialnist > s[i1 + 1].specialnist)
				||
				(s[i1].physics == s[i1 + 1].physics &&
					s[i1].specialnist == s[i1 + 1].specialnist &&
					s[i1].prizv > s[i1 + 1].prizv))
			{
				tmp = s[i1];
				s[i1] = s[i1 + 1];
				s[i1 + 1] = tmp;
			}
}
int BinarP(Student* s, const int N, const string prizv, const Specialnist specialnist, const int physics)
{
	int l = 0, p = N - 1, m;
	do {
		m = (l + p) / 2;
		if (s[m].physics == physics && s[m].specialnist == specialnist && s[m].prizv == prizv)
			return m;
		if ((s[m].physics < physics)
			||
			(s[m].physics == physics &&
				s[m].specialnist < specialnist)
			|| (s[m].physics == physics &&
				s[m].specialnist == specialnist &&
				s[m].prizv < prizv))
		{
			l = m + 1;
		}
		else
		{
			p = m - 1;
		}
	} while (l <= p);
	return -1;
}
int* Index(Student* s, const int N) {
	int* I = new int[N]; 
	for (int i = 0; i < N; i++)
		I[i] = i; 
	int i, j, value; 
	for (i = 1; i < N; i++)
	{
		value = I[i];
		for (j = i - 1;
			j >= 0 && ((s[I[j]].physics < s[value].physics) || (s[I[j]].physics == s[value].physics && s[I[j]].specialnist > s[value].specialnist) ||
				(s[I[j]].physics == s[value].physics && s[I[j]].specialnist == s[value].specialnist && s[I[j]].prizv > s[value].prizv));
			j--)
		{
			I[j + 1] = I[j];
		}
		I[j + 1] = value;
	}
	return I;

}
void PrintIndex(Student* s, int* I, const int N) {
	cout << "================================================================================================================"
		<< endl;
	cout << "| � | ������� | ���� |     ������������     | Գ���� | ���������� | ������������� | ���. ������ | ��������� |"
		<< endl;
	cout << "----------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(9) << left << s[I[i]].prizv
			<< "| " << setw(5) << left << s[I[i]].kurs
			<< "| " << setw(22) << specStr[s[I[i]].specialnist]
			<< "| " << setw(7) << left << s[I[i]].physics
			<< "| " << setw(11) << left << s[I[i]].math;
		switch (s[I[i]].specialnist)
		{
		case KN:
			cout << "| " << setw(13)
				<< s[I[i]].programming << " |" << "             " << "|"
				<< "            " << "|" << endl;
			break;
		case INF:
			cout << "| " << "              " << "| " << setw(11)
				<< s[I[i]].methods << " |" << "            " << "|" << endl;
			break;
		case MathEcon:
		case PhysInf:
		case WORK:
			cout << "| " << "              " << "|" << "             " << "| " << setw(11)
				<< s[I[i]].pedagogic << "|" << endl;
			break;

		}
		cout << "================================================================================================================"
			<< endl;
		cout << endl;

	}
}