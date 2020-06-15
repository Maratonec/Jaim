#include "lpfparser.h"
using namespace std;
namespace lpf {
	extern vector<string> languages_main;
	extern vector<vector<string> >strings_main;
	extern vector<string> data_main;
	extern int number_string_main;
	extern int number_language_main;

	void LPFParser::Create(string path) {
		//load file and settings
		ifstream file_load(path);
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
			getline(ss, number_language, '~');
			getline(ss, number_string);

			//create arrays
			int temp_language = stoi(number_language);
			long int temp_string = stoi(number_string);
			number_string_main = temp_string;
			number_language_main = temp_language;
			vector<vector<string> > strings(temp_string, vector<string>(temp_language));
			vector<string>languages(temp_language);
			vector<string>data(temp_string);

			//getting values (languages) from line 2
			string temp_line = line;
			getline(file_load, line);
			int n = count(line.begin(), line.end(), '~');
			n++;
			ss.str(line);
			ss.clear();
			string temp_value;
			for (int i = 0; i < n; i++) {
				getline(ss, languages[i], '~');
			}

			//get the languge strings
			for (int k = 0; k < temp_string; k++) {
				getline(file_load, line);
				ss.str(line);
				ss.clear();
				getline(ss, data[k], '=');
				for (int j = 0; j < temp_language; j++) {
					getline(ss, strings[k][j], '~');
				}
			}

			//copy to global arrays
			copy(languages.begin(), languages.end(), back_inserter(languages_main));
			copy(strings.begin(), strings.end(), back_inserter(strings_main));
			copy(data.begin(), data.end(), back_inserter(data_main));

		}
		else cout << "Error when reading file";

	}
	//search for string in language
	string LPFParser::Search(string variable, string language) {

		int language_index;
		language_index = distance(languages_main.begin(), find(languages_main.begin(), languages_main.end(), language));
		if (language_index == languages_main.size()) {
			return "Language " + language + " not found";
		}
		else {
			for (int i = 0; i < number_string_main; i++) {
				if (data_main[i] == variable) {
					return strings_main[i][language_index];
				}
			}
			return "Variable " + variable + " not found";
		}

	}

	string LPFParser::string_search(string string_value, string language) {

		int language_index;
		language_index = distance(languages_main.begin(), find(languages_main.begin(), languages_main.end(), language));
		if (language_index == languages_main.size()) {
			return "Language " + language + " not found";
		}
		for (int i = 0; i < number_string_main; i++) {
			for (int j = 0; j < number_language_main; j++) {
				if (strings_main[i][j] == string_value) {
					return strings_main[i][language_index];
				}
			}
		}
		return "String: " + string_value + ", not found";

	}


	//get languages
	vector<string> LPFParser::get_languages() {
		return languages_main;
	}

	//get strings
	vector<vector<string> > LPFParser::get_strings() {
		return strings_main;
	}

	//get data
	vector<string> LPFParser::get_variables() {
		return data_main;
	}


}