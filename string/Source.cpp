#include <iostream>
using namespace std;
#include <string>

int main()
{
	string str = "Hello Wor l d";
	int n = str.size();
	for(int i=0; i<n/2; i++)
	{
		char ch = str[i];
		str[i] = str[n-i-1];
		str[n-i-1] = ch;
	}

	cout << str<<endl;
}


