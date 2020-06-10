#include <iostream>

void load_message(int length)
{
	for (int i = 0; i < length; i++) {
		std::cout << i << ".." << std::endl << std::endl;
	}

	std::cout << "Jiam Browser core loaded\n";
}

int main()
{
	int length;
	std::cin >> length;
	load_message(length);

	return 0;
}
