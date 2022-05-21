// TestGr.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "PrintEr.h"

using namespace sf;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	/*параметры фигуры*/
	unsigned short size;
	unsigned short color;
	unsigned short figure;
	
	PrintEr PrintFigure;

	std::cout << "Вывод фигур на экран\n";
	while (1)
	{

		/*ввод параметров*/
		std::cout << "\nВыберите фигуру: |0 - КРУГ|      |1 - КВАДРАТ|      |2 - ТРЕУГОЛЬНИК|\n>";
		cin >> figure;
		/*проверить корректность параметров*/
		if (figure > 2 || cin.fail())
		{
			cin.clear();
			cin.ignore();
			std::cout << "Ошибка ввода\n";
			continue;
		}
		std::cout << "Выберите цвет:   |0 - КРАСНЫЙ|   |1 - ЗЕЛЕНЫЙ|      |2 - СИНИЙ|\n>";
		cin >> color;
		if (color > 2 || cin.fail())
		{
			cin.clear();
			cin.ignore();
			std::cout << "Ошибка ввода\n";
			continue;
		}
		std::cout << "Выберите размер: |0 - МАЛЕНЬКИЙ| |1 - СРЕДНИЙ|      |2 - БОЛЬШОЙ|\n>";
		cin >> size;
		if (size > 2 || cin.fail())
		{
			cin.clear();
			cin.ignore();
			std::cout << "Ошибка ввода\n";
			continue;
		}

		/*название фигуры*/
		switch (size)
		{
		case 0:
			std::cout << "МАЛЕНЬКИЙ ";
			break;
		case 1:
			std::cout << "СРЕДНИЙ ";
			break;
		case 2:
			std::cout << "БОЛЬШОЙ ";
			break;
		default:
			break;
		}

		switch (color)
		{
		case 0:
			std::cout << "КРАСНЫЙ ";
			break;
		case 1:
			std::cout << "ЗЕЛЕНЫЙ ";
			break;
		case 2:
			std::cout << "СИНИЙ ";
			break;
		default:
			break;
		}

		switch (figure)
		{
		case 0:
			std::cout << "КРУГ ";
			break;
		case 1:
			std::cout << "КВАДРАТ ";
			break;
		case 2:
			std::cout << "ТРЕУГОЛЬНИК ";
			break;
		default:
			break;
		}

		std::cout << endl;

		/*отрисовка фигуры*/
		PrintFigure.PresetParam(figure, color, size);
		PrintFigure.PrintIt();
	}
	return 0;
}
