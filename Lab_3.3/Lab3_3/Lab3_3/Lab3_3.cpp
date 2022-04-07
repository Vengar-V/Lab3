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
	cout << "������ N: "; cin >> N;
	Route* r = new Route[N];
	string name;
	int menuItem;
	char filename[100];
	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - ������������� ����� �� �������� ��������" << endl;
		cout << " [4] - ����� �� ������ ��������� ��� �������� ������" << endl;
		cout << " [5] - ����� ����� � ����" << endl;
		cout << " [6] - ���������� ����� �� �����" << endl << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
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
			cout << "������ ����� ������:" << endl;
			cin.get();
			cin.sync();
			cout << "�����: "; getline(cin, name); cout << "\n";
			StartFind(r, N, name);
			EndFind(r, N, name);
			break;
		case 5:
			cin.get();
			cin.sync();
			cout << "������ ��'� �����: "; 
			cin.getline(filename, 99);
			SaveToFile(r, N, filename);
			break;
		case 6:
			cin.get();
			cin.sync();
			cout << "������ ��'� �����: "; 
			cin.getline(filename, 99);
			LoadFromFile(r, N, filename);
			break;
		case 0:
			break;
		default:
			cout << "�������! �������� ������" << endl;
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

		cout << " ����� ����������� ������: "; getline(cin, r[i].startName);
		cout << " ����� �������� ������: "; getline(cin, r[i].endName);
		cout << " ����� �������� : "; cin >> r[i].num;

		cout << endl;
	}
}
void Print(Route* r, const int N) 
{
	for (int i = 0; i < N; i++)
	{
		cout << "�����   " << "���������   " << "ʳ�����" << endl;
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
			cout << "�������� ������� � " << r[i].num << endl;
			cout << "�������: " << r[i].startName << "  ʳ����: " << r[i].endName << "\n" << endl;
			routeExists = true;
		}
	}
	if (!routeExists)
	{
		cout << "M������ � ����� " << name << " �� ��������" << endl;
	}
}

void StartFind(Route* r, const int N, const string name)
{
	bool routeExists = false;
	for (int i = 0; i < N; i++)
	{
		if (r[i].startName == name)
		{
			cout << "�������� ������� � " << r[i].num << endl;
			cout << "�������: " << r[i].startName << "  ʳ����: " << r[i].endName << "\n" << endl;
			routeExists = true;
		}
	}
	if (!routeExists)
	{
		cout << "������� � �������� " << name << " �� ��������" << endl;
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
