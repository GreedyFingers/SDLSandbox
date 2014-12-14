#pragma once
#include <string>

class Global_Assets
{
public:
	static const char* FF_FONT_PATH;
	static const int FF_FONT_SIZE = 28;
	static const int ENTIRE_TEXTURE = 0;
	//slows down GameObjects specifically
	static const int _damping = 50;

	Global_Assets();
	~Global_Assets();

	static void openFont();
	static void closeFont();
};

