#pragma once

#include <iostream>

#if __GNUC__ >= 4	// Linux
#define DYNAMIC_API	__attribute__((visibility("default")))
#define IMPORT		__attribute__((visibility("hidden")))

/*
Name            FG  BG
Black           30  40
Red             31  41
Green           32  42
Yellow          33  43
Blue            34  44
Magenta         35  45
Cyan            36  46
White           37  47
Bright Black    90  100
Bright Red      91  101
Bright Green    92  102
Bright Yellow   93  103
Bright Blue     94  104
Bright Magenta  95  105
Bright Cyan     96  106
Bright White    97  107

тут 31 это цвет, 40 фон
\033[31;40m
отменить установку цвета
\033[0m
*/
namespace col
{
	DYNAMIC_API inline const char* cancel("\033[0m");

	DYNAMIC_API inline const char* black("\033[30m");
	DYNAMIC_API inline const char* red("\033[31m");
	DYNAMIC_API inline const char* green("\033[32m");
	DYNAMIC_API inline const char* yellow("\033[33m");
	DYNAMIC_API inline const char* blue("\033[34m");
	DYNAMIC_API inline const char* magenta("\033[35m");
	DYNAMIC_API inline const char* cyan("\033[36m");
	DYNAMIC_API inline const char* white("\033[37m");
	DYNAMIC_API inline const char* br_black("\033[90m");
	DYNAMIC_API inline const char* br_red("\033[91m");
	DYNAMIC_API inline const char* br_green("\033[92m");
	DYNAMIC_API inline const char* br_yellow("\033[93m");
	DYNAMIC_API inline const char* br_blue("\033[94m");
	DYNAMIC_API inline const char* br_magenta("\033[95m");
	DYNAMIC_API inline const char* br_cyan("\033[96m");
	DYNAMIC_API inline const char* br_white("\033[97m");
}
DYNAMIC_API void consoleCol(const char* color);

#elif _WIN32		// Windows
#include <Windows.h>
#include <io.h>
#include <fcntl.h>

const int errorsetmodeout = _setmode(_fileno(stdout), _O_U16TEXT);
const int errorsetmodeinp = _setmode(_fileno(stdin), _O_U16TEXT);
const int errorsetmodeerr = _setmode(_fileno(stderr), _O_U16TEXT);

#ifdef SecFun_lib_EXPORTS
	#define DYNAMIC_API __declspec(dllexport)
#else
	#define DYNAMIC_API __declspec(dllimport)
#endif

/*
	00 - черный
	01 - синий
	02 - зеленый
	03 - голубой
	04 - красный
	05 - фиолетовый
	06 - желтый
	07 - белый
	----
	08 - серый
	09 - ярк. синий
	10 - ярк. зеленый
	11 - ярк. голубой
	12 - ярк. красный
	13 - ярк. фиолетовый
	14 - ярк. желтый
	15 - ярк. белый
*/
namespace col
{
	DYNAMIC_API inline constexpr WORD cancel(7);

	DYNAMIC_API inline constexpr WORD black(0);
	DYNAMIC_API inline constexpr WORD blue(1);
	DYNAMIC_API inline constexpr WORD green(2);
	DYNAMIC_API inline constexpr WORD cyan(3);
	DYNAMIC_API inline constexpr WORD red(4);
	DYNAMIC_API inline constexpr WORD magenta(5);
	DYNAMIC_API inline constexpr WORD yellow(6);
	DYNAMIC_API inline constexpr WORD white(7);
	DYNAMIC_API inline constexpr WORD br_black(8);
	DYNAMIC_API inline constexpr WORD br_blue(9);
	DYNAMIC_API inline constexpr WORD br_green(10);
	DYNAMIC_API inline constexpr WORD br_cyan(11);
	DYNAMIC_API inline constexpr WORD br_red(12);
	DYNAMIC_API inline constexpr WORD br_magenta(13);
	DYNAMIC_API inline constexpr WORD br_yellow(14);
	DYNAMIC_API inline constexpr WORD br_white(15);
}
DYNAMIC_API void consoleCol(WORD color);

#else
#error "-= Unknow OS =-"
#endif


DYNAMIC_API void printHeader(std::wstring_view str);	// заголовок (std::string_view - std17)
