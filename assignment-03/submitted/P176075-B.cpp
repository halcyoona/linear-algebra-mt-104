#include<iostream>
#include "fraction.cpp"
using namespace std;




class matrix{
	
	private:
		fraction** p;
		int *zeroCountList;
		int zeroRows;
		int rows;
		int columns;
	public:
		matrix();
		matrix(int row, int col, fraction **mat);
		~matrix();
		void setMatrix();
		void showMatrix();
		void writeMatrixInFile();
		void inputMatrixFromFile();
		bool checkingEchelonForm();
		bool checkingReduceEchelonForm();
		void countZeros();
		void sort(int arr[], int size, int index);
		void reducing();
		void showZeroList();
		bool linearDependence();
};





matrix::matrix()
{
	cout<<"Enter Rows = ";
	cin>>rows;
	cout<<"Enter columns = ";
	cin>>columns;
	zeroRows = 0;
	zeroCountList = new int[rows];
	p = new fraction*[rows];
	for (int i = 0; i < rows; i++)
	{
		p[i] = new fraction[columns];
		for (int j = 0; j < columns; j++)
		{
			p[i][j] = 0;
		}
	}
}



matrix::matrix(int row, int col, fraction **mat)
{
	rows = row;
	columns = col;
	zeroRows = 0;
	zeroCountList = new int[rows];
	p = mat;
}



matrix::~matrix(){
	for (int i = 0; i < rows; i++)
	{
		delete[] p[i];
	}
	delete[] p;
}





void matrix::showMatrix(){
	for (int i = 0; i < rows; i++) 
	{
        for (int j = 0; j < columns; j++)
        {
            cout << p[i][j] << " ";
        }
        cout<<endl;
        // cout<<*(p+i)<<endl;
    }
    // showZeroList();
}

void matrix::writeMatrixInFile(){
	ofstream out("out.txt");
	for (int i = 0; i < rows; i++) 
	{
        for (int j = 0; j < columns; j++)
        {
            out << p[i][j] << " ";
        }
        out<<endl;
        // cout<<*(p+i)<<endl;
    }
    // showZeroList();
}


void matrix::setMatrix(){
	for (int i = 0; i < rows; i++)
	{
        for (int j = 0; j < columns; j++) 
        {
            cout << "Enter value at row = " << i << " column = "<<j<<" : ";
            cin>>p[i][j];
        }
    }
}



void matrix::inputMatrixFromFile(){
	ifstream in("in.txt");
	for (int i = 0; i < rows; i++) 
	{
        for (int j = 0; j < columns; j++)
        {
            in>>p[i][j];
            cout<<p[i][j]<<" i :"<<i<<" j : "<<j<<endl;
        }
    }
}





bool matrix::checkingEchelonForm()
{
	if (rows == 0 && columns == 0 )
	{
		// cout<<"Matrix is empty"<<endl;
		return false;
	}

	else if(rows == 1)
	{
		return true;
		// cout<<"Matrix is in Echelon Form"<<endl;
	}
	else{
		int lowestNumberOfZeros = -1;
		for (int i = 0; i < rows; i++)
		{
			int count = 0;
			for (int j = 0; j < columns; j++)
			{
				if (p[i][j] == 0)
				{
					count += 1;
				}
				else
				{
					break;
				}
			}
			if (count < lowestNumberOfZeros)
			{
				// cout<< "Matrix is not in Echelon Form"<<endl;
				return false;
			}
			else if (count == lowestNumberOfZeros)
			{
				if (count == columns)
				{
					continue;
				}
				else
				{
					// cout<<"Matrix is not in Echelon Form"<<endl;
					return false;
				}
			}
			else
			{
				lowestNumberOfZeros = count;
				continue;
			}

		}
		// cout<<"Matrix is in Echelon Form"<<endl;
		return true;
			
	}
}






