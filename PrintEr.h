#pragma once



#define SIZE_SMALL		0
#define SIZE_MEDIUM		1
#define SIZE_BIG		2

#define COLOR_RED		0
#define COLOR_GREEN		1
#define COLOR_BLUE		2

#define CIRCLE			0
#define SQUARE			1
#define TRIANGLE		2


#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

class PrintEr:private CircleShape, private RectangleShape
{
public:
	PrintEr();
	void PresetParam(short Figure, short Color, short Size);
	bool PrintIt();
	~PrintEr();

private:
	void Triangle();
	void Square();
	void Circle();
	void SetWinSize();
	short size;/*������*/
	short color;/*����*/
	short figure;/*������*/
	int WinSize;/*������ ����*/
	/*RGB*/
	std::vector<Color>const RGB = { Color(255,0,0), Color(0,255,0), Color(0,0,255) };
	/*���� ������"���"*/
	RenderWindow window;
	
};

