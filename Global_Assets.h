#pragma once
#include <string>

class Global_Assets
{
public:
	static char* FF_FONT_PATH;
	static const int FF_FONT_SIZE = 28;

	Global_Assets();
	~Global_Assets();

	static void openFont();
	static void closeFont();
};

