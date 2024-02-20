#include "SecondaryFunction.h"

#if _WIN32		// Windows
const int errorsetmodeout = _setmode(_fileno(stdout), _O_U16TEXT);
const int errorsetmodeinp = _setmode(_fileno(stdin), _O_U16TEXT);
const int errorsetmodeerr = _setmode(_fileno(stderr), _O_U16TEXT);
#endif

// цвет в консоли
void setConsoleCol(COLOR color)
{
#ifdef _WIN32
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
#elif __GNUC__
	std::wcout << color;
#endif
}

// получение текущего положения курсора
COORD getConsolePos()
{
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
	{
		return cbsi.dwCursorPosition;
	}
	else
	{
		// The function failed. Call GetLastError() for details.
		COORD invalid = { 0, 0 };
		return invalid;
	}
}

// установка положения курсора
void setConsolePos(const COORD coord)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// заголовок
void printHeader(const std::wstring& str)
{
#ifdef _WIN32
	std::system("cls");
#elif __GNUC__
	std::system("clear");
	setlocale(LC_ALL, "ru_RU.utf8");
#endif

	setConsoleCol(col::br_green);
	std::wcout << str << "\n";
	for (auto i = 0; i < str.length(); ++i) std::wcout << '-';
	std::wcout << "\n\n";
	setConsoleCol(col::cancel);
}

// Convert an ANSI string to a wide Unicode String
// https://gist.github.com/rosasurfer/33f0beb4b10ff8a8c53d943116f8a872#file-conversion-cpp
std::wstring ansi2wide(const std::string& str)
{
#ifdef _WIN32
	int size_needed = MultiByteToWideChar(CP_ACP, 0, &str[0], (int)str.size(), NULL, 0);
	std::wstring wstrTo(size_needed, 0);
	MultiByteToWideChar(CP_ACP, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
	return wstrTo;
#elif __GNUC__
	// convert UTF-8 string to wstring
	std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
    return myconv.from_bytes(str);
#endif
}
/*
std::string wide2multi(const std::wstring& str)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t> > myconv;
	return myconv.to_bytes(str);
}
*/

// Convert an UTF8 string to a wide Unicode String
std::wstring utf2wide(const std::string &str)
{
#ifdef _WIN32
	int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
	std::wstring wstrTo(size_needed, 0);
	MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
	return wstrTo;
#elif __GNUC__
#endif
}

// Convert a wide Unicode string to an UTF8 string
std::string wide2utf(const std::wstring& wstr)
{
#ifdef _WIN32
	int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
	std::string strTo(size_needed, 0);
	WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &strTo[0], size_needed, NULL, NULL);
	return strTo;
#elif __GNUC__
#endif
}

// Convert an wide Unicode string to ANSI string
std::string wide2ansi(const std::wstring &wstr)
{
#ifdef _WIN32
	int size_needed = WideCharToMultiByte(CP_ACP, 0, &wstr[0], -1, NULL, 0, NULL, NULL);
	std::string strTo(size_needed, 0);
	WideCharToMultiByte(CP_ACP, 0, &wstr[0], (int)wstr.size(), &strTo[0], size_needed, NULL, NULL);
	return strTo;
#elif __GNUC__
#endif
}
