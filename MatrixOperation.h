#include<iostream>
#include<vector>


using namespace std;

//Template class for the matrix operation
template <class T>

//Class for the matrix operation
class MatrixOperation
{
	int row; //No of rows in the matrix
	int column; //No of columns in the matrix
	vector<vector<T>> m; //declare a vector of vectors of type T

public:

	MatrixOperation() {} //Default Constructor
	
	MatrixOperation(int _row, int _column); //Initialize row and column of the matrix
	
	void InsertDataToMatrix(); //Assigns values to the matrix
	void PrintMatrix(); //Prints the matrix

	
	friend MatrixOperation<T> operator*(MatrixOperation<T>& ob1, MatrixOperation<T>& ob2)//Multiplication operation with operator overloading
	{
		
		MatrixOperation<T> temp(ob1.row, ob2.column);

		if (ob1.column != ob2.row)
		{
			cout << "Invalid matrix size for multiplication" << endl;
			return temp;
		}

		
		int i, j, k;
		for (i = 0; i < ob1.row; i++)
		{
			for (j = 0; j < ob2.column; j++)
			{
				temp.m[i][j] = 0;

				for (k = 0; k < ob1.column; k++)
					temp.m[i][j] += ob1.m[i][k] * ob2.m[k][j];
			}
		}

		return temp;


	}
	
	
	friend MatrixOperation<T> operator~(MatrixOperation<T>& ob) //Inverse operation with operator overloading
	{
		MatrixOperation<T> temp1(ob.column, ob.row);

		int i, j;

		for (i = 0; i < ob.row; i++)
		{
			for (j = 0; j < ob.column; j++)
			{
				temp1.m[j][i] = ob.m[i][j];
			}
		}

		return temp1;
	}
	
	~MatrixOperation() {} //Destructor
};

template <class T>

MatrixOperation<T>::MatrixOperation(int _row, int _col) //Constructor function definition 
{
	row = _row;
	column = _col;	
	m.resize(row, vector<T>(column, 0)); //Initialize the vector of size rowXcolumn with 0

}

template <class T>

void MatrixOperation<T>::InsertDataToMatrix() //Matrix value insertion function defintion
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			cin >> m[i][j];
		}
	}

}

template<class T>

void MatrixOperation<T>::PrintMatrix() //This method prints out the value of the matrix
{

	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}





