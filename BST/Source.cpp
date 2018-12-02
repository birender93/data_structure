#include<iostream>
using namespace std;
#include<stack>
#include <vector>
#include <algorithm>

class node
{
public:
    int data;
    node *left;
    node *right;
	int height;

	node(int val): data(val), left(nullptr),right(nullptr)
	{}

};

class lnode
{
public:
	int data;
	lnode *next;

	lnode(int val):data(val), next(nullptr)
	{}

};


node* makeBSTUtil(int arr[], int size, int& indx, int min, int max)
{
	if(indx == size) return nullptr;

	node* root = nullptr;

	if(arr[indx] > min && arr[indx] < max)
	{
		root = new node(arr[indx]);

		indx++;
		root->left = makeBSTUtil(arr, size, indx, min, root->data);

		root->right = makeBSTUtil(arr, size, indx, root->data, max);
	}

	return root;
}

node* makeBST(int arr[], int size)
{
	int indx = 0;

	node* root = nullptr;
	root = makeBSTUtil(arr, size, indx, INT_MIN, INT_MAX);

	return root;
}


node* makeBSTitr(int arr[], int size)
{
	if(size <1) return nullptr;

	stack<node*> st;
	node* root = new node(arr[0]);
	st.push(root);

	int indx = 1;
	while(indx < size)
	{
		if(st.top()->data > arr[indx])
		{
			st.top()->left = new node(arr[indx]);
			st.push(st.top()->left);
		}
		else
		{
			node* top = nullptr;
			while(!st.empty() && st.top()->data < arr[indx] )
			{
				top = st.top();
				st.pop();
			}

			if(top)
			{
				top->right = new node(arr[indx]);
				st.push(top->right);
			}
		}
		indx++;
	}


	return root;
}

void preordr(node* root, vector<int>& vec)
{
	if(root)
	{
		cout << root->data << "\t";	
		vec.push_back(root->data);
	}
	if(root->left)
		preordr(root->left, vec);

	if(root->right)
		preordr(root->right, vec);
}

void inordr(node* root, vector<int>& vec)
{
	if(root)
	{
		if(root->left)
			inordr(root->left, vec);

		cout << root->data << "\t";	
		vec.push_back(root->data);

		if(root->right)
			inordr(root->right, vec);
	}
}

void cnvtoBSTUtil(node* root, vector<int>& vec, int& indx)
{
	if(root)
	{
		if(root->left)
			cnvtoBSTUtil(root->left, vec, indx);

		root->data = vec[indx];
		indx++;

		if(root->right)
			cnvtoBSTUtil(root->right, vec, indx);
	}

}

void cnvtoBST(node* root)
{
	vector<int> vec;
	inordr(root,vec);
	cout<<"\n";

	std::sort(vec.begin(), vec.end());

	int indx = 0;
	cnvtoBSTUtil(root, vec, indx);
}

void cnvBSTtoBTutil(node* root, int& sum)
{
	if(root->right)
		cnvBSTtoBTutil(root->right, sum);

	sum += root->data;
	root->data = sum;

	if(root->left)
		cnvBSTtoBTutil(root->left, sum);
}

void cnvBSTtoBT(node* root)
{
	int sum = 0;
	cnvBSTtoBTutil(root, sum);		
}

lnode* createlist(int arr[], int size)
{
	lnode* root = new lnode(arr[0]);
	lnode* temp = root;

	for(int i=1; i<size; i++)
	{
		temp->next = new lnode(arr[i]);
		temp = temp->next;
	}

	return root;
}

node* createBSTfromListUtil(lnode** lroot, int n)
{
	if(n<=0) return nullptr;

	node* lnode = createBSTfromListUtil(lroot, n/2);

	node* root = new node((*lroot)->data);
	root->left = lnode;

	*lroot = (*lroot)->next;

	root->right = createBSTfromListUtil(lroot, n-n/2-1);

	return root;
}

node* createBSTfromList(lnode* lroot)
{
	int n=0;
	lnode* temp = lroot;

	while(temp)
	{
		n++;
		temp = temp->next;
	}

	node* root = createBSTfromListUtil(&lroot, n);

	return root;
}

