#include<iostream>
#include<ctime>

using namespace std;

class Matrix
{
	int** matrix = nullptr;
	int size_m = 0, size_n = 0;

public:
	Matrix();
	Matrix(int m, int n);
	~Matrix();
	void init();
	void print();
	Matrix operator+ (Matrix &summ);
	Matrix operator* (Matrix &multi);
	Matrix operator= (Matrix &assign);
	int*& operator[](int) const;
	void get_randomElement(int, int);
	int set_randomElement(int, int, int);
	void transpose();
};

void Matrix::transpose()
{
	cout << "transpose matrix:" << endl;
	//int temp;
	for (int j = 0; j < size_n; ++j)
	{
		for (int i = 0; i < size_m; ++i)
		{
			/*temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;*/
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}



Matrix Matrix::operator+ (Matrix &summ)//Складывать можно только матрицы одинакового размера.
{
	Matrix result(size_m, size_n);
	for (int i = 0; i < size_m; i++)
	{
		for (int j = 0; j < size_n; j++)
		{
			result[i][j] = this->matrix[i][j] + summ[i][j];
		}
	}
	return result;
}

Matrix Matrix::operator* (Matrix &multi)/*Операция умножения двух матриц выполнима только в том случае,
									   если число столбцов в первом сомножителе равно числу строк во втором*/
{
	Matrix m(size_m, size_n);
	if (this->size_n != multi.size_m)
	{
		cout << "Error!" << endl;
	}
	else
	{
		for (int i = 0; i < size_m; i++)
		{
			for (int j = 0; j < size_m; j++)
			{
				m[i][j] = 0;
				for (int k = 0; k < size_m; k++)
				{
					m[i][j] += this->matrix[i][k] * multi[k][j];
				}				
			}
		}
		return m;
	}	
}

Matrix Matrix::operator= (Matrix &assign)
{
	for (int i = 0; i < size_m; i++)
	{
		for (int j = 0; j < size_n; j++)
		{
			this->matrix[i][j] = assign.matrix[i][j];
		}
	}
	return *this;
}

int*& Matrix::operator[](int m) const //эту перегрузку я взял с киберфорума...
{
	if ((m > size_m - 1) || (m < 0))
		cout << "Error: array overflow..." << endl;
	return matrix[m];
}

void Matrix::get_randomElement(int a, int b){
	cout << "Element [" << a << "][" << b << "] = " << matrix[a - 1][b - 1] << endl << endl;
}

int Matrix::set_randomElement(int a, int b, int s){
	return matrix[a][b] = s;	
}

void Matrix::init()
{
	for (int i = 0; i < size_m; ++i)
	{
		for (int j = 0; j < size_n; ++j)
		{
			matrix[i][j] = rand() % 10;
		}
	}
}

void Matrix::print()
{	
	cout << "matrix: " << endl;
	for (int i = 0; i < size_m; ++i)
	{
		for (int j = 0; j < size_n; ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;	
}

Matrix::Matrix(int m, int n)
{
	this->size_m = m;
	this->size_n = n;	
	matrix = new int *[n];
	for (int i = 0; i < m; ++i)
	{
		matrix[i] = new int[m];
	}
}

Matrix::~Matrix()
{
	/*for (int i = 0; i < size_n; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;*/
}

void main(){
	Matrix a(4, 5);
	a.init();
	cout << "A ";
	a.print();
	a.get_randomElement(3, 3);
	a.transpose();

	Matrix b(5, 4);
	b.init();
	cout << "B ";
	b.print();
	b[1][1] = 35;
	cout << b[1][1] << endl;
	cout << "B ";
	b.print();
	b.set_randomElement(2, 2, 77);
	cout << "B ";
	b.print();
	b.get_randomElement(2, 2);
	b.transpose();

	system("pause");
	system("cls");
	Matrix c(3, 3), d(3, 3), cd(3, 3);
	c.init();
	cout << "C ";
	c.print();

	d.init();
	cout << "D ";
	d.print();

	cd = c + d;
	cout << "C + D ";
	cd.print();

	cd = c * d;
	cout << "C * D ";
	cd.print();

	c = d;
	cout << "C = D ";
	c.print();
	cout << "D ";
	d.print();

	
}