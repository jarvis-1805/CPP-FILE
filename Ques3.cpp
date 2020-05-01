#include<iostream>
using namespace std;
class RELATION
{
	private:
	int i,j,nA,nB,nR,*A,*B,*R;
	
	public:
	void inputSets()
	{
		cout << "Enter the size of SET A : ";
		cin >> nA;
		A = new int[nA];
		cout << "Enter the elements : ";
		for(i=0; i<nA; i++)
			cin >> A[i];
		cout << "Enter the size of SET B : ";
		cin >> nB;
		B = new int[nB];
		cout << "Enter the elements : ";
		for(i=0; i<nB; i++)
			cin >> B[i];
	}
	
	void inputRelation()
	{
		cout << "Enter the no of relations : ";
		cin >> nR;
		R = new int[nR * 2];
		cout << "Enter the relations in pair :\n";
		for(i=0; i<nR*2; i++)
			cin >> R[i];
	}
	
	void printSets()
	{
		cout << "A = {";
		for(i=0; i<nA; i++)
			cout << A[i] << " ";
		cout << "}\n";
		cout << "B = {";
		for(i=0; i<nB; i++)
			cout << B[i] << " ";
		cout << "}\n";
	}
	
	void printRelation()
	{
		cout << "R = {";
		for(i=0; i<nR*2; i++)
			cout << R[i] << " ";
		cout << "}\n";
	}
};

int main()
{
	RELATION ob;
	
	ob.inputSets();
	ob.inputRelation();
	ob.printSets();
	ob.printRelation();
}