bool matrix::checkingReduceEchelonForm()
{
	if (rows == 0 && columns == 0 )
	{
		// cout<<"Matrix is empty"<<endl;
		return false;
	}

	else if(rows == 1)
	{
		for (int i = 0; i < columns; ++i)
		{
			if (p[0][i] == 0)
			{
				continue;
			}
			else if (p[0][i] == 1)
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
		for (int i = 0; i < rows; i++)
		{
			int count = 0;
			for (int j = 0; j < columns; j++)
			{
				if (p[i][j] == 0)
				{
					count += 1;
				}
				else if (p[i][j] == 1)
				{
					for (int k = 0; k < rows; k++)
					{
						if (&(p[k][j]) == &(p[i][j]))
						{
							continue;
						}
						else
						{ 
							if (p[k][j] == 0)
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
				if (count == columns)
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


void matrix::countZeros()
{
	for (int i = 0; i < rows; i++) 
	{
		int count = 0;
        for (int j = 0; j < columns; j++)
        {
            if (p[i][j] == 0)
            {
            	count += 1;
            }
            else
            {
         		break;
            }
        }
        zeroCountList[i] = count;
        if (count == columns)
        {
        	zeroRows += 1;	
        } 
    }
}






void matrix::sort(int arr[], int size, int index)
{
	int i = index , j = size, counter = 1;
	while(i != j)
	{
		if (arr[i]>=arr[j])
		{
			fraction *fract;
			fract = *(p+j);
			*(p+j) = *(p+i);
			*(p+i) = fract;
			int temp;
			temp = *(arr+j);
			*(arr+j) = *(arr+i);
			*(arr+i) = temp;
			counter += 1;
			if (counter % 2 == 0)
			{
				j -= 1;
			}
			else
			{
				i += 1;
			}
		}
		else
		{
			if(counter % 2 == 0)
			{
				j -= 1;
			}
			else
			{
				i += 1;
			}
		}	
	}
	

	if (j==0 || j ==size)
	{
		return;
	}
	else
	{
		sort(arr,j-1,0);
		sort(arr, size, j+1);
		return;
	}

}

void matrix::reducing()
{
	bool n = false; 
	while(n == false)
	{
		countZeros();
		sort(zeroCountList, rows-1, 0);
		// showMatrix();
		// showZeroList();
		if (checkingReduceEchelonForm() != true)
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					if (p[i][j] == 0)
					{
						continue;
					}
					else
					{
						fraction lessImportant = p[i][j]; 
						// cout<<"lessImportant : "<<lessImportant<<endl;
						for (int m = j; m < columns; m++)
						{
							// cout<<p[i][m]<<" ";
							p[i][m] = p[i][m] / lessImportant;
							// cout<<p[i][m]<<" ";
						}
						// cout<<endl;
						for (int k = 0; k < rows; k++)
						{
							if (*(p+k) == *(p+i))
							{
								// cout<<"1"<<endl;
								continue;
							}
							else
							{ 
								if (p[k][j] == 0)
								{
									// cout<<"2"<<endl;
									continue;
								}
								else
								{
									// cout<<"3"<<endl;
									fraction important = p[k][j];
									// cout<<"important : "<<important<<endl;								
									for (int l = j; l < columns; l++)
									{
										
										p[k][l] = p[k][l] - (p[i][l] * important);
										// cout<<p[k][l]<<" "; 
									}	
									// cout<<endl;
								}
							}
						}
						break;
					}
				}
			}
		}
		else
		{
			return;
		}
	}	
}

void matrix::showZeroList()
{
	cout<<"Zero List : ";
	for (int i = 0; i < rows; i++)
	{
		cout<<*(zeroCountList+i);
	}
	cout<<endl;
}


bool matrix::linearDependence()
{
	if (columns > rows)
	{
		// cout<<"linearly Dependent"<<endl;
		return false;
	}
	else{
		reducing();
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (i == j && p[i][j] == 1)
				{
					continue;
				}
				else{
					if (p[i][j] == 0)
					{
						continue;
					}
					else
					{
						// cout<<"linearly Dependent"<<endl;
						return false;
					}
				}
			}
		}
		// cout<<"linearly Independent"<<endl;
		return true;
	}
}



int main(){
	int row = 0, col = 0, tmatrix = 0;
	fraction **mat;
	ifstream in("in.txt");
	ofstream out("out.txt");
	if (!in.is_open()) {
		cout << "Error in opening file" << endl;
		return 0;
	}

	in >> tmatrix;
	for (int i = 0; i < tmatrix; i++)
	{
		in>>row>>col;
		// cout<<"rows : "<<row<<" Col : "<<col<<endl;
		mat = new fraction*[row];
		for (int i = 0; i < row; i++)
			mat[i] = new fraction[col];
		for (int j = 0; j < row; j++) 
		{
	        for (int k = 0; k < col; k++)
	        {
	            in>>mat[j][k];
	            // cout<<p[i][j]<<" i :"<<i<<" j : "<<j<<endl;
	        }
    	}
		matrix m(row,col,mat);
		// // m.inputMatrixFromFile();
		// m.showMatrix();
		bool val = m.linearDependence();
		// // m.writeMatrixInFile();
		// m.showMatrix();
		// cout<<"good"<<endl;
		out<<val<<endl;
	}
	// matrix m;
	// // m.showMatrix();
	// m.setMatrix();
	// m.showMatrix();
	// m.reducing();
	// m.showMatrix();
	// couts<<1%2<<2%2<<endl; 

	return 0;
}