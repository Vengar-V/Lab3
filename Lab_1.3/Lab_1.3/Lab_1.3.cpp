/*
Сформувати масив структур, що містять інформацію про : прізвище
студента, курс, спеціальність(для представлення спеціальності використовувати переліки, а
	для представлення курсу – цілі числа) та оцінки з фізики, математики, інформатики
	Варіант 11.
1. Обчислити кількість оцінок «задовільно» з кожного предмету.
2.Вивести прізвища студентів, які отримали і з фізики і з математики оцінки «5» або «4».
*/


#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Specilnist { KN, INF, MathEcon, PhysInf, WORK };

string predmetStr[] = { " Комп. науки  ", " Інформатика  ", "Мат. та економ", " Фіз. та інф. ", " Труд. навч.  " };


struct Student
{
	string prizv;
	unsigned kurs;
	Specilnist spec;
	int Physical;
	int Math;
	int Informatik;
};



void Create(Student* s, const int N);
void Print(Student* s, const int N);
int Count(Student* s, const int N);
string Highest(Student* s, const int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть кількість студентів: "; cin >> N;

	Student* s = new Student[N];

	string prizv;
	unsigned kurs;
	Specilnist spec;
	int Physical;
	int Math;
	int Informatik;


	Create(s, N);
	Print(s, N);

	int counter = Count(s, N);

	if (counter != 0)
		cout << "Кількість оцінок 4 - " << counter << endl;
	else
		cout << endl << "Немає оцінок 4" << endl;

	cout << endl;

	cout << Highest(s, N) << endl;


	return 0;
}


void Create(Student* s, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури
		cin.sync(); // кінець рядка
		cout << " прізвище та ім'я: "; getline(cin, s[i].prizv);
		cout << " курс: "; cin >> s[i].kurs;
		cout << "  Виберіть спеціальність (0 - Комп. науки , 1 - Інформатика , 2 - Мат. та економ , 3 - Фіз. та інф. , 4 - Труд. навч. ): "; cin >> spec;
		s[i].spec = (Specilnist)spec;
		cout << " Оцінка з Фізики: "; cin >> s[i].Physical;
		cout << " Оцінка з Математики: "; cin >> s[i].Math;
		cout << " Оцінка з Інфортматики: "; cin >> s[i].Informatik;


		cout << endl;
	}
}
void Print(Student* s, const int N)
{
	cout << "======================================================================================="
		<< endl;
	cout << "| № |      Прізвище       | Курс | Спеціальність | Фізика | Математика | Інфортматика | "
		<< endl;
	cout << "---------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++) {
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(20) << left << s[i].prizv << "| " << setw(4) << right << s[i].kurs << " ";
		cout << "| " << setw(8) << right << predmetStr[s[i].spec] << " |";
		cout << "| " << setw(6) << setprecision(2) << fixed << right << s[i].Physical << right << " |";
		cout << " " << setw(10) << right << s[i].Math << " |";
		cout << " " << setw(12) << right << s[i].Informatik << " |" << endl;

	}
	cout << "=======================================================================================" << endl;
	cout << endl;
}
/*
 Обчислити кількість оцінок «задовільно» з кожного предмету
*/
int Count(Student* s, int n)
{
	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i].Informatik == 4)
		{
			counter++;
		} 
		if (s[i].Math == 4) 
		{
			counter++;
		}
		if (s[i].Physical == 4)
		{
			counter++;
		}
	}
	return counter;
}

/*
Вивести прізвища студентів, які отримали і з фізики і з математики оцінки «5» або «4».
*/
string Highest(Student* s, const int N)
{
	for (int i = 0; i < N; i++)
	{
		if (s[i].Math && s[i].Physical == 4 || s[i].Math && s[i].Physical == 5)
			cout << s[i].prizv << endl;
	}
}
