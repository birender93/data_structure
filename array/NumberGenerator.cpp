// Geek.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include<string>

using namespace std;

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;
 
    // This is checked so that we can skip 
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;
 
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
 
    return true;
}

void GenreateString(int tLen,string input,string res,int &count, int index)
{
	if(res.length() == tLen)
    {
	    cout<<res<<endl;
		if(isPrime(stoi(res)))
		{
			count++;
		}
		return;
	}
	for(int j=index; j<input.length();j++)
	{
		string out = res + input.at(j);
		GenreateString(tLen, input, out, count,j+1);
	
	}
}

int main(int argc, char* argv[])
{
	string input = "123";
	int count  = 0;

	for(int i=1; i<=6 && i<=input.length(); i++)
	{
		GenreateString(i,input,"",count,0);
	
	}
	cout<<count<<endl;
	return 0;
}

