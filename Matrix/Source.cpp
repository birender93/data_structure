#include <iostream>
using namespace std;

bool search(int mat[][4],int row,  int k)
{
	bool flag = false;

	int i=0, j=0;

	while(1)
	{
		if(mat[i][j] == k)
		{
			flag = true;
			break;
		}


	}

	return flag;
}

int main()
{
	int mat[4][4] = { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50}};

	cout << search(mat, 4, 29)<<endl;
return 0;
}