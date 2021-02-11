#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
using namespace std;

void printMatrix(int** matrix, int raw, int column)
{
	for (int i = 0; i < raw; i++)
	{
		for (int j = 0; j < column; j++)
			cout << matrix[i][j] << "\t";
		cout << "\n";
	}
}

int readSizeOfMatrix(string message)
{
	int dimension;
	do
	{
		cout << message << endl;
		cin >> dimension;
	} while (dimension < 0);

	return dimension;
}


int** memoryAllocationForMatrix(int raw, int column)
{
	int** matrix = new int* [raw];
	for (int i = 0; i < raw; i++)
		matrix[i] = new int[column];
	return matrix;
}

void fillingMatrixUser(int** matrix, int raw, int column)
{
	for (int i = 0; i < raw; i++)
		for (int j = 0; j < column; j++)
			cin >> matrix[i][j];
}

void fillingMatrixRandom(int** matrix, int raw, int column)
{
	for (int i = 0; i < raw; i++)
		for (int j = 0; j < column; j++)
			matrix[i][j] = rand() % 10;
}

int  selectionOfCoefficient(int raw1, int column1, int raw2, int column2)
{
	int maxDim = max(max(raw1, column1), max(raw2, column2));
	int l = 2;
	while (l < maxDim)
		l *= 2;
	return l;
}
int** matrixCasting(int** matrix, int raw, int column, int castingCoefficient)
{

	int** castingMatrix = new int* [castingCoefficient];
	for (int i = 0; i < castingCoefficient; i++)
	{
		castingMatrix[i] = new int[castingCoefficient];
		for (int j = 0; j < castingCoefficient; j++)
			castingMatrix[i][j] = 0;
	}

	for (int i = 0; i < raw; i++)
		for (int j = 0; j < column; j++)
			castingMatrix[i][j] = matrix[i][j];

	for (int i = 0; i < raw; i++)
		delete[] matrix[i];
	return castingMatrix;

}
//n и m -the coefficients that are added to i and j
int** partitioningOfMatrix(int** matrix, int n, int m, int castingCoefficient)
{
	int** partMatrix = new int* [castingCoefficient / 2];
	for (int i = 0; i < castingCoefficient / 2; i++)
	{
		partMatrix[i] = new int[castingCoefficient / 2];
		for (int j = 0; j < castingCoefficient / 2; j++)
			partMatrix[i][j] = matrix[i + n][j + m];
	}
	return partMatrix;
}

int** creatingIntermediateMatrix(int castingCoefficient)
{
	int** interMatrix = new int* [castingCoefficient / 2];
	for (int i = 0; i < castingCoefficient / 2; i++)
	{
		interMatrix[i] = new int[castingCoefficient / 2];
	}
	return interMatrix;
}

void printResult(int** resultMatrix, int castingCoefficient)
{
	int x, f = 100, s = 100; //some coefficientы for solution
	for (int i = 0; i < castingCoefficient; i++)
	{
		x = 0;
		for (int j = 0; j < castingCoefficient; j++)
		{
			if (resultMatrix[i][j] != 0)
			{
				x++;
				f = 100;
				s = 100;
			}
		}
		if (x == 0 && i < f)
		{
			f = i;
			s = i;
		}
	}
	printMatrix(resultMatrix, f, s);
}
void fillingZero(int** matrix, int raw, int column)
{
	for (int i = 0; i < raw; i++)
		for (int j = 0; j < column; j++)
			matrix[i][j] = 0;
}

