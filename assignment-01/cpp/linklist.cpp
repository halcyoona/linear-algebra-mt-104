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
	public:
		linklist();
		~linklist();
		void addInTheEnd(int val);
		void makeMatrix();
		void countNumberOfZerosInRows();
		int checkingSecondCondition();
		void checkingEchelonForm();
		void checkingReduceEchelonForm();
		void display();
};


linklist::linklist()
{
	cout<<"Enter Rows = ";
	cin>>rows;
	cout<<"Enter columns = ";
	cin>>columns;
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
		delete p;
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
	delete temp;
	
}


void linklist::makeMatrix(){
	for (int i = 0; i < rows; i++)
	{
		addInTheEnd(i);
	}
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
	delete temp;	
}


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
	delete temp;
}

int linklist::checkingSecondCondition()
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
			temp = temp->next;
			continue;
		}
		else if (temp->numberOfZeros == lowestNumZero)
		{
			for (int i = 0; i < columns; i++)
			{
				if (temp->data[i] == 0)
				{
					continue;
				}
				else
				{
					delete temp;
					return 0;	
				}
			}
			temp = temp->next;
		}
		else
		{
			delete temp;
			return 0;
		}
		
	}
	delete temp;
	return 1;
}



//checking first two condition for Echelon form
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
				temp = temp->next;
				continue;
			}
			else if (temp->numberOfZeros == lowestNumZero)
			{
				for (int i = 0; i < columns; i++)
				{
					if (temp->data[i] == 0)
					{
						continue;
					}
					else
					{
						cout<<"Matrix not in Echelon Form"<<endl;
						display();
						delete temp;
						return;	
					}
				}
				temp = temp->next;
			}
			else
			{
				cout<<"Matrix not in Echelon Form"<<endl;
				display();
				delete temp;
				return;
			}
			
		}
		cout<<"Matrix is in Echelon Form"<<endl;
		display();
		delete temp;
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
			if (head->data[i] != 0)
			{
				if (head->data[i] == 1)
				{
					cout<<"Matrix is in Reduce Echelon Form"<<endl;
					display();
					return;	
				}
				else
				{
					cout<<"Matrix is not in Reduce Echelon Form"<<endl;
					display();
					return;
				}
			}
			else{
				continue;
			}
		}
		cout<<"Matrix is in Reduce Echelon Form"<<endl;
		display();
	}
	else if(checkingSecondCondition() == 1)
	{
		Node *temp;
		temp = head;
		while(temp != NULL)
		{
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
									internalTemp = internalTemp->next;
									continue;
								}
								else
								{
									cout<<"Matrix is not in Reduce Echelon Form "<<endl;
									display();
									delete temp;
									return;
								} 
							}
							else{
								internalTemp = internalTemp->next;
								continue;
							}
							
						}
						delete internalTemp;
						break;
					}
					else
					{
						cout<<"Matrix is not in Reduce Echelon Form "<<endl;
						display();
						delete temp;
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
		cout<<"Matrix is in Reduce Echelon Form "<<endl;
		display();
		
	}
	else{
		cout<<"Matrix is not in Reduce Echelon Form "<<endl;
		display();
		return;
	}
}


int main()
{
	linklist l;
	l.makeMatrix();
	l.checkingReduceEchelonForm();
	return 0;
}