node* createTreeUtil(vector<int>& prevec, vector<int>& invec, int st, int en, int& preindx)
{
	node* root = new node(prevec[preindx]);
	preindx++;

	if(st == en)	return root;

	int i=st;
	while(i <= en && root->data != invec[i])
		i++;

	
	root->left = createTreeUtil(prevec, invec, st, i-1, preindx);
	root->right = createTreeUtil(prevec, invec, i+1, en, preindx);
	
	return root;
}

node* createTree(vector<int>& prevec, vector<int>& invec)
{
	node* root = new node(prevec[0]);

	int i=0;
	while(i<invec.size() && prevec[0] != invec[i])
		i++;

	int j =1;
	root->left = createTreeUtil(prevec, invec, 0, i-1, j);

	root->right = createTreeUtil(prevec, invec, i+1, prevec.size()-1, j);

	return root;
}

int height(node* root)
{
	if(root == nullptr) return 0;

	return std::max(height(root->left), height(root->right))+1;
}

bool isBalanced(node* root, int& height)
{
	bool flag = true;

	if(root)
	{		
		int lh = 0;
		flag = isBalanced(root->left, lh);
		
		if(flag == false) return flag;

		int rh = 0;
		flag = isBalanced(root->right, rh);

		if(flag == false) return flag;

		if( std::abs(lh-rh) > 1)
			flag = false;

		height += std::max(lh, rh)+1;
	}	
	return flag;
}

#include<queue>

void levelordr(node* root, vector<int>& vec)
{
	cout <<"\n\n";
	queue<node*> que;

	que.push(root);
	int size = que.size();

	while(!que.empty())
	{
		node* temp = que.front();
		que.pop();
		size--;
		cout <<temp->data<<"\t";
		vec.push_back(temp->data);

		if(temp->left)
			que.push(temp->left);

		if(temp->right)
			que.push(temp->right);

		if(size == 0)
		{
			cout << "\n";
			size = que.size();
		}
	}
}

vector<node*> createNBST(int st, int en)
{
	vector<node*> vecBST;

	if(st > en)
	{
		vecBST.push_back(NULL);
		return vecBST;
	}

	for(int i =st; i<=en; i++)
	{
		vector<node*> lvec = createNBST(st, i-1);
		vector<node*> rvec = createNBST(i+1, en);

		for(int j=0; j< lvec.size(); j++)
		{
			node* lroot = lvec[j];

			for(int k=0; k < rvec.size(); k++)
			{
				node* rroot = rvec[k];

				node* root = new node(i);

				root->left = lroot;
				root->right = rroot;
				vecBST.push_back(root);
			}
		}
	}

	return vecBST;
}

void cnvBSTtominheaputil(node* root, vector<int> ivec, int& indx)
{
	if(root)
	{
		root->data = ivec[indx];
		indx++;

		if(root->left)
		cnvBSTtominheaputil(root->left, ivec, indx);

		if(root->right)
		cnvBSTtominheaputil(root->right, ivec, indx);
	}
}

void cnvBSTtominheap(node* root)
{
	vector<int> ivec;

	inordr(root, ivec);

	int indx =0;
	cnvBSTtominheaputil(root, ivec, indx);

}

void prn_vec(vector<int> vec2)
{
	cout <<"\n\n";
	for(int i =0; i < vec2.size(); i++)
	{
		cout << vec2[i] << "\t";
	}

	cout <<"\n\n";
}

void setchild(node* pnode, node* root,vector<int>& vec,  int& indx)
{
	if(indx == vec.size()) return;

	if(pnode == nullptr)
	{
		if(root->data > vec[indx])
		{
			root->left = new node(vec[indx]);
			indx++;
		}

		if(root->data < vec[indx])
		{
			root->right = new node(vec[indx]);
			indx++;
		}		
	}
	else if(vec[indx] < pnode->data)
	{
		if(root->data > vec[indx])
		{
			root->left = new node(vec[indx]);
			indx++;
		}

		if(root->data < vec[indx])
		{
			root->right = new node(vec[indx]);
			indx++;
		}
	}

	if(root->left)
	{
		setchild(root, root->left, vec,indx);
	}

	if(root->right)
	{
		setchild(root, root->right, vec,indx);
	}
}

node* createBSTfromlvlTrv(vector<int> vec)
{
	node* pnode = nullptr;
	node* root = new node(vec[0]);

	int indx =1;
	setchild(pnode, root, vec, indx);
	

	return root;
}

