#include "SecondaryFunction.h"

// заголовок
void printHeader(std::wstring_view str)
{
#ifdef _WIN32
	int err = _setmode(_fileno(stdout), _O_U16TEXT);
	err = _setmode(_fileno(stdin), _O_U16TEXT);
	err = _setmode(_fileno(stderr), _O_U16TEXT);
	//std::system("cls");
#else
	setlocale(LC_ALL, "ru_RU.utf8");
	//std::system("clear");
#endif

	consoleCol(col::br_green);
	std::wcout << str << "\n";
	for (auto i = 0; i < str.length(); ++i) std::wcout << L"-";
	std::wcout << "\n\n";
	consoleCol(col::cancel);
}

#ifdef _WIN32
void consoleCol(WORD color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

#else
void consoleCol(const char* color)
{
	std::wcout << color;
}
#endif
