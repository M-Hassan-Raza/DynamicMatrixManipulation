#include <iostream>
#include <fstream>

using namespace std;

void deallocateMatrix(int** matrix, int& ROWS)
{
	int** upperBoundAddress = matrix + ROWS;

	for(int** i = matrix; i < upperBoundAddress; i++)
	{
		delete *i;
	}

	delete[] matrix;

	return;
}

int** InputMatrix(ifstream& fin, int& rows, int& cols)
{
	fin >> rows;
	fin >> cols;

	int** arrayMatrix = new int*[rows];

	int** upperBoundAddressRow = arrayMatrix + rows;

	for(int** i = arrayMatrix ; i < upperBoundAddressRow; i++)
	{
		*i = new int[cols];
	}

	for(int** i = arrayMatrix; i < upperBoundAddressRow; i++)
	{
		int* upperBoundAddressCol = *i + cols;

		for(int* j = *i; j < upperBoundAddressCol; j++)
		{
			fin >> *j;
		}
	}

	return arrayMatrix;
}


void OutputMatrix(int** matrix, const int& ROWS, const int& COLS)
{
	int** upperBoundAddressRow = matrix + ROWS;

	for(int** i = matrix; i < upperBoundAddressRow; i++)
	{
		int* upperBoundAddressCol = *i + COLS;

		for(int* j = *i; j < upperBoundAddressCol; j++)
		{
			cout << *j << "\t";
		}
		cout << "\n";
	}

	cout << "\n\n";
}


int** AddMatrix(int** matrixA, int** matrixB, const int& ROWS, const int& COLS)
{
	int** arrayAddition = new int*[ROWS];

	int** upperBoundAddressRow = arrayAddition + ROWS;

	for(int** i = arrayAddition ; i < upperBoundAddressRow; i++)
	{
		*i = new int[COLS];
	}

	int** rowCounterA = matrixA;
	int** rowCounterB = matrixB;


	for(int** i = arrayAddition; i < upperBoundAddressRow; i++)
	{
		int* upperBoundAddressCol = *i + COLS;
		int* elementA = *rowCounterA;
		int* elementB = *rowCounterB;

		for(int* j = *i; j < upperBoundAddressCol; j++)
		{
			*j = *elementA + *elementB;
			elementA++;
			elementB++;
		}

		rowCounterA++;
		rowCounterB++;
	}

	return arrayAddition;
}


int** TransposeMatrix(int** matrix, const int& ROWS, const int& COLS)
{

	int** transposed = new int*[COLS];
	int** upperBoundAddressRow = transposed + COLS;

	for(int** i = transposed ; i < upperBoundAddressRow; i++)
	{
		*i = new int[ROWS];
	}


	for(int i = 0; i < COLS; i++)
	{
		for(int j = 0; j < ROWS; j++)
		{
			*(*(transposed + i) + j) = *( *(matrix + j) + i);

		}
	}

	/*for(int i = 0; i < COLS; i++)
	{
	for(int j = 0; j < ROWS; j++)
	{
	transposed[i][j] = matrix[j][i];
	}
	}
	*/

	return transposed;
}


bool IsSymmetric(int** matrix, const int& ROWS, const int& COLS)
{

	int** newMatrix = TransposeMatrix(matrix, ROWS, COLS);
	int** upperBoundAddressRow = newMatrix + ROWS;
	int** matrixArray = matrix;

	for(int** i = newMatrix; i < upperBoundAddressRow; i++)
	{
		int* upperBoundAddressCol = *i + COLS;

		int* elementMatrix = *matrixArray;

		for(int* j = *i; j < upperBoundAddressCol; j++)
		{
			if(*j != *elementMatrix)
			{
				return false;
			}

			elementMatrix++;
		}
		matrixArray++;
	}

	return true;
}



void InterchangeRows(int*& row1, int*& row2 )
{
	int* temp = row1;
	row1 = row2;
	row2 = temp;

	return;
}

