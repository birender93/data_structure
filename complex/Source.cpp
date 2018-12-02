//#include <iostream>
//using namespace std;
//
//class complex
//{
//	int _real, _imag;
//
//public:
//	complex(int ireal=0, int iimag=0)
//	{
//		_real = ireal;
//		_imag = iimag;
//	}
//
//	complex(const complex& icomp)
//	{
//		int real, imag;
//		icomp.getvalue(real, imag);
//
//		_real = real;
//		_imag = imag;
//	}
//
//	complex operator +(complex& icomp)
//	{
//		int real, imag;
//		icomp.getvalue(real, imag);
//
//		real += _real;
//		imag += _imag;
//
//		complex tempc(real, imag);		
//		return tempc;	
//	}
//
//	complex operator -(complex& icomp)
//	{
//		int real, imag;
//		icomp.getvalue(real, imag);
//
//		real = _real - real;
//		imag = _imag - imag;
//
//		complex tempc(real, imag);		
//		return tempc;	
//	}
//
//	complex operator *(complex& icomp)
//	{
//		int real, imag;
//		icomp.getvalue(real, imag);
//
//		real = _real*real - (_imag * imag);
//		imag = _real*imag + (real* _imag);
//
//		complex tempc(real, imag);		
//		return tempc;	
//	}
//
//	complex operator /(complex& icomp)
//	{
//		int real, imag, den;
//		icomp.getvalue(real, imag);
//
//		den = pow(real,2) + pow(imag,2);
//
//		imag = -imag;
//		real = _real*real - (_imag * imag);
//		imag = _real*imag + (real* _imag);
//
//		real = real/den;
//		imag = imag/den;
//
//		complex tempc(real, imag);		
//		return tempc;	
//	}
//
//	complex conjugate()
//	{
//		complex tempc(_real, -_imag);		
//		return tempc;
//	}
//
//	void setvalue(int ireal, int iimag)
//	{
//		ireal = _real;
//		iimag = _imag;
//	}
//
//	void getvalue(int &oreal, int& oimag) const
//	{
//		oreal = _real;
//		oimag = _imag;
//	}
//
//	void operator =(const complex& icomp)
//	{
//		int real, imag;
//		icomp.getvalue(real, imag);
//
//		_real = real;
//		_imag = imag;
//	}
//	
//	friend ostream& operator << (ostream& icout, const complex& icomp);
//	friend istream& operator >> (istream& icin, complex& icomp);
//};
//
//ostream& operator << (ostream& icout, const complex& icomp)
//{
//	icout << icomp._real << "+" <<icomp._imag<<"i";
//	return icout;
//}
//
//istream& operator >> (istream& icin, complex& icomp)
//{
//	icin >> icomp._real >> icomp._imag;
//	return icin;
//}
//
//int main()
//{
//	complex c1(2,3), c2;
//
//	cin>>c2;	
//
//	complex c3 = c1 / c2;
//
//	complex c4;
//	c4 = c1 * c2;
//
//	cout << "\n" << c1 << "\n" << c2 << "\n" << c3 << "\n" << c4 << endl;
//
//	return 0;
//}

#include <iostream>
using namespace std;
#include <vector>

const int row = 3;
const int col = 3;
class matrix
{
	int **_ppmtrx;
	int arr[row][col];
	int _row, _col;

public:
	matrix()
	{

	}

	matrix(int irow, int icol, int* parr)
	{
		_row = irow;
		_col = icol;
		_ppmtrx = new int*[irow];

		if(_ppmtrx)
		{
			for(int i=0; i < irow; i++)
			{
				_ppmtrx[i] = new int[icol];
				if(_ppmtrx[i])
				{
					for(int j=0; j < icol; j++)
					{
						_ppmtrx[i][j] = *( (parr+i*icol) + j);	
					}
				}
			}
		}
	}

	matrix operator *(const matrix& mobj)
	{
		int** parr = NULL;
		int row, col;
		mobj.GetArr(parr, row,col);

		matrix omobj;

		if(_col != row)
			return omobj;

		vector<vector<int>> vec;
		vector<int> tvec;
		for(int i=0; i < _row; i++)
		{
			for(int j=0; j < col; j++)
			{
				int sum = 0;
				for(int k=0; k < row; k++)
				{
					sum += _ppmtrx[i][k]*parr[j][k];
				}
				tvec.push_back(sum);
			}	
			vec.push_back(tvec);
			tvec.clear();
		}
	}

	void GetArr(int** &oparr, int& orow, int& ocol) const
	{
		oparr = _ppmtrx;
		orow = _row;
		ocol = _col;
	}

	void SetArr(int irow, int icol, int* parr)
	{
		_row = irow;
		_col = icol;
		_ppmtrx = new int*[irow];

		if(_ppmtrx)
		{
			for(int i=0; i < irow; i++)
			{
				_ppmtrx[i] = new int[icol];
				if(_ppmtrx[i])
				{
					for(int j=0; j < icol; j++)
					{
						_ppmtrx[i][j] = *( (parr+i*icol) + j);	
					}
				}
			}
		}
	}

	void transpose()
	{
		int row = _col, col = _row;

		int**ptr = new int*[row];

		for(int i = 0; i<row; i++)
		{
			ptr[i] = new int[col];
			for(int j = 0; j<col; j++)
			{
				ptr[i][j] = _ppmtrx[j][i];
			}
		}

		_ppmtrx = ptr;
	}

	friend ostream& operator <<(ostream& icout, const matrix& mobj);
};

ostream& operator <<(ostream& icout, const matrix& mobj)
{
	for(int i=0; i < mobj._row; i++)
	{
		for(int j=0; j < mobj._col; j++)
		{
			icout << (mobj._ppmtrx)[i][j] << "\t";	
		}	
		icout << endl;
	}

	return icout;
}



int main()
{
	/*int arr[3][3];
	int cnt =1;

	for(int i=0; i < 3; i++)
	{
		for(int j=0; j < 3; j++)
		{
			arr[i][j] = cnt;
			cnt++;
		}
	}

	matrix mtrx(3,3, (int*)arr);
	cout << mtrx;

	mtrx.transpose();
	cout<<mtrx;*/


	int cnt=0, n=5;

	while(n)
	{
		for(int i=0; i<cnt; i++)
			cout <<" ";

		for(int j=0; j<n; j++)
		{
			cout <<"*" <<" ";
		}
		cout <<endl;
		n--;
		cnt++;
	}
}