#include <iostream>
using namespace std;

//==============STL========================================================================

#include <list>
#include <algorithm>
void process_stl_list()
{
	list<int>::iterator it;
	list<int> lst;
	lst.push_back(20), lst.push_back(15), lst.push_back(10), lst.push_back(2), lst.push_back(1);

	lst.sort();
	//sort(lst.begin(), lst.end());

	list<int> lst2;
	lst2.push_back(5), lst2.push_back(8), lst2.push_back(12), lst2.push_back(14), lst2.push_back(19);

	for(it = lst.begin(); it != lst.end(); it++)
	{
		cout << *it << "--->";
	}
	cout << "\n\n\n";

	for(it = lst2.begin(); it != lst2.end(); it++)
	{
		cout << *it << "--->";
	}

	cout << "\n\n\n";

	lst.merge(lst2);

	for(it = lst.begin(); it != lst.end(); it++)
	{
		cout << *it << "--->";
	}
	cout << "\n\n\n";

	cout << "list1 after merge operation is : ";
    for (int &x : lst) cout << x << " ";
    cout << endl;
	cout << "\n\n\n";

	it = lst.begin();
	
	advance(it, 2);

	cout << *it << endl;

	lst.emplace(it,100);
	it--;
	cout << *it << endl;


	cout << "\n\n\n";
}

struct node
{
	node(int idata=0)
	{
		_data = idata;
		_next = nullptr;	
	}
node* _next;
int _data;
};

void displaylist(node* headref)
{
	if(headref == nullptr) return;

	while(headref != nullptr)
	{
		cout << headref->_data <<"-->";
		if(headref->_next == nullptr) cout << "NULL" <<endl;
	    headref = headref->_next;
	}
}

void reverse(node** headref, int k )
{
	if(*headref == nullptr || (*headref)->_next == nullptr) return;

	node *prev = nullptr, *curr = (*headref), *next = curr->_next;

	int i=0;
	while(i < k && curr != nullptr)
	{
		curr->_next = prev;
		prev = curr;
		curr = next;

		if(curr)
			next = curr->_next;

		i++;
	}

	if(curr != nullptr)  reverse(&curr, k);

	(*headref)->_next = curr;
	*headref = prev;
}

void partition(node* phead, node** ppa)
{
	node* fast = phead->_next;
	node* slow = phead;

	while(fast != nullptr)
	{
		fast = fast->_next;
		if(fast != nullptr)
		{
			fast = fast->_next;
			slow = slow->_next;
		}
	}

	*ppa = slow->_next;
	slow->_next = nullptr;
}

node* mergeLst(node* a, node* b)
{
	node datum;
	node* temp = &datum;

	while( b && a)
	{
		if(b->_data < a->_data)
		{
			temp->_next = b;
			b = b->_next;
		}
		else
		{
			temp->_next = a;
			a = a->_next;
		}
		temp = temp->_next;
	}

	if(b)
	{
		temp->_next = b;
	}

	if(a)
	{
		temp->_next = a;
	}

	return datum._next;
}

void mergesort(node** pphead)
{
	if((*pphead) == nullptr || (*pphead)->_next == nullptr)
		return;

	node* a = nullptr;
	partition(*pphead, &a);

	mergesort(pphead);
	mergesort(&a);

	node* b = *pphead;
	
	*pphead = mergeLst(a, b);
}

void bubblesort(node** pphead)
{
	if((*pphead) == nullptr || (*pphead)->_next == nullptr) 
		return;

	node* en = nullptr;
	node* st = *pphead;
	node* prev = nullptr;
	bool swap = 0;
	int i=0;

	while(st->_next != en)
	{
		if(st->_data > (st->_next)->_data)
		{
			node* temp = st->_next;
			st->_next = temp->_next;
			temp->_next = st;

			if(prev != nullptr)
				prev->_next = temp;
			else
			{
				*pphead = temp;
			}
			prev = temp;
			swap = 1;
		}
		else
		{			
			prev = st;
			st = st->_next;
		}

		if(st->_next == en && en != (*pphead)->_next)
		{
			en = st;
			st = *pphead;
			prev = nullptr;
		}
	}
}

