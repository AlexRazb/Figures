#include "PrintEr.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

PrintEr::PrintEr() :figure(CIRCLE), color(COLOR_RED), size(SIZE_SMALL)
{
	SetWinSize();
}


void PrintEr::PresetParam(short Figure, short Color, short Size)
{

	switch (Figure)
	{
	case CIRCLE:
	case SQUARE:
	case TRIANGLE:
		figure = Figure;
		break;
	default:
		figure = CIRCLE;
		break;
	}

	switch (Color)
	{
	case COLOR_GREEN:
	case COLOR_RED:
	case COLOR_BLUE:
		color = Color;
		break;
	default:
		color = COLOR_RED;
		break;
	}

	switch (Size)
	{
	case SIZE_SMALL:
	case SIZE_MEDIUM:
	case SIZE_BIG:
		size = Size;
		break;
	default:
		size = SIZE_SMALL;
		break;
	}

	SetWinSize();

}

/*вывести фигуру на экран*/
bool PrintEr::PrintIt()
{
	/*окно*/
	window.create(VideoMode(WinSize, WinSize), "Figure!", Style::Close);
	window.setVerticalSyncEnabled(1);

	/*окно открыто*/
	while (window.isOpen())
	{
		/*события*/
		Event event;
		while (window.pollEvent(event))
		{
			
			if (event.type == Event::Closed)
			{
				window.close();
				return 1;/**/
			}
		}
		/*цвет фона*/
		window.clear(Color::Color(190,190,190));
		/*фигура*/
		switch (figure)
		{

			case CIRCLE:
			Circle();
			break;

			case SQUARE:
			Square();
			break;

			case TRIANGLE:
			Triangle();
			break;
		
			default:
				break;
		}

		window.display();
	}
	return 1;
}

PrintEr::~PrintEr()
{

}

void PrintEr::SetWinSize()
{
	WinSize = (size * 1) *200 + 200;
}

void PrintEr::Triangle()
{
	/*треугольник*/
	this->CircleShape::setRadius(WinSize / 2);
	this->CircleShape::setPointCount(3);
	this->CircleShape::setPosition(Vector2f(0, WinSize / 10));
	this->CircleShape::setFillColor(RGB[color]);
	window.draw(CircleShape(*this));
}

void PrintEr::Square()
{
	/*квадрат*/
	this->RectangleShape::setSize(Vector2f(WinSize - 20, WinSize - 20));
	this->RectangleShape::setPosition(Vector2f(10, 10));
	this->RectangleShape::setFillColor(RGB[color]);
	window.draw(RectangleShape(*this));
	
}

void PrintEr::Circle()
{
	/*круг*/
	this->CircleShape::setRadius(WinSize / 2);
	this->CircleShape::setPointCount(100);
	this->CircleShape::setPosition(Vector2f(0, 0));
	this->CircleShape::setFillColor(RGB[color]);
	window.draw(CircleShape(*this));
}