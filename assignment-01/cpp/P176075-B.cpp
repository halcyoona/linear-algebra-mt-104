#include<iostream>
#include<fstream>
using namespace std;

bool is_reducedEche_form(int **matrix, int row, int col) {
	
	if (row == 0 && col == 0 )
	{
		// cout<<"Matrix is empty"<<endl;
		return false;
	}

	else if(row == 1)
	{
		for (int i = 0; i < col; ++i)
		{
			if (matrix[0][i] == 0)
			{
				continue;
			}
			else if (matrix[0][i] == 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		return true;
		// cout<<"Matrix is in  Reduce Echelon Form"<<endl;
	}
	else{
		int lowestNumberOfZeros = -1;
		for (int i = 0; i < row; i++)
		{
			int count = 0;
			for (int j = 0; j < col; j++)
			{
				if (matrix[i][j] == 0)
				{
					count += 1;
				}
				else if (matrix[i][j] == 1)
				{
					for (int k = 0; k < row; k++)
					{
						if (matrix[k][j] == matrix[i][j])
						{
							continue;
						}
						else
						{ 
							if (matrix[k][j] == 0)
							{
								continue;
							}
							else
							{
								// cout<<"1"<<endl;
								return false;
							}
						}
					}
					break;
				}
				else
				{	
					
					// cout<<"2"<<endl;
					return false;
				}
			}
			if (count < lowestNumberOfZeros)
			{
				// cout<< "Matrix is not in Reduce Echelon Form"<<endl;
				return false;
			}
			else if (count == lowestNumberOfZeros)
			{
				if (count == col)
				{
					continue;
				}
				else
				{
					// cout<<"Matrix is not in Reduce Echelon Form"<<endl;
					return false;
				}
			}
			else
			{
				lowestNumberOfZeros = count;
				continue;
			}

		}
		// cout<<"Matrix is in Reduce Echelon Form"<<endl;
		return true;
			
	}
}

//Don't touch this function
void alloca_memory(int **matrix, int row, int col) {
	for (int i = 0; i < row; i++)
		matrix[i] = new int[col];
}

//Don't touch this function
void free_memory(int **matrix, int row) {
	for (int i = 0; i > row; i++)
		delete[] matrix[i];
	delete[] matrix;
}

void main() {

	int row = 0, col = 0, tmatrix = 0;
	int **matrix = 0;
	ifstream in("in.txt");
	ofstream out("out.txt"); // will automatically created if not present

	if (!in.is_open()) {
		cout << "Error in opening file" << endl;
		return;
	}

	in >> tmatrix;

	for (int i = 0; i < tmatrix; i++) {
		in >> row >> col;
		matrix = new int*[row];
		alloca_memory(matrix, row, col);

		for (int k = 0; k < row; k++) 
			for (int j = 0; j < col; j++)
				in >> matrix[k][j];

		if (is_reducedEche_form(matrix, row, col)) // your desired function to which you passes 2d array(matrix)
			out << 1<<endl;
		else out << 0 << endl;

		free_memory(matrix, row); // to free the memory allocated

	}


}