void main()
{
	srand(time(NULL));
	int raw1, column1, raw2, column2, choice, castingCoefficient;
	system("chcp 1251");
	cout << "Вас приветствует программа" << endl <<
		"быстрого перемножения матриц методом Штрассена\n\n";

	///////////////////////////////////////////////////////////////////////////////
	//////////////////// User input of matrix sizes ////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	raw1 = readSizeOfMatrix("Введите количество строк первой матрицы");
	column1 = readSizeOfMatrix("Введите количество столбцов первой матрицы");
	raw2 = readSizeOfMatrix("Введите количество строк второй матрицы");
	column2 = readSizeOfMatrix("Введите количество столбцов второй матрицы");

	int** matrix1; int** matrix2;
	matrix1 = memoryAllocationForMatrix(raw1, column1);
	matrix2 = memoryAllocationForMatrix(raw2, column2);

	///////////////////////////////////////////////////////////////////////////////
	////////////////Selection of filling method and filling of matrices///////////////////
	///////////////////////////////////////////////////////////////////////////////

	do
	{
		cout << "Выберите способ заполнения матриц\n" <<
			"1 - Вручную \n2 - Случайным образом\n";
		cin >> choice;
	} while (choice < 1 || choice > 2);
	switch (choice)
	{
	case 1:
		fillingMatrixUser(matrix1, raw1, column1);
		fillingMatrixUser(matrix2, raw2, column2);
		cout << "Матрица 1" << endl;
		printMatrix(matrix1, raw1, column1);
		cout << "Матрица 2" << endl;
		printMatrix(matrix2, raw2, column2);
		break;
	case 2:
		fillingMatrixRandom(matrix1, raw1, column1);
		fillingMatrixRandom(matrix2, raw2, column2);
		cout << "Матрица 1" << endl;
		printMatrix(matrix1, raw1, column1);
		cout << "Матрица 2" << endl;
		printMatrix(matrix2, raw2, column2);
		break;
	}

	///////////////////////////////////////////////////////////////////////////////
	/////////////////Bringing matrices to the required size////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	castingCoefficient = selectionOfCoefficient(raw1, column1, raw2, column2);
	int** castMatrix1; int** castMatrix2;

	matrix1 = matrixCasting(matrix1, raw1, column1, castingCoefficient);
	matrix2 = matrixCasting(matrix2, raw1, column1, castingCoefficient);
	raw1 = castingCoefficient; column1 = castingCoefficient; raw2 = castingCoefficient; column2 = castingCoefficient;
	cout << "\nПриведенные матрицы\n";
	cout << "\nМатрица 1\n\n";
	printMatrix(matrix1, raw1, column1);
	cout << "\nМатрица 2\n\n";
	printMatrix(matrix2, raw2, column2);

	///////////////////////////////////////////////////////////////////////////////
	///////////////Dividing matrices into submatrices and filling them in//////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** partMatrix1 = partitioningOfMatrix(matrix1, 0, 0, castingCoefficient);
	int** partMatrix2 = partitioningOfMatrix(matrix1, 0, castingCoefficient / 2, castingCoefficient);
	int** partMatrix3 = partitioningOfMatrix(matrix1, castingCoefficient / 2, 0, castingCoefficient);
	int** partMatrix4 = partitioningOfMatrix(matrix1, castingCoefficient / 2, castingCoefficient / 2, castingCoefficient);

	int** partMatrix5 = partitioningOfMatrix(matrix2, 0, 0, castingCoefficient);
	int** partMatrix6 = partitioningOfMatrix(matrix2, 0, castingCoefficient / 2, castingCoefficient);
	int** partMatrix7 = partitioningOfMatrix(matrix2, castingCoefficient / 2, 0, castingCoefficient);
	int** partMatrix8 = partitioningOfMatrix(matrix2, castingCoefficient / 2, castingCoefficient / 2, castingCoefficient);

	///////////////////////////////////////////////////////////////////////////////
	////////////////////////Creating intermediate matrices//////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** interMatrix1 = creatingIntermediateMatrix(castingCoefficient);
	int** interMatrix2 = creatingIntermediateMatrix(castingCoefficient);
	int** interMatrix3 = creatingIntermediateMatrix(castingCoefficient);
	int** interMatrix4 = creatingIntermediateMatrix(castingCoefficient);
	int** interMatrix5 = creatingIntermediateMatrix(castingCoefficient);
	int** interMatrix6 = creatingIntermediateMatrix(castingCoefficient);
	int** interMatrix7 = creatingIntermediateMatrix(castingCoefficient);
	

	///////////////////////////////////////////////////////////////////////////////
	////////////////////Calculating intermediate matrix values///////////////////
	///////////////////////////////////////////////////////////////////////////////

	fillingZero(interMatrix1, castingCoefficient / 2, castingCoefficient / 2);
	fillingZero(interMatrix2, castingCoefficient / 2, castingCoefficient / 2);
	fillingZero(interMatrix3, castingCoefficient / 2, castingCoefficient / 2);
	fillingZero(interMatrix4, castingCoefficient / 2, castingCoefficient / 2);
	fillingZero(interMatrix5, castingCoefficient / 2, castingCoefficient / 2);
	fillingZero(interMatrix6, castingCoefficient / 2, castingCoefficient / 2);
	fillingZero(interMatrix7, castingCoefficient / 2, castingCoefficient / 2);

	for (int i = 0; i < castingCoefficient / 2; i++)
	{
		for (int j = 0; j < castingCoefficient / 2; j++)
		{
			for (int z = 0; z < castingCoefficient / 2; z++)
			{
				interMatrix1[i][j] += (partMatrix1[i][z] + partMatrix4[i][z]) * (partMatrix5[z][j] + partMatrix8[z][j]);
				interMatrix2[i][j] += (partMatrix3[i][z] + partMatrix4[i][z]) * partMatrix5[z][j];
				interMatrix3[i][j] += partMatrix1[i][z] * (partMatrix6[z][j] - partMatrix8[z][j]);
				interMatrix4[i][j] += partMatrix4[i][z] * (partMatrix7[z][j] - partMatrix5[z][j]);
				interMatrix5[i][j] += (partMatrix1[i][z] + partMatrix2[i][z]) * partMatrix8[z][j];
				interMatrix6[i][j] += (partMatrix3[i][z] - partMatrix1[i][z]) * (partMatrix5[z][j] + partMatrix6[z][j]);
				interMatrix7[i][j] += (partMatrix2[i][z] - partMatrix4[i][z]) * (partMatrix7[z][j] + partMatrix8[z][j]);
			}

		}
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////Creation of auxiliary matrices/////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** partMatrix9 = creatingIntermediateMatrix(castingCoefficient);
	int** partMatrix10 = creatingIntermediateMatrix(castingCoefficient);
	int** partMatrix11 = creatingIntermediateMatrix(castingCoefficient);
	int** partMatrix12 = creatingIntermediateMatrix(castingCoefficient);
	

	///////////////////////////////////////////////////////////////////////////////
	////////////Counting the values ​​of auxiliary matrices from intermediate///////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < castingCoefficient / 2; i++)
	{
		for (int j = 0; j < castingCoefficient / 2; j++)
		{
			partMatrix9[i][j] = interMatrix1[i][j] + interMatrix4[i][j] - interMatrix5[i][j] + interMatrix7[i][j];
			partMatrix10[i][j] = interMatrix3[i][j] + interMatrix5[i][j];
			partMatrix11[i][j] = interMatrix2[i][j] + interMatrix4[i][j];
			partMatrix12[i][j] = interMatrix1[i][j] - interMatrix2[i][j] + interMatrix3[i][j] + interMatrix6[i][j];
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////Creating the resulting matrix/////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** resultMatrix = new int* [castingCoefficient];
	for (int i = 0; i < castingCoefficient; i++)
	{
		resultMatrix[i] = new int[castingCoefficient];
	}

	///////////////////////////////////////////////////////////////////////////////
	///////Entering information from auxiliary matrices into the resulting/////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < castingCoefficient / 2; i++)
	{
		for (int j = 0; j < castingCoefficient / 2; j++)
		{
			resultMatrix[i][j] = partMatrix9[i][j];
			resultMatrix[i][j + castingCoefficient / 2] = partMatrix10[i][j];
			resultMatrix[i + castingCoefficient / 2][j] = partMatrix11[i][j];
			resultMatrix[i + castingCoefficient / 2][j + castingCoefficient / 2] = partMatrix12[i][j];
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	////////////////Outputting the final answer /////////////////////
	///////////////////////////////////////////////////////////////////////////////
	printResult(resultMatrix, castingCoefficient);

	///////////////////////////////////////////////////////////////////////////////
	/////////////////////Clearing heap///////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	
	for (int i = 0; i < raw1; i++)
		delete[] matrix1[i];
	for (int i = 0; i < raw2; i++)
		delete[] matrix2[i];
	for (int i = 0; i < castingCoefficient / 2; i++)
	{
		delete[] partMatrix1[i];
		delete[] partMatrix2[i];
		delete[] partMatrix3[i];
		delete[] partMatrix4[i];
		delete[] partMatrix5[i];
		delete[] partMatrix6[i];
		delete[] partMatrix7[i];
		delete[] partMatrix8[i];
		delete[] partMatrix9[i];
		delete[] partMatrix10[i];
		delete[] partMatrix11[i];
		delete[] partMatrix12[i];
		delete[] interMatrix1[i];
		delete[] interMatrix2[i];
		delete[] interMatrix3[i];
		delete[] interMatrix4[i];
		delete[] interMatrix5[i];
		delete[] interMatrix6[i];
		delete[] interMatrix7[i];
	}
	delete[] matrix1, matrix2;
	delete[] partMatrix1, partMatrix2, partMatrix3, partMatrix4, partMatrix5, partMatrix6, partMatrix7, partMatrix8, partMatrix9, partMatrix10, partMatrix11, partMatrix12;
	delete[] interMatrix1, interMatrix2, interMatrix3, interMatrix4, interMatrix5, interMatrix6, interMatrix7;
}



