#include "SecondaryFunction.h"
/*
*/
#if _WIN32		// Windows
const int errorsetmodeout = _setmode(_fileno(stdout), _O_U16TEXT);
const int errorsetmodeinp = _setmode(_fileno(stdin), _O_U16TEXT);
const int errorsetmodeerr = _setmode(_fileno(stderr), _O_U16TEXT);
#endif

// цвет в консоли
void consoleCol(COLOR color)
{
#ifdef _WIN32
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
#elif __GNUC__
	std::wcout << color;
#endif
}

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

// Convert an ANSI string to a wide Unicode String
std::wstring ansi2unicode(std::string_view str)
{
	int size_needed = MultiByteToWideChar(CP_ACP, 0, &str[0], (int)str.size(), NULL, 0);
	std::wstring wstrTo(size_needed, 0);
	MultiByteToWideChar(CP_ACP, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
	return wstrTo;
}
