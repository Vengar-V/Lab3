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
	cout << "Введіть N: "; cin >> N;
	Student* s = new Student[N];
	Create(s, N);
	Print(s, N);
	cout << "кількість трійок з фізики: " << PhysicsFourOrFive(s, N) << endl;
	cout << "кількість трійок з математики: " << MathFourOrFive(s, N) << endl;
	cout << "кількість трійок з програмування: " << ProgrammingFourOrFive(s, N) << endl;
	cout << "кількість трійок з педагогіки: " << PedagogicFourOrFive(s, N) << endl;
	cout << "кількість трійок з методів: " << MethodsFourOrFive(s, N) << endl;
	Prizv(s, N);
	return 0;
}
void Create(Student* s, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент: " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << " Прізвище: "; getline(cin, s[i].prizv);
		cout << " Курс: "; cin >> s[i].kurs;
		cout << "Спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, 2 - Математика і економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
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
			cout << "Методи: "; cin >> s[i].methods;
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
	cout << "Cтуденти, в яких з фізики і математики 4 або 5:" << endl;
	for (int i = 0; i < N; i++)
	{
		if ((s[i].math == 4 || s[i].math == 5) && ((s[i].physics == 4 || s[i].physics == 5)))
		{
			cout << s[i].prizv << endl;
		}
	}
}
