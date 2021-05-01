# DynamicMatrixManipulation

Write a program that takes two matrices from user and performs Mathematical operations on it.

Operations Include:
                  -	Matrix Addition
                  -	Transpose of a matrix
                  -	Checks if a matrix is symmetric or not
                  -	Interchange rows of a matrix

Functions:
          1.	Int** InputMatrix( ifstream& fin, int& rows, int& cols)
              Description: This function will take size of matrix from file, create a matrix dynamically, take matrix elements from file and return the matrix created.

          2.	Void OutputMatrix(int** matrix, cont int& ROWS, const int& COLS)
              Description: Displays the matrix in proper format. 

          3.	Int** AddMatrix(int** matrixA, int** matrixB, const int& ROWS, const int& COLS)
              Description: This function takes two matrices as parameters, adds them and saves the result in a newly created matrix R and returns the result. 

          4.	int** TransposeMatrix(int** matrix, const int& ROWS, const int& COLS)
              Decription: This function takes a matrix A, takes transpose of matrix A, saves the result in a newly created matrix and returns the result. 

          5.	Bool IsSymmetric(int** matrix, const int& ROWS, const int& COLS)
              Description: This function takes a matrix as parameter with its size information and returns true if the matrix is symmetric and false otherwise.

          6.	Void InterchangeRows(int** matrix, const int& ROWS, const int& COLS )
              Description: This function takes two row numbers and calls following function to actually interchange the rows. 

          7.	Void InterchangeRows( int*& row1, int*& row2 )
              Description: This function interchanges two rows. You are NOT ALLOWED to iterate through rows and swap their values. Think of simple solution. 

