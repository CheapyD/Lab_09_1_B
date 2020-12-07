#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Specialty { КН, ІН, МЕ, ФН, ТН };

string specialtyStr[] = { "КН", "ІН", "МЕ", "ФН", "ТН" };

struct Student
{
	string prizv;
	short unsigned kurs;
	Specialty specialty;
	short unsigned physics;
	short unsigned mathematics;
	union
	{
		short unsigned programming;
		short unsigned NumericMethods;
		short unsigned pedagogy;
	};
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
void MinAverage(Student* p, const int N, double& MinAve);
void CountMarks(Student* p, const int N, int& countphysics, int& countmathematics, int& countprogramming, int& countNumericMethods, int& countpedagogy);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть N: "; cin >> N;

	Student* p = new Student[N];

	double MinAver = 0.0;
	int count = 0;
	int countphysics = 0;
	int countmathematics = 0;
	int countprogramming = 0;
	int countNumericMethods = 0;
	int countpedagogy = 0;

	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - вивід найменшого середьного балу" << endl;
		cout << " [4] - вивід вивід кількості 4 з кожного предмету" << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;

		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			MinAverage(p, N, MinAver);
			cout << "Мінімальне середній бал: " << setprecision(2) << fixed << MinAver << endl;
			break;
		case 4:
			CountMarks(p, N, countphysics, countmathematics, countprogramming, countNumericMethods, countpedagogy);
			cout << "Кількість 4 з фізики: " << countphysics << endl;
			cout << "Кількість 4 з математики: " << countmathematics << endl;
			cout << "Кількість 4 з програмування: " << countprogramming << endl;
			cout << "Кількість 4 з чисельних методів: " << countNumericMethods << endl;
			cout << "Кількість 4 з педагогіки: " << countpedagogy << endl;
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);
	system("pause");
	return 0;
}

void Create(Student* p, const int N)
{
	int specialty;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.sync();
		cout << " Прізвище: "; cin >> p[i].prizv;
		cout << " Курс: "; cin >> p[i].kurs;
		cout << " Спеціальність (0 - КН, 1 - ІН, 2 - МЕ, 3 - ФН, 4 - ТН): ";
		cin >> specialty;
		p[i].specialty = (Specialty)specialty;
		cout << " Оцінка з фізики: "; cin >> p[i].physics;
		cout << " Оцінка з математики: "; cin >> p[i].mathematics;
			switch (p[i].specialty)
			{
			case КН:
				cout << " Оцінка з програмування : "; cin >> p[i].programming;
				break;
			case ІН:
				cout << " Оцінка з чисельних методів: "; cin >> p[i].NumericMethods;
				break;
			case МЕ:
				cout << " Оцінка з педагогіки: "; cin >> p[i].pedagogy;
				break;
			case ФН:
				cout << " Оцінка з педагогіки: "; cin >> p[i].pedagogy;
				break;
			case ТН:
				cout << " Оцінка з педагогіки: "; cin >> p[i].pedagogy;
				break;
			}
			cout << endl;
	}
}

void Print(Student* p, const int N)
{
	cout << "============================================================================================================"
		<< endl;
	cout << "| № | Прізвище | Курс | Спеціальність | Фізика | Математика | Програмування | Чисельні методи | Педагогіка |"
		<< endl;
	cout << "------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(9) << left << p[i].prizv
			 << "| " << setw(4) << left << p[i].kurs << " "
			 << "| " << setw(14) << left << specialtyStr[p[i].specialty]
			 << "| " << setw(6) << left << p[i].physics << " "
			 << "| " << setw(10) << left << p[i].mathematics << " ";
			switch (p[i].specialty)
			{
			case КН:
				cout << "| " << setw(13) << left
					 << p[i].programming << " |" << setw(18) << right << "|" << setw(13) << right << "|" << endl;
				break;
			case ІН:
				cout << "| " << setw(16) << right
					 << "| " << setw(16) << left << p[i].NumericMethods << "|" << setw(13) << right << "|" << endl;
				break;
			case МЕ:
				cout << "| " << setw(15) << right << "|"  << setw(19) << right
					 << "| " << setw(11) << left << p[i].pedagogy << "|" << endl;
				break;
			case ФН:
				cout << "| " << setw(15) << right << "|" << setw(19) << right
					 << "| " << setw(11) << left << p[i].pedagogy << "|" << endl;
				break;
			case ТН:
				cout << "| " << setw(15) << right << "|" << setw(19) << right
					 << "| " << setw(11) << left << p[i].pedagogy << "|" << endl;
				break;
			}
		cout << "------------------------------------------------------------------------------------------------------------"
			 << endl;
	}
}

void MinAverage(Student* p, const int N, double& MinAve)
{
	double average;
	MinAve = (p[0].physics + p[0].mathematics + p[0].programming) / 3.;
	for (int i = 1; i < N; i++)
	{
		average = (p[i].physics + p[i].mathematics + p[i].programming) / 3.;

		if (MinAve > average)
			MinAve = average;
	}
}

void CountMarks(Student* p, const int N, int& countphysics, int& countmathematics, int& countprogramming, int& countNumericMethods, int& countpedagogy)
{
	countphysics = 0;
	countmathematics = 0;
	countprogramming = 0;
	countNumericMethods = 0;
	countpedagogy = 0;

	for (int i = 0; i < N; i++)
	{
		if (p[i].physics == 4)
			countphysics++;
		if (p[i].mathematics == 4)
			countmathematics++;
		switch (p[i].specialty)
		{
		case КН:
			if (p[i].programming == 4)
				countprogramming++;
			break;
		case ІН:
			if (p[i].NumericMethods == 4)
				countNumericMethods++;
			break;
		default:
			if (p[i].pedagogy == 4)
				countpedagogy++;
			break;
		}
	}
}
