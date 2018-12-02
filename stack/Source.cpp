#include<iostream>
using namespace std;
#include<stack>

int prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
 
    case '^':
        return 3;
    }
    return -1;
}

void infixtopostfix()
{
		string str = "1*2+3*4+5^2";
	string pfstr;

	stack<char> cstk;

	for(int i=0; i<str.size(); i++)
	{
		char ch = str[i];

		if(isdigit(ch))
		{
			cout<<ch;
			pfstr.push_back(ch);
		}
		else
		{
			if(cstk.empty() || prec(ch) > prec(cstk.top()))
			{
				cstk.push(ch);
			}
			else
			{
				while(!cstk.empty() && prec(ch) <= prec(cstk.top()))
				{
					cout<<cstk.top();
					pfstr.push_back(cstk.top());
					cstk.pop();
				}
				cstk.push(ch);
			}
		}
	}

	while(!cstk.empty())
	{
		cout<<cstk.top();
		pfstr.push_back(cstk.top());
		cstk.pop();
	}

	cout<<"\n\n\n";
	stack<int> istk;

	for(int i=0; i<pfstr.size(); i++)
	{
		if(isdigit(pfstr[i]))
		{
			istk.push(pfstr[i]-'0');
		}
		else if(!istk.empty())
		{
			int a = istk.top();
			istk.pop();
			int b = istk.top();
			istk.pop();

			switch(pfstr[i])
			{
				case '+': istk.push(b+a);	break;
				case '-': istk.push(b-a);	break;
				case '*': istk.push(b*a);	break;
				case '/': istk.push(b/a);	break;
				case '^': istk.push(pow(b,a));	break;  
				default: break;
			}			
		}
	}

	if(!istk.empty())
	cout << istk.top();
	cout<<"\n\n\n";
}

class kstacks
{
	int* arr;
	int* top;
	int* next;
	int k, n, free;

public:

	kstacks()
	{
		k=3;
		n=3;

		arr = new int[n];
		top = new int[k];
		next = new int[n];
		free = 0;

		for(int i=0; i<n; i++)
		{
			next[i] = i+1;

			if(i == n-1)
				next[i] = -1;

			if(i<k)
				top[i] = -1;
		}
	}

	bool push(int val, int sn)
	{
		if( sn > k || free == -1)
			return false;

		arr[free] = val;
		int i = free;
		free = next[i];

		int j = top[sn];
		top[sn] = i;
		next[i] = j;

		return true;
	}

	bool pop(int sn)
	{
		if( sn > k || top[sn] == -1)
			return false;

		int j = top[sn];
		top[sn] = next[j];

		next[j] = free;
		free = j;

		return true;
	}

	int peek(int sn)
	{
		if(sn > k || top[sn] == -1)
			return -1;

		return arr[top[sn]];
	}

	bool isempty(int sn)
	{
		if(top[sn] == -1)
			return true;

		return false;
	}

	bool isfull()
	{
		return (free == -1);
	}

};

void KStacksinArr()
{
	kstacks kst;

	kst.push(1,1);
	kst.push(2,2);
	kst.push(3,3);

	kst.pop(2);
	int i = kst.peek(3);
	i = kst.peek(2);
	bool res = kst.push(2,2);
	res = kst.push(4,1);
	i = kst.peek(1);

	res = kst.isfull();
}

int main()
{
	KStacksinArr();

return 0;
}



