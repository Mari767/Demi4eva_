#include "class_Information.h"
#include <iomanip>

int main()
{
	setlocale(LC_ALL, "ru");

	string name = "";
	char typ;
	float nom;
	int colvo;

	const int Size = 3;

	Information object[Size];

	cout << "Setter \n";
	cout << "Введите данные: \nОбозначение, Тип, Номинал, Количество" << endl;
	for (int i = 0; i < Size; i++) {
		cin >> name;
		cin >> typ;
		cin >> nom;
		cin >> colvo;
		object[i].set_inform(name, typ, nom, colvo);
	}
	cout << "\n ----------------------------------------------\n";
	cout << "Show\n";
	for (int i = 0; i < Size; i++) {
		object[i].show_inform();
	}
	cout<<"\n ----------------------------------------------\n";

	cout << "Get\n";
	cout << "Обозначение    Тип   Номинал   \t   Количество" << endl;
	for (int i = 0; i < Size; i++) {
		object[i].get_inform(name, typ, nom, colvo);
		cout <<name << "\t\t" << typ << "\t"  << nom << "\t\t"  << colvo << endl ;
	}

	return 0;
}

