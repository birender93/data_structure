#include <iostream>
using namespace std;
#include <ctime>
#include <chrono>
using namespace std::chrono;

//void prnt_arr(int arr[], int size)
//{
//	for(int i = 0; i< size; i++)
//	{
//		cout <<arr[i] << "\t";
//	}
//}
//
//void swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//
//void rot_arr_brut(int arr[], int size, int d)
//{
//	int tmp;
//	d = d%size;
//
//	for(int i=0; i<d; i++)
//	{
//		tmp = arr[0];
//		for(int j=0; j<size-1; j++)
//		{
//			arr[j] = arr[j+1];
//		}
//		arr[size-1] = tmp;
//	}
//}
//
//void rot_arr_m1(int arr[], int size, int d)
//{
//	d = d%size;
//	int tmp = arr[d-1];
//
//	for(int i=0; i<(size-d); i++)
//	{
//		swap(arr[i], arr[i+d]);
//	}
//
//	for(int i = size-d; i < ((size-d) + d/2); i++)
//	{
//		swap(arr[i], arr[ (size-d) + (size-i-1)]);
//	}
//}
//
//void reverse(int arr[], int sind, int eind)
//{
//	for(int i=sind; i <= (sind+eind)/2; i++)
//	{
//		swap(arr[i], arr[sind + eind -i]);
//	}
//}
//
//void rot_arr_revrsl(int arr[], int size, int d)
//{
//	d = d%size;
//
//	if(d)
//	{
//		reverse(arr, 0, d-1);
//		reverse(arr, d, size-1);
//		reverse(arr, 0, size-1);
//	}
//}
//
//void wave_sort(int arr[], int size)
//{
//	for(int i=0; i<size-1; i+=2)
//	{
//		if(i>0 && arr[i] < arr[i-1])
//			swap(arr[i], arr[i-1]);
//		
//
//		if(arr[i] < arr[i+1])
//			swap(arr[i], arr[i+1]);
//	}		
//}
//
//#include <algorithm>
//#include <functional>
//#include <vector>
//
//	void func_print(int value) { 
//    std::cout << "int" << std::endl;
//}
//void func_print(void* value) {
//    std::cout << "void"<< std::endl;
//}
//
//long int factorial(int n)
//{
//    if(n == 0 || n==1) return 1;
//    
//    return (n * factorial(n-1));
//}
//vector<int> repeatedNumber(const vector<int> &A) {
//    
//    int n = A.size(), dif;
//    long int esum = n*(n-1)/2, efact = 1, asum=0, afact=1;
//    
//    efact = factorial(n);
//    
//    for(int i=0; i<n; i++)
//    {
//        asum +=A[i];
//        afact *=A[i];
//    }
//    
//    dif = esum - asum;
//    
//    
//    vector<int> ans;
//    
//    ans.push_back(dif*afact/(afact-efact));
//    ans.push_back(ans[0]-dif);
//    
//    return ans;
//}
//
//void prnt_pascal_tri(int row)
//{
//	
//
//}
//
//vector<int> flip(string A) {
//    
//    int msum =-1, l=0,r=0, ll=0, lsum=0;
//    
//    for(int i=0; i< A.size(); i++)
//    {
//        if(A[i]-48)
//            lsum--;
//        else
//            lsum++;
//            
//        if(msum < lsum)
//        {
//            msum = lsum;
//            l=ll+1;
//            r = i+1;
//        }
//        
//        if(lsum < 0)
//        {
//            lsum=0;
//            ll = i+1;
//        }
//    }
//    
//    vector<int> vec;
//    if(l>0 && r>0)
//    {
//        vec.push_back(l);
//        vec.push_back(r);
//    }
//    
//    return vec;
//}
//
//void generateMatrix(int A) {
//    
//	A = 4;
//    vector<vector<int>> vecvec;
//    vector<int> vec;
//	int j = 0;
//	int i = 0;
//	int cnt=1;
//    
//    for(int k=0; k<A; k++)
//    {
//        for(int j=0; j<A;j++)
//        {
//            vec.push_back(j+1);
//        }
//
//        vecvec.push_back(vec);
//		vec.clear();
//    }
//
//	int maxr = A, minr = 0, minc=0, maxc = A;
//    while(maxr >0)
//    {
//    while(j<maxc)
//    {
//        vecvec[i][j] = cnt;
//        cnt++;
//        j++;
//    }
//    i++;j--; maxc--;
//    while(i<maxr)
//    {
//        vecvec[i][j] = cnt;
//        cnt++;
//        i++;
//    }
//    j--;i--;maxr--;
//    while(j>=minc)
//    {
//        vecvec[i][j] = cnt;
//        cnt++;
//        j--;
//    }
//    i--;j++;minc++;
//    while(i>minr)
//    {
//        vecvec[i][j] = cnt;
//        cnt++;
//        i--;
//    }
//	i++;j++;minr++;
//}
//
//		  for(int k=0; k<A; k++)
//    {
//        for(int j=0; j<A;j++)
//        {
//            cout << vecvec[k][j] << "\t"; 
//        }
//
//       cout<<"\n\n";
//    }
//
//	  cout <<"\n\n\n";
//}
//
//#include<deque>
//vector<int> allFactors(int A) {
//    
//    deque<int> dque;
//    
//    for(int i = sqrt(A); i >0; i--)
//    {
//        if(A%i == 0)
//        {
//            dque.push_front(i);
//            
//            if(A/i != i)
//                dque.push_back(A/i);
//        }
//    }
//    
//    vector<int> vec;
//    for(int i=0; i<dque.size(); i++)
//    {
//        vec.push_back(dque[i]);
//    }
//    
//    return vec;
//}
//
//#include<string>
//
//string findDigitsInBinary(int A) {
//	A=2;
//    string str;
//    str.clear();
//    int num = A;
//	char zero = '0';
//	char one = '1';
//    int cnt = 0;
//    while(num > 0)
//    {
//		cnt++;
//        if(num % 2 == 0)
//            str.append(&zero);
//        else
//            str.append(&one);
//        
//        num = num/2;
//		str.resize(cnt);
//    }
//
//	str.shrink_to_fit();
//    
//    for(int i=0; i < str.size()/2; i++)
//    {
//        char tmp = str[i];
//		str[i] = str[str.size()-1-i];
//		str[str.size()-1-i] = tmp;
//    }
//
//	for(int i=0; i < str.size(); i++)
//    {
//		cout << str[i] << "\t";
//    }
//
//	cout <<endl;
//
//	return str;
//}
//
//vector<int> sieve(int n) {
//    // Do not write main() function.
//    // Do not read input, instead use the arguments to the function.
//    // Do not print the output, instead return values as specified
//    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
//    vector<bool> isprime(n+1,true);
//    vector<int> ans;
//    isprime[0]=false;
//    isprime[1]=false;
//    for(int p=2;p*p<=n;p++)
//    {
//        if(isprime[p])
//        {
//            for(int i=p*2;i<=n;i=i+p)
//            {
//                isprime[i]=false;
//            }
//        }
//    }
//    for(int i=2;i<=n;i++)
//    {
//        if(isprime[i])
//        ans.push_back(i);
//    }
//    return ans;
//    
//}
//#include <map>
//
//int getdstn(int xor1)
//{
//    int sum=0;
//    while(xor1)
//    {
//        if(xor1%2 != 0)
//            sum++;
//            
//        xor1 = xor1/2;
//    }
//    
//    return sum;
//}
//
//int hammingDistance(const vector<int> &A) {
//    
//    int xor1;
//    
//    map<int, int> xormap;
//    int sum = 0;
//    
//    for(int i=0; i< A.size(); i++)
//    {
//        for(int j=0; j<A.size(); j++)
//        {
//            if(i == j) continue;
//            
//            xor1 = A[i]^A[j];
//            
//            if(xormap.find(xor1) != xormap.end())
//            {
//                sum = sum + (xormap.find(xor1))->second;
//            }
//            else
//            {
//				int dist = getdstn(xor1);
//                sum = sum + dist;
//				xormap.insert(pair<int,int>(xor1,dist));
//            }
//        }
//    }
//	return sum;    
//}
//
//vector<string> fizzBuzz(int A) {
//
//	A=15;
//    vector<string> vec;
//    string str;
//	char buffer[33];
//    for(int i=1; i<=A; i++)
//    {
//         str.clear();
//        
//        if(i % 3 == 0 && i % 5 == 0)
//        {
//			str = "FizzBuzz";
//        }
//		else if(i % 5 == 0)
//		{
//            str = "Buzz";
//		}
//		else if(i % 3 == 0)
//		{
//			str = "Fizz";
//		}
//		else
//		{
//			str = std::to_string(i);
//		}
//
//		vec.push_back(str);      
//    }
//
//	for(int i=0; i< vec.size(); i++)
//	{
//		cout << vec[i] << "\t";
//	}
//	cout << "\n\n\n";
//
//	return vec;
//}
//
//
//class complex{
//
//public:
//
//	complex()
//	{
//		_real = 0;
//		_img = 0;		
//	}
//
//	complex(int ireal, int iimg)
//	{
//		_real = ireal;
//		_img = iimg;
//	}
//
//	~complex()
//	{
//		_real = 0;
//		_img = 0;
//	}
//
//	void setvalues(int ireal, int iimg)
//	{
//		_real = ireal;
//		_img = iimg;
//	}
//
//	void getvalues(int& ireal, int& iimg)
//	{
//		ireal = _real;
//		iimg = _img;
//	}
//
//	complex operator +(complex& ic)
//	{
//		complex c;
//
//		int real, img;
//
//		ic.getvalues(real, img);
//
//		c.setvalues(_real + real, _img+img);
//
//		return c;
//	}
//
//private:
//	int _img;
//	int _real;
//};
//
//
//int isPower(int A) {
//
//	A = 43659;
//    int num;
//    int flag = 0;
//    
//    if(A == 1) return !flag;
//    
//    for(int i=2; i <= sqrt(A); i++)
//    {
//        if(A % i == 0)
//        {
//            num = sqrt(A);
//            if(num == sqrt(A))
//            {
//                flag = 1;
//                break;
//            }
//            else
//            {
//                num = sqrt(A/i);
//                if(num == sqrt(A/i))
//                {
//                    flag = 1;
//                    break;
//                }
//            }
//        }
//    }
//    return flag;
//}
//
//
//
//int main()
//{	
//	int size = 6;
//	int* arr = new int[size];
//
//	for(int i = 0; i<size; i++)
//		arr[i] = i+1;
//
//	prnt_arr(arr,size);
//	cout << "\n\n\n\n==========================================";
//
//	//cout <<"===========Array Rotation================"<<endl;
//	
//	//int d = 7000;	
//	//
//	// high_resolution_clock::time_point t1 = high_resolution_clock::now();
// //   rot_arr_brut(arr,size,d);
//	// //rot_arr_revrsl(arr,size,d);
// //   high_resolution_clock::time_point t2 = high_resolution_clock::now();
//
// //   auto duration = duration_cast<microseconds>( t2 - t1 ).count();
//
// //   cout << "\n\n\n\nExecution time: " << duration;
//
//	//cout <<"\n\nArray after rotation:\t";
//	//prnt_arr(arr,size);
//
//	//cout << "\n\n\n\n==========================================";
//
//	cout <<"=================Array Sort in Wave form================"<<endl;
//	//sort(arr,arr+size, greater<int>());
//
//	wave_sort(arr, size);
//	prnt_arr(arr,size);
//
//	cout << "\n\n\n\n==========================================";
//
//	if(arr != nullptr)
//	{
//		delete []arr;
//		arr = nullptr;	
//	}
//
//    func_print(0);
//    func_print(nullptr);
//
//	int n = 1.999;
//
//	//cout << n;
//
//	int row =5;
//	//prnt_pascal_tri(row);
//
//	//string A = "010";
//	//flip(A) ;
//
//	cout << "\n\n\n\n==========================================\n\n\n";
//
//	//generateMatrix(3);
//
//	//findDigitsInBinary(2);
//
//	//sieve(11);
//
//	vector<int> A;
//	A.push_back(2);		A.push_back(4);		A.push_back(6);
//	//hammingDistance(A);
//
//	int sum=0;
//	for(int i=0; i < 31; i++)
//	{
//		sum= sum + pow(2,i);
//	}
//
//
//	//cout<<"\n\n"<< sum <<"\n\n" << INT_MIN<<"\n\n";
//
//	cout <<(INT_MIN-1) << endl;
//	cout << INT_MAX << endl;
//	//fizzBuzz(5);
//
//	complex c1(1,2);
//	complex c2(3,4);
//
//	complex c3 = c1+c2;
//
//	int real, img;
//
//	c3.getvalues(real,img);
//
//	cout << "Real: " << real << "Img: " << img;
//
//	cout <<endl;
//
//	isPower(43659);
//}
//
//
//
//#include <queue>
//
////#include<bits/stdc++.h>
////using namespace std;
//
//void pascal_trn(int A)
//{
//   queue<int> que;
//    que.push(1);
//    int size = que.size();
//    int row = 1;
//	int sum=0;
//    while(row <=A)
//    {
//		if(row == que.size())
//			que.push(1);
//
//        int fs = que.front();
//		cout << fs <<"\t";
//		sum += fs;
//        que.pop();
//        size--;
//        
//        if(size == 0)
//        {
//            que.push(fs);
//            size = que.size();
//            row++;            
//			cout <<endl;
//        }
//        else
//            que.push(fs+que.front());
//    }
//
//	cout<<"\n\n" << sum <<"\n\n";
//}
//
//
// 
//int sizeofdatatype()
//{
//    cout << "Size of char : " << sizeof(char) << " byte" << endl;
//    cout << "Size of int : " << sizeof(int) << " bytes" << endl;
//    cout << "Size of short int : " << sizeof(short int) << " bytes" << endl;
//    cout << "Size of long int : " << sizeof(long int) << " bytes" << endl;
//    cout << "Size of signed long int : " << sizeof(signed long int) << " bytes" << endl;
//    cout << "Size of unsigned long int : " << sizeof(unsigned int) << " bytes" << endl;
//    cout << "Size of float : " << sizeof(float) << " bytes" <<endl;
//    cout << "Size of double : " << sizeof(double) << " bytes" << endl;
//    cout << "Size of wchar_t : " << sizeof(wchar_t) << " bytes" <<endl;
//     
//    return 0;
//}
//
//int main() {
////  int T;
////  cin>>T;
////  cin.clear();
////  cin.ignore(200,'\n');
////  
////  for(int i=0; i <T; i++)
////  {   
////      string str;
////      int flag=1;
////      int arr[26] = {0};
////      getline(cin,str);
////      
////      if(str.size() == 0) flag=0;
////      
////      int indx=0;
////      for(int i=0; i<str.size(); i++)
////      {
////          if(isalpha(str[i]))
////          {
////            indx = str[i] - 'a';
////            arr[indx]++;
////          }
////      }
////      
////      for(int i=0; i<26; i++)
////      {
////           if(!arr[i])
////            {
////              flag = 0;
////               break;
////            }
////      }
////      if(flag)
////          cout << "yes" <<endl;
////        else
////         cout << "no"<<endl;
////  }
////  return 0;
////}
//
//	   // pascal_trn(3);
//
//	sizeofdatatype();
//
//	
//	int *ptr = NULL;
//	free(ptr);
//
//    
//    return 0;
//}


#include <iostream>
using namespace std;

class Test {
	int x;
public:
	Test() {
		cout << "Constructor called \n";
	}
	void* operator new(size_t size);
	void* operator new[](size_t size)
	{
		void *storage = malloc(size);
		cout << "new called \n";
		return storage;
	}
	void operator delete(void*);
	
	~Test() { cout << "Destructor called \n"; }
};


void* Test::operator new(size_t size)
{
	void *storage = malloc(size);
	cout << "new called \n";
	return storage;
}

void Test::operator delete(void *p )
{
	cout<<"delete called \n";
	free(p);
}

int main()
{
	Test *m = new Test();
	delete m;

	Test *m2 = new Test[10];
	return 0;
}