bool checkforBSTutil(node* root, int& i)
{
	if(root == NULL) return true;

	if(!(checkforBSTutil(root->left, i)))
		return false;

	if(root->data <= i)
		return false;

	i = root->data;

	if(!(checkforBSTutil(root->right, i)))
		return false;

	return true;
}

bool checkforBST(node* root)
{
	int i = INT_MIN;
	return checkforBSTutil(root, i);
}

int KthSmallElemBST(node* root, int& k)
{
	int i = INT_MIN;

	if(root == NULL || k < 1) return i;

	i = KthSmallElemBST(root->left, k);

	if(k)
	{
		k--;
		i = root->data;

		if(!k)
			return i;

		i = KthSmallElemBST(root->right, k);
	}

	return i;
}

bool check_1child(int pre[], int size)
{
	bool flag = true;

	if(size <= 1) return flag;

	int min = INT_MIN;
	int max = INT_MAX;

	if(pre[0] < pre[1])
	{
		min = pre[0];
		max = pre[1];
	}
	else
	{
		max = pre[0];
		min = pre[1];
	}

	for(int i=2; i<size; i++)
	{
		if(pre[i] < min)	
	}
}

int main()
{
	//int arr[] = {50,40,7,1,5,10};
	//vector<int> vec;
	//node* root = nullptr;

	//int n = sizeof(arr)/sizeof(arr[0]);
	//root = makeBST(arr, n);

	//preordr(root);
	//cout<<"\n\n";
	//inordr(root, vec);
	//cout<<"\n\n";

	//root = makeBSTitr(arr, n);
	//
	//preordr(root);
	//cout<<"\n\n";
	//inordr(root, vec);
	//cout<<"\n\n";

	//root = new node(10);
 //   root->left = new node(30);
 //   root->right = new node(15);
 //   root->left->left = new node(20);
 //   root->right->right = new node(5);

	/*vec.clear();
	cnvtoBST(root);
	cout<<"\n\n";
	preordr(root,vec);
	cout<<"\n\n";
	inordr(root, vec);
	cout<<"\n\n";

	cnvBSTtoBT(root);
	cout<<"\n\n";
	preordr(root,vec);
	cout<<"\n\n";
	inordr(root, vec);
	cout<<"\n\n";*/
	vector<int> vec2;

	int larr[] = {1,2,3,4,5,6,7};
	int lsize = sizeof(larr)/sizeof(larr[0]);
	lnode* lroot = createlist(larr, lsize);
	node* lstnoderoot = createBSTfromList( lroot);
	levelordr( lstnoderoot, vec2 );
	cout<<"\n\n";

	//vec.clear();
	
 	/*cout<<"\n\n";
	preordr(lstnoderoot, vec2);
	cout<<"\n\n";
	inordr(lstnoderoot, vec);
	cout<<"\n\n";

	node* croot = createTree(vec2, vec);
	cout<<"\n\n";
	vec2.clear();
	preordr(croot, vec2);
	cout<<"\n\n";
	vec.clear();
	inordr(croot, vec);
	cout<<"\n\n";*/

	//int height =0;
	//bool flag = isBalanced(lstnoderoot, height);

	//cout << "flag: " << flag << "\t" << "height: " << height << endl;

	/*vector<node*> vec_bst;
	
	vec_bst = createNBST(1,3);

	for(int i=0; i< vec_bst.size(); i++)
	{
		cout << "For" << i << ":" << endl;
		preordr(vec_bst[i], vec2);
		cout<<endl;
		levelordr( vec_bst[i] );
		cout<<"\n\n";
	}*/

	//cnvBSTtominheap( lstnoderoot);
	//cout<<"\n\n";
	//levelordr( lstnoderoot );
	//cout<<"\n\n";
	//preordr(lstnoderoot, vec2);
	//cout<<"\n\n";

	//vec2.clear();
	//levelordr( lstnoderoot, vec2 );
	//prn_vec(vec2);

	//node* bstnode = createBSTfromlvlTrv(vec2);
	//vec2.clear();
	//levelordr( bstnode, vec2 );

	//cout <<"\n\n";
	//cout << checkforBST(bstnode)<<"\n\n";

	//cout<<"\n\n";
	//
	//int k=5;
	//cout << KthSmallElemBST(bstnode,k) <<"\n\n";

	int pre[] = {20, 10, 11, 13, 12};

	int size = sizeof(pre)/sizeof(pre[0]);

	cout << check_1child(pre, size);

}





