#include <iostream>
using namespace std;
#include <math.h>
#include <queue>


struct node
{
	node(int idata)
	{
		_data = idata;
		lt = nullptr;
		rt = nullptr;
	}
	int _data;
	node* lt;
	node* rt;
};

void lvl_ord_prnt(node* root)
{
	queue<node*> que;
	que.push(root);
	node* tmp;
	int cnt = que.size();

	while(!que.empty())
	{
		cnt--;
		tmp = que.front();
		que.pop();
		cout << tmp->_data << "\t";

		if(tmp->lt)
		{
			que.push(tmp->lt);
		}

		if(tmp->rt)
		{
			que.push(tmp->rt);
		}

		if(cnt == 0)
		{
			cout << endl;
			cnt = que.size();
		}
	}

}

void in_ord_prnt(node* root)
{
	if(root->lt)
		in_ord_prnt(root->lt);

	cout << root->_data << "\t";

	if(root->rt)
		in_ord_prnt(root->rt);
}

void pst_ord_prnt(node* root)
{
	if(root->lt)
		pst_ord_prnt(root->lt);

	if(root->rt)
		pst_ord_prnt(root->rt);

	cout << root->_data << "\t";
}

void pre_ord_prnt(node* root)
{
	cout << root->_data << "\t";

	if(root->lt)
		pre_ord_prnt(root->lt);

	if(root->rt)
		pre_ord_prnt(root->rt);	
}

#include <map>

void diag_util_prnt(node* root, int slope, map<int, vector<int>> &diag_map)
{
	if(!root)
		return;

	diag_map[slope].push_back(root->_data);

	if(root->lt)
		diag_util_prnt(root->lt, slope+1, diag_map);

	if(root->rt)
		diag_util_prnt(root->rt, slope, diag_map);
}

void diag_prnt(node* root)
{
	if(!root)
		return;

	map<int, vector<int>> diag_map;
	diag_util_prnt(root, 0, diag_map);


	for(auto mpitr = diag_map.begin(); mpitr != diag_map.end(); mpitr++)
	{
		for(auto vecitr = mpitr->second.begin(); vecitr != mpitr->second.end(); vecitr++ )
		{
			cout << *vecitr << "\t";
		}
		cout << endl;
	}

}

void tree()
{
	node* arr[15];
	int chin;
	int size = sizeof(arr)/sizeof(arr[0]);
	for(int i = size-1; i >=0; i--)
	{
		arr[i] = new node(i+1);
		chin = 	(2*i)+1;

		if(chin < size)
		{
			arr[i]->lt  = arr[chin];
			if(chin+1 < size)
				arr[i]->rt = arr[chin+1];
		}
	}

	cout << "Level Order"<<endl;
	lvl_ord_prnt(arr[0]);
	cout << "\n\n\n\n\n\n";

	cout << "Inorder Order"<<endl;
	in_ord_prnt(arr[0]);
	cout << "\n\n\n\n\n\n";

	cout << "Post Order"<<endl;
	pst_ord_prnt(arr[0]);
	cout << "\n\n\n\n\n\n";

	cout << "Pre Order"<<endl;
	pre_ord_prnt(arr[0]);
	cout << "\n\n\n\n\n\n";

	cout << "Diagonal Print"<<endl;
	diag_prnt(arr[0]);
	cout << "\n\n\n\n\n\n";
}

void prnt_arr(int arr[], int size)
{
	for(int i =0; i<size; i++)
	{
		cout << arr[i] << "\t";	
	}
}

void arr()
{
//===========================Array Rotation===================================================
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int d;
	unsigned int size  = sizeof(arr)/sizeof(arr[0]);

	cout<<"enter the number:";
	cin>>d;
	int *t = new int[d];

	for(int i =0; i<d; i++)
	{
		t[i] = arr[i];	
	}

	for(unsigned int i=d; i<size; i++)
	{
		arr[i-d] = arr[i];	
	}

	for(unsigned int i = (size-d); i<size; i++)
	{
		arr[i]=t[i - (size-d)];	
	}

	prnt_arr(arr, size);
	cout << "\n\n\n\n\n\n";
//============================================================================================





}

int main()
{
	//tree();

	arr();

return 0;
}

