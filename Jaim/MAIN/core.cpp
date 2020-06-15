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