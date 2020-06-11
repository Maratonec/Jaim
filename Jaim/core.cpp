#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <sstream>
#include <vector> 

using namespace std;

int main()
{
	//load file and settings
	ifstream file_load("Resources/info.lpf");
	setlocale(LC_ALL, "");

	if (file_load.is_open()) {

		//variables
		string line;
		string temp = "";
		string number_language;
		string number_string;

		//get values from first line (number of languges and sentences)
		getline(file_load, line);
		stringstream ss(line);
		getline(ss, number_language, '!');
		getline(ss, number_string);

		//create arrays
		int temp_language = stoi(number_language);
		int temp_string = stoi(number_string);
		vector<vector<string> > strings(temp_string, vector<string>(temp_language));
		vector<string>languages(temp_language);
		vector<string>data(temp_string);

		//getting values (languages) from line 2
		string temp_line = line;
		getline(file_load, line);
		int n = count(line.begin(), line.end(), '?');
		n++;
		ss.str(line);
		ss.clear();
		string temp_value;
		for (int i = 0; i < n; i++) {
			getline(ss, languages[i], '?');
			cout << languages[i] << " ";
		}
		

	}
	else cout << "Error when reading file";


	return 0;
}
