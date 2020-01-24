#include <iostream>
using std::cin;
using std::cout;

int maxRows, maxCols;

int shortestPaths(int rows, int cols, int** matrix) {
	if (rows >= maxRows || cols >= maxCols)
		return 0;
	if (matrix[rows][cols] > 0) {
		return matrix[rows][cols];
	}
	if (rows == maxRows - 1 && cols == maxCols - 1) {
		return 1;
	}
	matrix[rows][cols] = shortestPaths(rows + 1, cols, matrix) + shortestPaths(rows, cols + 1,  matrix);
	return matrix[rows][cols];
}
int main()
{
	int rows, cols;
	cout << "Enter the number of rows: ";
	cin >> rows;
	maxRows = rows;
	cout << "Enter the number of columns: ";
	cin >> cols;
	maxCols = cols;
	int** matrix = new int*[rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[cols];
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = 0;
		}
	}

	shortestPaths(0, 0, matrix);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}