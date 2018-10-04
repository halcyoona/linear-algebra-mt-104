#include<iostream>
using namespace std;

struct Node
{
	int *data;
	int numberOfZeros;
	Node *next;
};

class linklist
{
	protected:
		Node *head;
		Node *tail;
		int rows;
		int columns;
		int highestNumberOfZeros;
		int countZeroRow;
	public:
		linklist();
		~linklist();
		void addInTheEnd(int val);
		void addInTheStart();
		void makeMatrix();
		void checkZeroRow();
		void addZeroRowInTheEnd();
		void countNumberOfZerosInRows();
		void checkingEchelonForm();
		void checkingReduceEchelonForm();
		//void reduceMatrix();
		void checking();
		void display();
};


linklist::linklist()
{
	cout<<"Enter Rows = ";
	cin>>rows;
	cout<<"Enter columns = ";
	cin>>columns;
	highestNumberOfZeros = 0;
	countZeroRow = 0;
	head = NULL;
	tail = NULL;
}

linklist::~linklist()
{
	Node *p;
	Node *q;
	q = head;
	while(q != NULL)
	{
		p = q;
		q = q->next;
		delete[] p->data;
		delete p;
	}
}

void linklist::addInTheStart()
{
	Node *temp = new Node;
	temp->data = new int[columns];
	temp->numberOfZeros = 0;
	temp->next = NULL;
	if(head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
	
}


void linklist::addInTheEnd(int val)
{
	Node *temp = new Node;
	temp->data = new int[columns];
	temp->numberOfZeros = 0;
	temp->next = NULL;
	if(head == NULL)
	{
		head = temp;
		tail = temp;
		for (int i = 0; i < columns; i++)
		{
			cout<<"Enter value at : Row = "<<val<< " column = "<<i <<" : ";
			cin>>tail->data[i];
		}
	}
	else
	{
		tail->next = temp;
		tail = temp;
		for (int i = 0; i < columns; i++)
		{
			cout<<"Enter value at : Row = "<<val<< " column = "<<i <<" : ";
			cin>>tail->data[i];
		}
	}
	
}

void linklist::addZeroRowInTheEnd()
{
	Node *temp = new Node;
	temp->data = new int[columns];
	temp->numberOfZeros = highestNumberOfZeros;
	temp->next = NULL;
	tail->next = temp;
	tail = temp;
	for (int i = 0; i < columns; i++)
	{
		tail->data[i] = 0;
	}
	delete temp;
}

void linklist::makeMatrix(){
	for (int i = 0; i < rows; i++)
	{
		addInTheEnd(i);
	}
}


void linklist::checkZeroRow(){

	Node *p;
	Node *temp;
	temp = head;
	while(temp != NULL)
	{
		int count = 0;
		for (int i = 0; i < columns; i++)
		{
			if(temp->data[i] == 0){
				count += 1;
			}	
		}
		temp->numberOfZeros = count;
		if (count>highestNumberOfZeros && count != columns)
		{
			highestNumberOfZeros = count;
			// cout<<"highestNumberOfZeros"<<highestNumberOfZeros<<endl;
		}
		if (count == columns)
		{
			countZeroRow += 1;
			// cout<<"countZeroRow"<<countZeroRow<<endl;
			if (head == temp)
			{
				head = head->next;
				temp = head;
			}
			else
			{
				p->next = temp->next;
				temp = p;
			}
		}
		else
		{
			p = temp;
			temp = temp->next;
		}	
	}
	delete temp;
	delete p;
}

void linklist::countNumberOfZerosInRows(){

	Node *temp;
	temp = head;
	while(temp != NULL)
	{
		int count = 0;
		for (int i = 0; i < columns; i++)
		{
			if(temp->data[i] == 0)
			{
				count += 1;
			}	
		}
		temp->numberOfZeros = count;
		temp = temp->next;
	}	
}
// void linklist::reduceMatrix(){
// 	if (p[0][0] == 1 )
// 	{
// 		for (int i = 0; i < rows; i++)
// 		{
// 			int counts = 1;
// 			for (int j = 0; j < columns; j++)
// 			{
// 				if(p[i][j] == 0){
// 					counts += 1;
// 				} 
// 			}
// 			if (counts == columns)
// 			{
				
// 			}
// 		}
// 	}

// 	else{
// 		for (int i = 0; i < columns; i++)
// 		{
// 			p[0][i] = p[0][i]/p[0][0];
// 		}
// 		for (int i = 1; i < rows; i++)
// 		{
// 			if (p[i][0] == 0)
// 			{
// 				cout<<"ok"<<endl;
// 			}
// 		}
			
// 	}
// }

void linklist::display()
{
	
	Node *temp;
	temp = head;
	while(temp != NULL)
	{
		for (int i = 0; i < columns; i++)
		{
			cout<<temp->data[i]<<" ";	
		}
		cout<<endl;
		temp = temp->next;
	}
}

void linklist::checking()
{
	if(head==NULL)
	{
		cout<<"Matrix is empty"<<endl;
	}
	else if(head == tail)
	{
		int num = 1;
		for (int i = 0; i < columns; i++)
		{
			if (head->data[i] == 0)
			{
				continue;
			}
			else if (head->data[i] == 1)
			{
				cout<<"Matrix is in Reduce Echelon Form"<<endl;
				return;
			}
			else
			{
				for (int j = 0; j < columns; j++)
				{
					head->data[j] = head->data[j]/num;
				}
				cout<<"Matrix is in Echelon Form"<<endl;
				return;
			}
		}
				
	}
	else{
		checkZeroRow();
		
		for (int i = 0; i < countZeroRow; i++)
		{
			addZeroRowInTheEnd();
		}
		
	}
}

void linklist::checkingEchelonForm()
{
	if(head==NULL)
	{
		cout<<"Matrix is empty"<<endl;
	}
	else if(head == tail)
	{
		cout<<"Matrix is in Echelon Form"<<endl;
		display();
	}
	else
	{
		countNumberOfZerosInRows();
		Node *temp;
		temp = head;
		int lowestNumZero = -1;
		while(temp != NULL)
		{
			if (temp->numberOfZeros > lowestNumZero)
			{
				lowestNumZero = temp->numberOfZeros;
			}
			else{
				cout<<"Matrix not in Echelon Form"<<endl;
				display();
				return;
			}
			temp = temp->next;
		}
		delete temp;
		cout<<"Matrix is in Echelon Form"<<endl;
		display();
		
	}
}

void linklist::checkingReduceEchelonForm()
{
	if(head==NULL)
	{
		cout<<"Matrix is empty"<<endl;
	}
	else if(head == tail)
	{
		for (int i = 0; i < columns; i++)
		{
			if (head->data[i] == 0)
			{
				continue;
			}
			else if (head->data[i] == 1)
			{
				cout<<"Matrix is in Reduce Echelon Form"<<endl;
			}
			else
			{
				cout<<"Matrix is not in Reduce Echelon Form"<<endl;
			}
		}
		cout<<"Matrix is in Reduce Echelon Form"<<endl;
	}
	else
	{
		countNumberOfZerosInRows();
		Node *temp;
		temp = head;
		int lowestNumZero = -1;
		while(temp != NULL)
		{
			if (temp->numberOfZeros > lowestNumZero)
			{
				lowestNumZero = temp->numberOfZeros;
			}
			else
			{
				cout<<"Matrix not in Reduce Echelon Form"<<endl;
				display();
				return;
			}
			for (int i = 0; i < columns; i++)
			{
				if(temp->data[i] != 0)
				{
					if(temp->data[i] == 1)
					{
						Node *internalTemp;
						internalTemp = head;
						while(internalTemp != NULL)
						{
							if (internalTemp != temp)
							{
								if(internalTemp->data[i] == 0)
								{
									continue;
								}
								else
								{
									cout<<"Matrix is not in Reduce Echelon Form "<<endl;
									return;
								} 
							}
							internalTemp = internalTemp->next;
						}
						delete internalTemp;
					}
					else
					{
						cout<<"Matrix is not in Reduce Echelon Form "<<endl;
						return;
					}
				}
				else
				{
					continue;
				}
		 	}
			temp = temp->next;
		}
		delete temp;
		cout<<"Matrix is in Echelon Form"<<endl;
		display();
		
	}
}


int main()
{
	linklist l;
	l.makeMatrix();
	l.checkingReduceEchelonForm();
	return 0;
}
