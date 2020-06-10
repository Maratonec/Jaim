#include <iostream>
#include <fstream>
#include <string>
#include <clocale>

int main()
{
	using namespace std;
	string copyright;
	ifstream file_load("info.txt");

	setlocale(LC_ALL, "");

	if (file_load.is_open()) {
		getline(file_load, copyright);
			cout << copyright << "\n";

	}
	else cout << "Error when reading file";

	return 0;
}
