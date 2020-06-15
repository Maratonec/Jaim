# Jaim
Powerfull standard c++ library for making everything much easier.
Every folder in CAPS contains only test code. You can use it as example project.
## LPFParser
With LPFParser you can simply load data from .lpf files (language pack file) to load your translations from file.
#### Setup
To work with lpfparser you have to include lpfparser.h that is in folder with lpfparser.cpp folder ```#include "lpfparser.h"``` and optionaly use namespace lpf ```using namespace lpf;"```
#### Classes
Firstly you need to call ```Create();``` function that will parse all the data from file to arrays. It's argument is the path where the .lpf file is. Then there is ```Search():``` function in which you have 2 arguments. The variable name of the string you want to have and the language. And last important function is ```string_search();``` There you have two arguments: the string that you want to translate (must be in .lpf file) and language you want to translate it.
#### Example program
```
#include "../LPFParser/lpfparser.h"
using namespace lpf;
int main() {
	LPFParser lpf;
	lpf.Create("FILES/info.lpf");
	string test1 = lpf.Search("start", "en");
	string test2 = lpf.string_search("Hello, how are you?", "cs");
	cout << test1 << "\n";
	cout << test2;
	return 0;
}
```
#### Example .lpf file (comments not supported in .lpf file)
```
3~2 //number of languages and number of strings (~ is separator)
en~cs~de //names of languages
v=something in en~something in cs~something in de //variable representing the string (separator =) strings in same order as the order of languages on line 2 (~ separator)
hello=Hello, how are you?~Ahoj jak se máš?~Hallo, wie geht es dir
```
