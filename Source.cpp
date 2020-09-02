//1
//Проверить, есть ли в матрице хотя бы одна строка, содержащая отрицательный элемент, и найти ее номер. 
	//Все элементы столбца с таким же номером уменьшить вдвое.
#include <iostream>
#include<stdio.h>
using namespace std;
float** Builder(int, int,int&);
void Counter(float **,int,int);
void Final(float**, int, int);
int main()
{

	setlocale(LC_CTYPE, "ru");
	int sizeY, sizeX, count = 0;
	cout << "Введите размеры матрицы по оси Оy: ", cin >> sizeY;
	cout << "Введите размеры матрицы по оси Оx: ", cin >> sizeX;

	cout << "Начальная матрица: " << endl;
	float** matrix = Builder(sizeX, sizeY, count);
	Counter(matrix, count, sizeX);

	cout << endl << "Конечная матрица: " << endl;
	Final(matrix, sizeX, sizeY);

	for (int i = 0; i < sizeY; i++)
		delete[] matrix[i];
	delete[] matrix;
	return 0;
}

float** Builder(int sizeX, int sizeY,int &count)
{

	float** matrix = new float* [sizeY];
	for (int i = 0; i < sizeY; i++)
	{
		*(matrix + i) = new float[sizeX];

		for (int j = 0; j < sizeX; j++)
		{
			*(*(matrix + i) + j) = (-10 + rand() % 45) % 10;
			cout << *(*(matrix + i) + j) << '\t';
			if (*(*(matrix + i) + j) < 0)
				count=i+1;
		}
		cout << endl;
	}
	
	return matrix;
}

void Counter(float**matrix,int count, int sizeX)
{

	if (count > 0)
	{
		cout << endl << "Строка под номером " << count << " имеет отрицательный элемент " << endl;

		for (int i = 0, j = count - 1; i < sizeX; i++)
			* (*(matrix + i) + j) /= 2;
	}
	else
		cout << "В матрице нет отрицательных элементов" << endl;
	
}

void Final(float** matrix, int sizeX, int sizeY)
{
	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++)
		{
			cout << *(*(matrix + i) + j) << " ";
		}
		cout << endl;
	}

}