#ifndef lpfparser_H
#define lpfparser_H
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <sstream>
#include <vector> 
using namespace std;

namespace lpf {
	class LPFParser {
	public:
		void Create(string path);
		string Search(string variable, string language);
		string string_search(string string_value, string language);
		vector<string> get_languages();
		vector<vector<string> > get_strings();
		vector<string> get_variables();
	private:
		vector<string> languages_main;
		vector<vector<string> >strings_main;
		vector<string> data_main;
		int number_string_main;
		int number_language_main;
	};
}
#endif