/*
Варіант 11.
Описати структуру з іменем Route, що містить наступні поля:
 назву початкового пункту маршруту;
 назву кінцевого пункту маршруту;
 номер маршруту.
Написати програму, що виконує наступні дії:
 введення даних з клавіатури в масив, що складається з елементів типу Route;
 впорядкування масиву структур за номерами маршрутів;
 вивід на екран інформації про маршрути, які починаються або закінчуються в
пункті, назва якого введена з клавіатури; якщо таких маршрутів немає, вивести
на екран відповідне повідомлення.
*/

#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <iostream>

using namespace std;

struct Route
{
    string startPoint;
    string endPoint;
    int num;
};



void Create(Route* R, const int N);
void Print(Route* R, const int N);
void Sort(Route* R, const int N);
int Search(Route* R, const int N, const string);
void SaveToFile(Route* p, const int N, const char* filename);
void LoadFromFile(Route*& p, int& N, const char* filename);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість маршрутів: "; cin >> N;

    Route* R = new Route[N];

    char filename[100];
    string f_zod;

    int MenuItem;

    while (true)
    {
        cout << endl << endl << endl;
        cout << "Виберіть дію:" << endl;
        cout << "1 - введення даних з клавіатури" << endl;
        cout << "2 - вивід даних на екран" << endl;
        cout << "3 - сортування за прізвищем" << endl;//-
        cout << "4 - інформація про людину" << endl;//=
        cout << "5 - запис у файл" << endl;
        cout << "6 - зчитування з файлу" << endl;
        cout << "0 - вихід та завершення роботи програми" << endl;
        cout << "Введіть значення: "; cin >> MenuItem; cout << endl;

        switch (MenuItem)
        {
        case 1:
            Create(R, N);
            break;
        case 2:
            Print(R, N);
            break;
        case 3:
            Sort(R, N);
            Print(R, N);
            break;
        case 4:
            cout << "Введіть номер маршруту " << endl;
            cin.get();
            cin.sync();
            getline(cin, newFile); cout << endl;
            Search(R, N, newFile);
            break;
        case 5:
            cin.get(); 
            cin.sync(); 
            cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
            SaveToFile(R, N, filename);
            break;
        case 6:
            cin.get();
            cin.sync();

            cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
            LoadFromFile(R, N, filename);
            break;
        }


        if (MenuItem == 0) break;
    }

    return 0;
}

void Create(Route* R, const int N)
{
    for (int i = 0; i < N; i++)
    {

        int speciality;
        cout << "Маршрут: " << i + 1 << endl;
        cin.get();
        cin.sync();
        cout << "Початок маршруту: "; getline(cin, R[i].startPoint);
        cout << "Кінець маршруту: "; getline(cin, R[i].endPoint);
        cout << "Номер маршруту: "; getline(cin, R[i].num);
        cout << endl;
    }
}

void Print(Route* R, const int N)
{
    cout << "=================================================" << endl;
    cout << "|  №  |  Початок  | Кінець |    Номер маршруту  |" << endl;
    cout << "-------------------------------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(3) << i + 1 << setw(3);
        cout << "|" << setw(4) << R[i].startPoint << setw(8);
        cout << "|" << setw(6) << R[i].endPoint << setw(3);
        cout << "|" << setw(6) << R[i].num << setw(12);

    }
    cout << "==================================================" << endl << endl;
}
void Sort(Zodiac* S, Bday* B, int N)
{
    Zodiac temp;
    Bday btemp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if ((S[j].surname > S[j + 1].surname)
                ||
                (S[j].surname == S[j + 1].surname))
            {
                temp = S[j];
                S[j] = S[j + 1];
                S[j + 1] = temp;

                btemp = B[j];
                B[j] = B[j + 1];
                B[j + 1] = btemp;
            }

        }
    }
}

int Search(Zodiac* S, Bday* B, const int N, const string f_zod)
{
    string zod;
    int flag = 0;
    cout << "=========================================================================================" << endl;
    cout << "|  №  |  Прізвище  | Імя | Знак зодіаку  |  День народження  |  Місяць  |  Рік          |" << endl;
    for (int i = 0; i < N; i++) {
        if (S[i].zodiac_sign == f_zod)
        {
            flag = 1;

            cout << "-----------------------------------------------------------------------------------------" << endl;
            cout << "|" << setw(3) << i + 1 << setw(3);
            cout << "|" << setw(4) << S[i].surname << setw(8);
            cout << "|" << setw(6) << S[i].name << setw(3);
            cout << "|" << setw(6) << S[i].zodiac_sign << setw(6);
            cout << "|" << setw(6) << B[i].day << setw(12);
            cout << "|" << setw(6) << B[i].month << setw(6);
            cout << "|" << setw(10) << B[i].year << setw(6) << "|" << endl;

        }
    }
    cout << "=========================================================================================" << endl << endl;
    if (!flag)
        cout << "Немає людей які народились під таким знаком зодіаку" << endl;
    return flag;
}








void SaveToFile(Zodiac* p, Bday* b, const int N, const char* filename)

{
    ofstream fout(filename, ios::binary); // відкрили бінарний файл запису
    fout.write((char*)&N, sizeof(N)); // записали кількість елементів
    for (int i = 0; i < N; i++)
    {
        fout.write((char*)&p[i], sizeof(Zodiac)); // записали елементи масиву
        fout.write((char*)&b[i], sizeof(Bday));
    }
    fout.close(); // закрили файл
}

void LoadFromFile(Zodiac*& p, Bday*& b, int& N, const char* filename)
{
    delete[] p; // знищили попередні дані
    ifstream fin(filename, ios::binary); // відкрили бінарний файл зчитування
    fin.read((char*)&N, sizeof(N)); // прочитали кількість елементів
    p = new Zodiac[N]; // створили динамічний масив
    b = new Bday[N]; // створили динамічний масив
    for (int i = 0; i < N; i++)
    {
        fin.read((char*)&p[i], sizeof(Zodiac)); // прочитали елементи масиву
        fin.read((char*)&b[i], sizeof(Bday));
    }
    fin.close(); // закрили файл
}