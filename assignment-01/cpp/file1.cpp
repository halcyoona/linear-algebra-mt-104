#include<iostream>
#include <string>
using namespace std;

class matrix{
	
	private:
		int** p;
		int rows;
		int columns;
	public:
		matrix();
		~matrix();
		void setMatrix();
		void showMatrix();
		bool checkingEchelonForm();
		bool checkingReduceEchelonForm();

};

matrix::matrix(){
	cout<<"Enter Rows = ";
	cin>>rows;
	cout<<"Enter columns = ";
	cin>>columns;
	p = new int*[rows];
	for (int i = 0; i < rows; i++){
		p[i] = new int[columns];
		for (int j = 0; j < columns; j++)
		{
			p[i][j] = 0;
		}
	}
}

matrix::~matrix(){
	for (int i = 0; i < rows; i++){
		delete[] p[i];
	}
	delete[] p;
}

void matrix::showMatrix(){
	for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << p[i][j] << " ";
        }
        cout<<endl;
    }
}

void matrix::setMatrix(){
	for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Enter value at row = " << i << " column = "<<j<<" : ";
            cin>>p[i][j];
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
						if (p[k][j] == p[i][j])
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

int main(){

	matrix m;
	m.showMatrix();
	m.setMatrix();
	cout<<m.checkingReduceEchelonForm()<<endl;
	m.showMatrix(); 

	return 0;
}