void InterchangeRows(int** matrix, const int& ROWS, const int& COLS )
{
	int** row1 = matrix;
	int** row3 = matrix+2;
	InterchangeRows(*row1, *row3);

	return;
}


int main()
{
	int arrRows, arrCols, arrRows2, arrCols2, arrRows3, arrCols3;
	ifstream inputObj("InputFile.txt");

	int** arrayA = InputMatrix(inputObj, arrRows, arrCols);
	cout << "Matrix A = \n";
	OutputMatrix(arrayA, arrRows, arrCols);
	cout << "\n\n";

	int** arrayB = InputMatrix(inputObj, arrRows2, arrCols2);
	cout << "Matrix B = \n";
	OutputMatrix(arrayB, arrRows2, arrCols2);
	cout << "\n\n";


	int** arrayC = InputMatrix(inputObj, arrRows3, arrCols3);
	cout << "Matrix C = \n";
	OutputMatrix(arrayC, arrRows3, arrCols3);
	cout << "\n\n";


	cout << "A + B = \n";
	if ((arrRows != arrRows2) || (arrCols != arrCols2))
	{
		cout << "Addition not possible.\n";
	}
	else
	{
		int** arrayAdditionAB = AddMatrix(arrayA, arrayB, arrRows, arrCols);
		OutputMatrix(arrayAdditionAB, arrRows, arrCols);
		int** upperBoundAB = arrayAdditionAB + arrRows;
		for(int** i = arrayAdditionAB; i < upperBoundAB; i++)
		{
			delete[] *i;
		}

		delete[] arrayAdditionAB;
	}
	cout << "\n\n";


	cout << "A + C = \n";
	if ((arrRows != arrRows3) || (arrCols != arrCols3))
	{
		cout << "Addition not possible.\n";
	}
	else
	{
		int** arrayAdditionAC = AddMatrix(arrayA, arrayC, arrRows, arrCols);
		OutputMatrix(arrayAdditionAC, arrRows, arrCols);
		int** upperBoundAC = arrayAdditionAC + arrRows3;
		for(int** i = arrayAdditionAC; i < upperBoundAC; i++)
		{
			delete[] *i;
		}

		delete[] arrayAdditionAC;
	}
	cout << "\n\n";


	int** transposedA = TransposeMatrix(arrayA, arrRows, arrCols);
	cout << "Transpose of A =\n";
	OutputMatrix(transposedA, arrCols, arrRows);
	cout << "\n\n";


	int** transposedC = TransposeMatrix(arrayC, arrRows3, arrCols3);
	cout << "Transpose of C =\n";
	OutputMatrix(transposedC, arrCols3, arrRows3);
	cout << "\n\n";


	if(arrRows == arrCols)
	{
		if(IsSymmetric(arrayA, arrRows, arrCols))
		{
			cout << "Matrix A is Symmetric\n";
		}
		else
		{
			cout << "Matrix A is NOT Symmetric\n";
		}

	}
	else
	{
		cout << "Matrix A is NOT Symmetric\n";
	}
	cout << "\n\n";



	if(arrRows2 == arrCols2)
	{
		if(IsSymmetric(arrayB, arrRows2, arrCols2))
		{
			cout << "Matrix B is Symmetric\n";
		}
		else
		{
			cout << "Matrix B is NOT Symmetric\n";
		}
	}
	else
	{
		cout << "Matrix B is NOT Symmetric\n";
	}
	cout << "\n\n";




	cout << "Interchanging Rows of Matrix A: \n";
	cout << "row1: 1\n"; 
	cout << "row2: 3\n";
	cout << "\nAfter Interchanging Rows Matrix A =\n";
	InterchangeRows(arrayA, arrRows, arrCols);
	OutputMatrix(arrayA, arrRows, arrCols);


	////Memory Deallocation
	deallocateMatrix(arrayA, arrRows);
	deallocateMatrix(arrayB, arrRows2);
	deallocateMatrix(arrayC, arrRows3);

	system("pause>0");
}