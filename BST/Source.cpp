#include <iostream>
using namespace std;
#include<vector>
#include<queue>

class node
{
public:
	node* left;
	node* right;
	int val;

	node(int x): val(x), left(nullptr), right(nullptr)
	{}
};

node* createBstFrmPreodr(vector<int>& A, int st, int end)
{
	if(!A.size()) return nullptr;

	node* root = new node(A[st]);

	if(st == end) return root;

	int i=st+1;
	for(; i<= end; i++)
	{
		if(A[i] > A[st])
			break;
	}

	if(A[st+1] < A[st])
		root->left = createBstFrmPreodr(A, st+1, i-1);

	if(A[i] > A[st])
		root->right = createBstFrmPreodr(A, i, end);

	return root;
}

void lvlordrtrv(node* root)
{
	queue<node*> que;
	int size = 1;
	que.push(root);

	while(!que.empty())
	{
		node* temp = que.front();
		que.pop();

		cout << temp->val << "\t";

		if(temp->left)
			que.push(temp->left);

		if(temp->right)
			que.push(temp->right);

		size--;

		if(!size && !que.empty())
		{
			size = que.size();
			cout << endl;
		}
	}

	cout << "\n\n";
}

int main()
{
	int arr[] = {10, 5, 1, 7, 40, 50};
	int size = sizeof(arr)/sizeof(arr[0]);
	vector<int> vec;

	for(int i=0; i< size; i++)
	{
		vec.push_back(arr[i]);
	}

	node* root = createBstFrmPreodr(vec, 0, size-1);
	lvlordrtrv(root);

	return 0;
}