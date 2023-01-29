#include "SecondaryFunction.h"

// заголовок
void printHeader(std::wstring_view str)
{
#ifdef _WIN32
	std::system("cls");
#elif __GNUC__
	std::system("clear");
	setlocale(LC_ALL, "ru_RU.utf8");
#endif

	consoleCol(col::br_green);
	std::wcout << str << "\n";
	for (auto i = 0; i < str.length(); ++i) std::wcout << '-';
	std::wcout << "\n\n";
	consoleCol(col::cancel);
}

void consoleCol(COLOR color)
{
#ifdef _WIN32
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
#elif __GNUC__
	std::wcout << color;
#endif
}
