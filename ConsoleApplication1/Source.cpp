#include <iostream>
using namespace std;

bool search(int mat[][4],int row,  int k)
{
	bool flag = false;

	int i=0, j=0;

	while(i < row && i >=0 && j < 4 && j >=0)
	{
		if(mat[i][j] == k)
		{
			flag = true;
			cout << "index i= " << i+1<<"\t index j= " << j+1<<endl;
			break;
		}

		if(i+1 < row && j+1 < 4)
		{
			if(mat[i+1][j] < k && mat[i][j+1] < k)
			{
				i++;
				j++;
			}
			else if(mat[i+1][j] > k && mat[i][j+1] > k)
			{
				i--;
				j--;
			}
			else if(mat[i+1][j] <= k && mat[i][j+1] > k)
			{
				i++;
			}
			else
			{
				j++;
			}
		}
		else
		{
			if(j+1 < 4)
			{

				if( mat[i][j+1] <= k)
				{
					j++;
				}
				else
					j--;
			}
			else
			{
				if( mat[i+1][j] <= k)
				{
					i++;
				}
				else
					i--;
			}
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

	cout << search(mat, 4, 40)<<endl;
return 0;
}