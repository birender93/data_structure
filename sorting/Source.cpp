#include <iostream>
using namespace std;

void display(int arr[], int size)
{
	for(int i = 0; i <size; i++)
	{
		cout << arr[i] << "\t" ;
	
	}
	cout << endl;

}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;

	//a = a+b;
	//b = a-b;
	//a = a-b;
}

void selection_sort(int arr[], int size )
{
	int min_index;

	for(int i=0; i < size-1; i++)
	{
		min_index = i;

		for(int j= i+1; j < size; j++)
		{
			if(arr[min_index] > arr[j])
			{
				min_index = j;	
			}
		}

		swap(arr[min_index],arr[i]);
	}
}

void bubble_sort(int arr[], int size)
{
	int flag = 0;
	for(int i = 1; i < size ; i++)
	{
		flag = 0;
		for(int j = 0; j < size-i; j++ )
		{
			if(arr[j] > arr[j+1])
			{
				swap(arr[j], arr[j+1]);
				flag = 1;
			}
		}	
		if(!flag) break;
	}
}

void insertion_sort(int arr[], int size)
{
	for(int i = 1; i < size; i++ )
	{
		for(int j = i; j >0; j-- )
		{
			if(arr[j] < arr[j-1]) swap(arr[j], arr[j-1]);
			else break;
		}
	}
}

void merge( int arr[], int lind, int rind, int mid)
{
	int *temparr = new int[rind - lind +1];

	int i = lind, j = mid+1, k = 0;

	while(i <= mid && j <= rind)
	{
		if(arr[i] <= arr[j])
		{
			temparr[k] = arr[i];
			i++;
		}
		else
		{
			temparr[k] = arr[j];
			j++;
		}
		k++;
	}

	for(; i <= mid; i++, k++)
	{
		temparr[k] = arr[i];
	}

	for(; j <= rind; j++, k++)
	{
		temparr[k] = arr[j];
	}

	for(int i = 0; i < k; i++ )
	{
		arr[i + lind] = temparr[i];	
	}

	delete []temparr;
}

void merge_sort(int arr[], int lind, int rind)
{
	if(rind <= lind) return;

	int  mid = (rind + lind)/2;

	if(mid != lind)
	{
		merge_sort( arr, lind, mid);
		merge_sort(arr, mid+1, rind);
	}

	merge(arr, lind, rind, mid);
}

int partition(int arr[], int& st, int &end)
{
	int pivot = arr[end];
	int p_ind = st;
	for(int i = st; i < end; i++)
	{
		if(arr[i] <= pivot)
		{
			swap(arr[i], arr[p_ind]);
			p_ind++;
		}
	}

	swap(arr[end], arr[p_ind]);

	return p_ind;
}

void quick_sort(int arr[], int st, int en)
{
	if(st > en) return;

	int p_ind = partition(arr, st, en);

	quick_sort(arr, st, (p_ind - 1) );
	quick_sort(arr, p_ind+1, en);

}

#include <vector>
void spiralOrder(const vector<vector<int> > &A) {
	vector<int> result;
	int stR = 0, stC=0, enR=A.size(), enC=A[0].size() ;
	
	while(stC<enC && stR<enR)
	{
		for(int i =stC; i < enC; i++)
			result.push_back(A[stR][i]);

		stR++;
		for(int i =stR; i < enR; i++)
			result.push_back(A[i][enC-1]);

		enC--;
		if(stC < enC)
		{
			for(int i =enC-1; i > stC; i--)
				result.push_back(A[enR-1][i]);
			enR--;
		}

		if(stR<enR)
		{
			for(int i =enR-1; i > stR; i--)
				result.push_back(A[i][stC]);
			stC++;
		}
	}
	
	for(int i = 0; i < result.size(); i++)
	cout <<result[i];

	cout<<"\n\n\n\n\n\n\n";
}

int main()
{
	int arr[5] = {5,4,3,2,1};

	//display(arr,5);

	//selection_sort(arr,5);
	//bubble_sort(arr,5);
	//insertion_sort(arr,5);
	//merge_sort(arr, 0,4);
	//quick_sort(arr, 0,4);

	//display(arr,5);

	vector<vector<int> > A;
	vector<int>B;
	int m=2, n=3, nct=0;

	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			B.push_back(nct);
			nct++;
		}
		A.push_back(B);
		B.clear();
	}

	
	spiralOrder(A);
}


