//1. Програма має дати користувачеві можливість фізично впорядкувати масив в першу чергу – за значенням оцінки з фізики,
//в другу чергу(для однакових оцінок з фізики) – за назвою спеціальності, в останню чергу(для однакових оцінок з фізики
//і спеціальностей) – за прізвищем за зростанням – в алфавітному порядку.
//2. Програма має будувати індексний масив, який забезпечує наступне індексне впорядкування : 
//в першу чергу – за значенням оцінки з фізики, в другу чергу(для однакових оцінок з фізики) – за назвою спеціальності, 
//в останню чергу(для однакових оцінок з фізики і спеціальностей) – за прізвищем. 3. За допомогою бінарного пошуку визначити, 
//чи навчається студент із вказаним користувачем прізвищем на вказаній спеціальності та вказаною оцінкою з фізики.

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Specialnist { KN, INF, MathEcon, PhysInf, WORK };

string specStr[] = { "Комп'ютерні науки", "Інформатика", "Математика і економіка", "Фізика та інформатика", "Трудове навчання" };

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
	cout << "Введіть N: "; cin >> N;
	Student* s = new Student[N];
	int indexSpec;
	enum Specialnist specialnist;
	string prizv;
	int physics;
	int found;
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - фізичне впорядкування даних за " << endl;
		cout << " оцінкою з фізики/спецільністю/прізвищем" << endl << endl;
		cout << " [4] - індексне впорядкування та вивід даних" << endl;
		cout << " [5] - бінарний пошук за прізвищем, спеціальністю та оцінкою з фізики" << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
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
			cout << "Введіть ключі пошуку:" << endl;
			cout << "Спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, 2 - Математика і економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
			cin >> indexSpec;
			specialnist = (Specialnist)indexSpec;
			cin.get();
			cin.sync();

			cout << "Прізвище : "; getline(cin, prizv);
			cout << endl;
			cout << "Оцінка з фізики: "; cin >> physics;
			cout << endl;
			if ((found = BinarP(s, N, prizv, specialnist, physics)) != -1)
				cout << "Знайдено студента на позиції " << found + 1 << endl;
			else
				cout << "Студента не знайдено" << endl;
			break;
		case 0:
			break;
		default:
			cout << "Помилка! Повторіть спробу" << endl;
		}
	} while (menuItem != 0);


	return 0;
}
void Create(Student* s, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();

		cout << "Прізвище: "; getline(cin, s[i].prizv);
		cout << "Курс: "; cin >> s[i].kurs;
		cout << "Спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, 2 - Математика і економіка, 3 - Фізика та Інформатика 4 - Трудове навчання): ";
		cin >> spec;
		s[i].specialnist = (Specialnist)spec;
		cout << "Фізика: "; cin >> s[i].physics;
		cout << "Математика: "; cin >> s[i].math;
		switch (s[i].specialnist)
		{
		case MathEcon:
		case PhysInf:
		case WORK:
			cout << "Педагогіка : "; cin >> s[i].pedagogic;
			break;
		case KN:
			cout << "Програмування : "; cin >> s[i].programming;
			break;
		case INF:
			cout << "Методи : "; cin >> s[i].methods;
			break;
		}
		cout << endl;
	}
}
void Print(Student* s, const int N)
{
	cout << "================================================================================================================"
		<< endl;
	cout << "| № | Прізвище | Курс |     Спеціальність     | Фізика | Математика | Програмування | Чис. методи | Педагогіка |"
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
	cout << "| № | Прізвище | Курс |     Спеціальність     | Фізика | Математика | Програмування | Чис. методи | Педагогіка |"
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