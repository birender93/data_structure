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

class listnode
{
public:
	int val;
	listnode* next;

	listnode(int x): val(x), next(nullptr)
	{}
};

//O(n2) solution 
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

node* createBstFrmPreodr_Oofn(vector<int>& A, int* indxer, int key, int min, int max)
{
	if(*indxer == A.size()) return nullptr;

	node* root = nullptr;

	if(key > min && key < max)
	{
		root = new node(key);
		(*indxer)++;

		if(*indxer < A.size())
		{
			root->left = createBstFrmPreodr_Oofn(A, indxer, A[*indxer], min, key);
			root->right = createBstFrmPreodr_Oofn(A, indxer, A[*indxer], key, max);
		}		
	}
	return root;
}

//Convert a BST to a Binary Tree such that sum of all greater keys is added to every key

void inordrTrv(node* root, vector<int>& vec, int& sum)
{
	if(!root) return;

	if(root->left)
		inordrTrv(root->left, vec, sum);

	vec.push_back(root->val);
	sum += root->val;

	if(root->right)
		inordrTrv(root->right, vec, sum);
}

void cnvBST(node* root, int& lsum)
{
	if(root->right)
		cnvBST(root->right, lsum);
	
	root->val = root->val + lsum;
	lsum = root->val;

	if(root->left)
		cnvBST(root->left, lsum);
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

node* createBSTfromList(listnode* lroot)
{
	if(!lroot) return nullptr;

	listnode* sptr = lroot, *fptr = lroot->next;

	if(fptr && fptr->next)
		fptr = fptr->next;

	while(fptr && fptr->next)
	{
		sptr = sptr->next;
		fptr = fptr->next->next;
	}
	node* root;
	if(sptr->next)
	{
		root = new node(sptr->next->val);
		fptr = sptr->next->next;
		sptr->next = nullptr;

		root->left = createBSTfromList(lroot);
		root->right = createBSTfromList(fptr);
	}
	else
	{
		root = new node(sptr->val);
	}

	return root;
}

node* bstfromlist(listnode** lroot, int n)
{
	if(n == 0) return nullptr;

	node* left = bstfromlist(lroot, n/2);

	node* root = new node((*lroot)->val);

	root->left = left;

	*lroot = (*lroot)->next;

	root->right = bstfromlist(lroot, n- n/2 -1);

	return root;
}

node* createBSTfromList_On(listnode** lroot)
{
	node* root = nullptr;

	int n =0;
	listnode* temp = *lroot;

	while(temp)
	{
		n++;
		temp = temp->next;
	}

	root = bstfromlist(lroot, n);

	return root;
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

	//node* root = createBstFrmPreodr(vec, 0, size-1);
	//lvlordrtrv(root);

	//int indx =0;
	//root = createBstFrmPreodr_Oofn(vec, &indx, vec[0], INT_MIN, INT_MAX);
	//lvlordrtrv(root);

	//node* root = new node(5);
	//root->left = new node(2);
	//root->right = new node(13);
	//lvlordrtrv(root);

	int lsum =0;
	//cnvBST(root, lsum);
	//lvlordrtrv(root);
	
	listnode* lroot = new listnode(1);
	lroot->next = new listnode(2);
	lroot->next->next = new listnode(3);
	lroot->next->next->next = new listnode(4);
	lroot->next->next->next->next = new listnode(5);
	lroot->next->next->next->next->next = new listnode(6);
	lroot->next->next->next->next->next->next = new listnode(7);

	listnode* pcrawl = lroot;
	while(pcrawl)
	{
		cout << pcrawl->val;
		
		if(pcrawl->next)
			cout << "-->";

		pcrawl = pcrawl->next;
	}
	cout << "\n\n";

	node* root  = createBSTfromList(lroot);
	lvlordrtrv(root);

	//node* root = createBSTfromList_On(&lroot);
	//lvlordrtrv(root);

	return 0;
}


