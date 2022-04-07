#include <fstream>
#include <string>
#include <Windows.h>
#include <iostream>
#include <iomanip>


using namespace std;

struct Route
{
	string startName;
	string endName;
	int num;
};

void Create(Route* r, const int N);
void Print(Route* r, const int N);
void Sort(Route* r, const int N);
void StartFind(Route* r, const int N, const string name);
void EndFind(Route * r, const int N, const string name);
void SaveToFile(Route* r, const int N, const char* filename);
void LoadFromFile(Route*& r, int& N, const char* filename);

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N;
	cout << "Введіть N: "; cin >> N;
	Route* r = new Route[N];
	string name;
	int menuItem;
	char filename[100];
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - впорядкування даних за номерами маршрутів" << endl;
		cout << " [4] - пошук за назвою початково або кінцевого пункту" << endl;
		cout << " [5] - запис даних у файл" << endl;
		cout << " [6] - зчитування даних із файлу" << endl << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(r, N);
			break;
		case 2:
			Print(r, N);
			break;
		case 3:
			Sort(r, N);
			break;
		case 4:
			cout << "Введіть ключі пошуку:" << endl;
			cin.get();
			cin.sync();
			cout << "Назва: "; getline(cin, name); cout << "\n";
			StartFind(r, N, name);
			EndFind(r, N, name);
			break;
		case 5:
			cin.get();
			cin.sync();
			cout << "Введіть ім'я файлу: "; 
			cin.getline(filename, 99);
			SaveToFile(r, N, filename);
			break;
		case 6:
			cin.get();
			cin.sync();
			cout << "Введіть ім'я файлу: "; 
			cin.getline(filename, 99);
			LoadFromFile(r, N, filename);
			break;
		case 0:
			break;
		default:
			cout << "Помилка! Повторіть спробу" << endl;
		}
	} while (menuItem != 0);

	return 0;
}
void Create(Route* r, const int N)
{
	for (int i = 0; i < N; i++)
	{
		cin.get();
		cin.sync();

		cout << " Назва початкового пункту: "; getline(cin, r[i].startName);
		cout << " Назва кінцевого пункту: "; getline(cin, r[i].endName);
		cout << " Номер маршруту : "; cin >> r[i].num;

		cout << endl;
	}
}
void Print(Route* r, const int N) 
{
	for (int i = 0; i < N; i++)
	{
		cout << "Номер   " << "Початкова   " << "Кінцева" << endl;
		cout << r[i].num << setw(8) << r[i].startName << setw(12) << r[i].endName << "\n\n";
	}
}

void Sort(Route* r, const int N) 
{
	Route tmp;
	for (int i0 = 0; i0 < N - 1; i0++)
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if ((r[i1].num > r[i1 + 1].num))
			{
				tmp = r[i1];
				r[i1] = r[i1 + 1];
				r[i1 + 1] = tmp;
			}

}
void EndFind(Route* r, const int N, const string name)
{
	bool routeExists = false;
	for (int i = 0; i < N; i++)
	{
		if (r[i].endName == name)
		{
			cout << "Знайдено маршрут № " << r[i].num << endl;
			cout << "Початок: " << r[i].startName << "  Кінець: " << r[i].endName << "\n" << endl;
			routeExists = true;
		}
	}
	if (!routeExists)
	{
		cout << "Mаршрут з кінцем " << name << " не знайдено" << endl;
	}
}

void StartFind(Route* r, const int N, const string name)
{
	bool routeExists = false;
	for (int i = 0; i < N; i++)
	{
		if (r[i].startName == name)
		{
			cout << "Знайдено маршрут № " << r[i].num << endl;
			cout << "Початок: " << r[i].startName << "  Кінець: " << r[i].endName << "\n" << endl;
			routeExists = true;
		}
	}
	if (!routeExists)
	{
		cout << "Маршрут з початком " << name << " не знайдено" << endl;
	}
}

void SaveToFile(Route* r, const int N, const char* filename)
{
	ofstream fout(filename, ios::binary);
	fout.write((char*)&N, sizeof(N));
	for (int i = 0; i < N; i++)
		fout.write((char*)&r[i], sizeof(Route));
	fout.close();
}
void LoadFromFile(Route*& r, int& N, const char* filename)
{
	delete[] r;
	ifstream fin(filename, ios::binary);
	fin.read((char*)&N, sizeof(N));
	r = new Route[N];
	for (int i = 0; i < N; i++)
		fin.read((char*)&r[i], sizeof(Route));
	fin.close();
}
