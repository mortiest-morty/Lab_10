# include "Header.h"

int main() {
	using namespace std;
	setlocale(LC_ALL, "Rus");
	int num;

	cout << "~ Yo, hiii ~ " << endl;;
	cout << "Введите номер желаемой задачи (0 - выход): ";
	cin >> num;
	while (num != 0 && (num < 1 || num>5)) {
		cout << "Введите цифру 1-5: ";
		cin >> num;
	}

	while (num != 0) {

		switch (num) {
		case 1:
			cout << endl << "(^-^) ============  Задание 1  ============ (^-^)" << endl;
			cout << "\n";
			task_1();
			cout << endl;
			break;
		case 2:
			cout << endl << "(^-^) ============  Задание 2  ============ (^-^)" << endl;
			cout << "\n";
			task_2();
			cout << endl;
			break;
		case 3:
			cout << endl << "(^-^) ============  Задание 3  ============ (^-^)" << endl;
			cout << "\n";
			task_3();
			cout << endl;
			break;
		case 4:
			cout << endl << "(^-^) ============  Задание 4  ============ (^-^)" << endl;
			cout << "\n";
			task_4();
			cout << endl;
			break;
		case 5:
			cout << endl << "(^-^) ============  Задание 5  ============ (^-^)" << endl;
			cout << "\n";
			task_5();
			cout << endl;
			break;
		}
		cout << "Введите номер желаемой задачи (0 - выход): ";
		cin >> num;
		while (num != 0 && (num < 1 || num>5)) {
			cout << "Введите цифру 1-5: ";
			cin >> num;
		}
	}

	cout << endl << "(x-x) ============ конец проги ============ (x-x)" << endl;
	cout << endl << "byeee ~" << endl;
}