void quick_sort(node** pphead)
{
	if((*pphead) == nullptr || (*pphead)->_next == nullptr) 
		return;

	node* pvt = *pphead;

	node* a = nullptr;
	node* b = nullptr;
	node* atmp = nullptr;
	node* btmp = nullptr;

	node* temp = (*pphead)->_next;

	while(temp)
	{
		if(temp->_data <= pvt->_data)
		{
			if(a)
			{
				atmp->_next = temp;
				atmp = atmp->_next;
			}
			else
			{
				a = temp;
				atmp = temp;
			}
		}
		else
		{
			if(b)
			{
				btmp->_next = temp;
				btmp = btmp->_next;
			}
			else
			{
				b = temp;
				btmp = temp;
			}
		}
		temp = temp->_next;
	}

	if(atmp)
	{
		atmp->_next = nullptr;	
	}
	else
	{
		a = *pphead;
		a->_next = nullptr;
	}

	if(btmp)
		btmp->_next = nullptr;
	else
	{
		b = *pphead;
		b->_next = nullptr;
	}

	quick_sort(&a);
	quick_sort(&b);

	*pphead = mergeLst(a, b);
}

void recur_reverse(node** pphead)
{
	if(*pphead == nullptr || (*pphead)->_next == nullptr)
		return;

	node* nxt = (*pphead)->_next;

	recur_reverse(&nxt);

	(*pphead)->_next->_next = *pphead;
	(*pphead)->_next = nullptr;

	*pphead = nxt;
}

bool findandremloop(node* phead)
{
	node* slow = phead;
	node* fast = phead->_next;
	bool loop = 0;

	while(fast != nullptr)
	{
		if(slow == fast)
		{
			loop = 1;
			break;
		}

		fast = fast->_next;

		if(fast)
		{
			fast = fast->_next;
			slow = slow->_next;
		}
	}

	if(!loop)
		return 0;

	slow = phead;

	while(slow != fast->_next)
	{
		slow = slow->_next;
		fast = fast->_next;
	}

	fast->_next = nullptr;

	return 1;
}

void saperateevenodd(node** pphead)
{
	node* temp = *pphead;
	node* prev = nullptr;

	if(temp->_data %2 == 0)
		prev = temp;

	while(temp && temp->_next)
	{
		 if(temp->_next->_data %2 == 0)
		 {
			 if(prev == nullptr)
			 {
				 node* temp2 = *pphead;
				 *pphead = temp->_next;
				 temp->_next = temp->_next->_next;
				 (*pphead)->_next = temp2;
				 prev = *pphead;
			 }
			 else if(prev->_next != temp->_next)
			 {
				 node* temp2 = prev->_next;
				 prev->_next = temp->_next;
				 temp->_next = temp->_next->_next;
				 prev->_next->_next = temp2;
				  prev = prev->_next;
			 }

		 }

		 temp = temp->_next;
	}

}
//=========================================================================================

int main()
{
	struct node* root = new node(10);
	struct node* node1 = root;
	int n=8;
	node* node2 = nullptr;
	for(int i=2; i<= n; i++)
	{
		node1->_next = new node(10-i);
		node1 = node1->_next;	
		//if((10-i) == 5)
		//	node2 = node1;
	}
	root->_data = 11;
	//node1->_next = node2;
	displaylist(root);
	saperateevenodd(&root);
	//cout << findandremloop(root) << "\n\n";
	displaylist(root);
	//reverse(&root, 3);
	//displaylist(root);
	//process_stl_list();
	//bubblesort(&root);
	//quick_sort(&root);
	//recur_reverse(&root);
	//displaylist(root);
}