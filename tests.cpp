
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class Database
{
private:
	class Student
	{
	private:
		string name;
		int course;
		int age;
		bool gender;
		double grade;

	public:
		Student() // конструктор без параметров
		{
			name = "Ivan";
			age = rand() % 10 + 25;
			course = rand() % 4 + 1;
			grade = rand() % 8 + 2;
			gender = 1;
		}


		Student(string cons) // ввод с клавиатуры 
		{
			cout << " name = ";
			cin >> name;

			do {
				cout << " age (16 - 80) = ";
				cin >> age;
			} while (age < 16 || age > 80);

			do {
				cout << " gender (1 - male, 0 - female) = ";
				cin >> gender;
			} while (gender != true && gender != false);

			do {
				cout << " course (1 - 4) = ";
				cin >> course;
			} while (course < 1 || course > 4);

			do {
				cout << " grade (1 - 10) = ";
				cin >> grade;
			} while (grade < 1 || grade > 10);
			cout << endl;
		}

		~Student() // деструктор
		{
		}

		Student(const Student& T) // конструктор копирования
		{
			name = T.name;
			age = T.age;
			course = T.course;
			gender = T.gender;
			grade = T.grade;
		}

		int getCourse()
		{
			return course;
		}

		double getGender()
		{
			return gender;
		}

		friend ostream& operator<< (ostream& out, Student& E) // оператор вывода
		{
			if (E.gender == true)
			out << left << setw(7) << E.name << left << setw(5) << E.age << left << setw(5) << E.course << left << setw(12) << "Male" << left << setw(8) << E.grade;
			else out << left << setw(7) << E.name << left << setw(5) << E.age << left << setw(5) << E.course << left << setw(12) << "Female" << left << setw(8) << E.grade;
			return out;
		}
	};

	Student database[3];

public:

	Database() // конструктор без параметров
	{
		for (int i = 0; i < 3; i++)
		{
			database[i] = Student();
		}
	}

	Database(int len) // конструктор c параметрaми
	{
		for (int i = 0; i < len; i++)
		{
			database[i] = Student();
		}
	}

	Database(string cons) //заполнение с клавиатуры
	{
		if (cons == "console")
		{
			for (int i = 0; i < 3; i++)
			{
				database[i] = Student("console");
			}
		}
	}

	Database(const Database& V) //конструктор копирования
	{
		for (int i = 0; i < 3; i++)
		{
			database[i] = V.database[i];
		}
	}

	~Database() // деструктор
	{

	}

	Student operator [] (int index)
	{
		return database[index];
	}

	int getCourse(int index) // получение курса
	{
		return database[index].getCourse();
	}

	double getGender(int index) // получение пола
	{
		return database[index].getGender();
	}

	friend ostream& operator<< (ostream& out, Database& E) //оператор вывода
	{
		for (int i = 0; i < 3; i++)
		{
			out << E.database[i];
			out << endl;
		}

		return out;
	}

	void getStudent(int index) // поиск студента
	{
		cout << database[index];
	}

	bool write(ostream& type) // чтение из файла
	{
		type.write((char*)this, sizeof(Database));
		return type.good();
	}

	bool read(ifstream& type)// запись в файл
	{
	type.read((char*)this, sizeof(Database));
		return type.good();
	}

};

int main()
{
	int course,n, count = 0;
	double average = 0;

	Database A("console");
	cout << left << setw(7) << "Name:" << left << setw(5) << "Age:" << left << setw(5) << "Course:" << left << setw(9) << "Gender:" << left << setw(8) << "Grade:" << endl;
	cout << A;

	cout << "Give course:";	cin >> course;

	for (int i = 0; i < 3; i++)
	{
		if (A[i].getCourse() == course && A[i].getGender() == 1) count++;
	}

	cout << "Num of male studs for " << course << " course : " << count << endl;
	cout << "Give num of stud to choose = "; cin >> n;
	cout << left << setw(7) << "Name:" << left << setw(5) << "Age:" << left << setw(5) << "Course:" << left << setw(9) << "Gender:" << left << setw(8) << "Grade:" << endl;
	A.getStudent(n);

	ofstream ofs2("input", ios::binary | ios::out);

	A.write(ofs2);

	ifstream ofs1("input", ios::binary | ios::in);

	A.read(ofs1);
	cout <<endl<< A;
	return 0;
}
