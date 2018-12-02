//KMP Algo
#include <iostream>
using namespace std;
#include <vector>

int main()
{
	string str("AAABAAABA");
	string str2("AAB");
	vector<int> vec;

	for(int i=0; i <= (str.size()-str2.size()); i++)
	{
		bool fnd = true;
		for(int j=0; j < str2.size(); j++)
		{
			if(str2[j] != str[i+j])
			{
				fnd = false;
				break;
			}
		}
		if(fnd)
		{
			vec.push_back(i);
		}
	}

	if(vec.size())
	{
		cout<<"indx: ";
		for(int i=0; i<vec.size(); i++)
		{
			cout<<"\t" << vec[i]+1;
		}
	}
	else
		cout << "not fnd"<<endl;

	getchar();

return 0;
}


