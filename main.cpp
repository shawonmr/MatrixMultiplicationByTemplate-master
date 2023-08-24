#include "MatrixOperation.h"
#include "stdio.h"

//This is the main.cpp file
//Matrix input can be provided


int main()
{
	int r1, c1, r2, c2, type;//Temporary variables
	r1 = c1 = type = 1;
	r2 = c2 = 2;
	while(c1 != r2)
	{
		cout << "Enter no of row and column for the first matrix" << endl;
		cin >> r1 >> c1;
		cout << "Enter no of row and column for the second matrix" << endl;
		cin >> r2 >> c2;
		if (c1 != r2)
		{
			cout << "Please enter same no of column and row for the first and the second matrix" << endl;
		}
	}

	cout << "Enter value type (1 or 2) for the matrix e.g." << "1 for interger or " << "2 for float type " << endl;
	cin >> type;
	
	//Matrix value type operations 
	if (type == 1) //Matrix values are int type
	{
		MatrixOperation<int> a(r1, c1); //First matrix declaration
		MatrixOperation<int> b(r2, c2); //Second matrix declaration
		MatrixOperation<int> c;       //Matrix that stores the product
		cout << "Enter value for the first matrix of dimension " << r1 << "X" << c1 << endl;
		a.InsertDataToMatrix();

		
		
		cout << "First matrix" << endl;
		a.PrintMatrix();

		cout << "Enter value for the second matrix of dimension " << r2 << "X" << c2 << endl;
		b.InsertDataToMatrix();

		
		

		cout << "Second matrix " << endl;
		b.PrintMatrix();

		

		c = a * b; //Multiplication

		cout << "After multiplication" << endl;
		c.PrintMatrix();

		c = ~c; //Transpose

		cout << "After transpose" << endl;
		c.PrintMatrix();
	}
	else //Matrix values are float type
	{
		MatrixOperation<float> a(r1, c1); //First matrix declaration
		MatrixOperation<float> b(r2, c2); //Second matrix declaration
		MatrixOperation<float> c;       //Matrix that stores the product
		cout << "Enter value for the first matrix of dimension " << r1 << "X" << c1 << endl;
		a.InsertDataToMatrix();

		cout << "First matrix" << endl;
		a.PrintMatrix();

		cout << "Enter value for the second matrix of dimension " << r2 << "X" << c2 << endl;
		b.InsertDataToMatrix();

		cout << "Second matrix " << endl;
		b.PrintMatrix();

		c = a * b; //Multiplication

		cout << "After multiplication" << endl;
		c.PrintMatrix();

		c = ~c; //Transpose

		cout << "After transpose" << endl;
		c.PrintMatrix();
	}
	

	getchar();
	getchar();
	return 0;
}