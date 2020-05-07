/* Create a class RELATION, use Matrix notation to represent a relation. Include functions to 
check if a relation is reflexive, Symmetric, Anti-symmetric and Transitive. Write a Program 
to use this class.
*/
#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;

class RELATION
{
	private:
	int i,j,k,x,y,iA,iB,nA,nR,*A,*R,**RM;
	
	public:
	void inputSet();
	void inputRelation();
	void printSet();
	void printRelation();
	void Matrix();
	void reflexive();
};

void RELATION::inputSet()
{
	cout << "Enter the size of SET A : ";
	cin >> nA;
	A = new int[nA];
	cout << "Enter the elements : ";
	for(i=0; i<nA; i++)
		cin >> A[i];
}

void RELATION::inputRelation()
{
	cout << "Enter the no of relations (R on A) : ";
	cin >> nR;
	R = new int[nR * 2];
	cout << "Enter the relations in pair :\n";
	for(i=0; i<nR*2; i++)
		cin >> R[i];
}

void RELATION::printSet()
{
	cout << "A = {";
	for(i=0; i<nA; i++)
		cout << A[i] << " ";
	cout << "}\n";
}

void RELATION::printRelation()
{
	cout << "R = {";
	for(i=0; i<nR*2; i++)
	{
		if(i%2 == 0)
			cout << "(";
		cout << R[i] << " ";
		if(i%2 != 0)
			cout << ")";
	}
	cout << "}\n";
}

void RELATION::Matrix()
{
	cout << "\nMATRIX NOTATION\n\n";
	RM = new int *[nA];
	for(i=0; i<nA; i++)
		RM[i]=new int[nA];
	
	for(i=0; i<nA; i++)
	{
		for(j=0; j<nA; j++)
		{
			RM[i][j]=0;
		}	
	}
	
	for(i=0; i<nR*2; i+=2)
	{
		for(j=0; j<nA; j++)
		{
			if(R[i] == A[j])
			{
				iA=j;
				break;
			}
		}
		for(k=0; k<nA; k++)
		{
			if(R[i+1] == A[k])
			{
				iB=k;
				break;
			}
		}
		RM[iA][iB]=1;
	}
	
	cout << "    ";
	for(int x=0; x<nA; x++)
		cout << " " << A[x] << " ";
	cout << endl << endl;
	for(i=0; i<nA; i++)
	{
		cout << A[i] << "  | ";
		for(j=0; j<nA; j++)
		{
			cout << RM[i][j] << "  ";
		}	
		cout << "|";
		cout << endl;
	}
}

void RELATION::reflexive()
{
	x=0;
	y=0;
	for(i=0; i<nA; i++)
	{
		if(RM[i][i] == 1)
			y++;
		for(j=0; j<nA; j++)
		{
			x+=RM[i][j];
		}
	}
	if(x == nA && y == nA)
		cout << "\nRelation is REFLEXIVE.";
	else
		cout << "\nRelation is NOT REFLEXIVE.";
}

int main()
{
	RELATION ob;
	
	ob.inputSet();
	ob.printSet();
	ob.inputRelation();
	ob.printRelation();
	ob.Matrix();
	ob.reflexive();
}