////#include <iostream>
////using namespace std;
////
////int sub_arr(int arr[], int size, int k)
////{
////	int sum = 0, cnt = 0, mxcnt = 0;
////
////	for(int i = 0; i < size; i++)
////	{
////		if((sum + arr[i]) == k)
////		{
////			if(cnt > mxcnt)
////			mxcnt = cnt;	
////		}
////		else if( (sum + arr[i]) < k)
////		{
////			sum += arr[i];
////			cnt++;
////		}
////		else if(cnt > 0 )
////		{
////			sum -= arr[i - cnt];
////			cnt--;
////			i--;			
////		}
////		if(cnt > mxcnt)
////			mxcnt = cnt;	
////	}
////return cnt;
////}
////
/////* function to print an array */
////void printArray(int arr[], int size);
//// 
/////*Fuction to get gcd of a and b*/
////int gcd(int a,int b);
//// 
/////*Function to left rotate arr[] of siz n by d*/
////void leftRotate(int arr[], int d, int n)
////{
////  int i, j, k, temp;
////  for (i = 0; i < gcd(d, n); i++)
////  {
////    /* move i-th values of blocks */
////    temp = arr[i];
////    j = i;
////    while(1)
////    {
////      k = j + d;
////      if (k >= n)
////        k = k - n;
////      if (k == i)
////        break;
////      arr[j] = arr[k];
////      j = k;
////    }
////    arr[j] = temp;
////  }
////}
//// 
/////*UTILITY FUNCTIONS*/
/////* function to print an array */
////void printArray(int arr[], int size)
////{
////  int i;
////  for(i = 0; i < size; i++)
////    printf("%d ", arr[i]);
////}
//// 
/////*Fuction to get gcd of a and b*/
////int gcd(int a,int b)
////{
////   if(b==0)
////     return a;
////   else
////     return gcd(b, a%b);
////}
////
////void par_rev(int arr[], int si, int ei)
////{
////	int temp;
////	while(si<ei)
////	{
////		temp = arr[si];
////		arr[si] = arr[ei];
////		arr[ei] = temp;
////		si++;
////		ei--;	
////	}
////}
////
////void rev(int arr[], int size, int d)
////{
////	if(size <= 0 || d<=0)
////		return;
////
////	par_rev(arr, 0, d-1);
////	par_rev(arr, d, size-1);
////	par_rev(arr,0,size-1);
////}
////
////int bn_srch(int arr[], int si, int ei, int el )
////{
////	int ind = -1;
////	if(si >ei)
////		return ind;
////
////	int mid = (si+ei)/2;
////
////	if(arr[mid] == el)
////		return mid;
////
////	if(arr[mid] < arr[si])
////	{
////		if(el > arr[mid] && el <= arr[ei])
////		{
////			return bn_srch(arr, mid+1, ei, el );	
////		}
////		else
////			return bn_srch(arr, si, mid-1, el);
////	}
////
////	if(el < arr[mid] && el >= arr[si])
////		return bn_srch(arr, si, mid-1, el);
////	else
////		return bn_srch(arr, mid+1, ei, el );	
////}
////
////#include <vector>
////
////void swap(int &a, int &b)
////{
////    int temp = a;
////    a = b;
////    b = temp;
////}
////
////void arrange(vector<int> &A) {
////
////	int ind = 0, val = A[ind];
////
////	do
////	{
////		for(int i= 0; i<A.size(); i++)
////		{
////			if(ind == A[i])
////			{
////				ind = i;
////				swap(A[i], val);
////				break;
////			}       
////		}
////	}while(ind != 0);
////}
////
////void prn_vec(vector<int> A)
////{
////	for(int i =0; i<A.size(); i++)
////	{
////		cout << A[i] <<"\t";
////	}
////
////	cout <<endl;
////}
////
////#include <stack>
////
////string simplifyPath(string A) {
////    
////  stack<char> st;
////  
////  for(int i=0; i< A.size()-1; i++)
////  {
////    if(A[i] == '.')
////    {
////        if(i+1 < A.size() && A[i+1] == '.')    
////        {
////            if(!st.empty() && st.size() != 1)
////            {
////                st.pop();
////            }
////            while(!st.empty() && st.top() != '/')
////                st.pop();
////            i++;
////        }
////        i++;
////    }
////    else
////    {
////        if(!st.empty()  && st.top() == '/' && A[i] == '/')
////        continue;
////        
////        st.push(A[i]);
////    }
////  }
////  
////  string B("");
////  
////  while(!st.empty())
////  {
////      B+= st.top();
////      st.pop();
////  }  
////  reverse(B.begin(), B.end());
////   if(B.size() >1 && B[B.size()-1]=='/')
////  {
////      B.erase(B.size()-1,1);
////  }
////  
////  return B;
////}
////
////int trap(const vector<int> &A) {
////    
////    int sum = 0, lf=0, rt=0;
////    
////    for(int i =1; i<A.size(); i++)
////    {
////        int j =lf = i;
////        while( j >=0 )
////		{
////			if(A[j] > A[lf])
////				lf = j;
////            j--;
////		}
////        int k = rt = i;
////        while( k < A.size())
////		{
////			if(A[k] > A[rt])
////				rt = k;
////            k++;
////		}
////
////        k = min(A[lf], A[rt]) -A[i];
////
////		if(k > 0)
////			sum += k;
////    }
////    
////    return sum;
////}
////
////int main()
////{
////	//{//FIND MAXIMUN SUBARRAY HAVING SUM EQUAL TO GIVEN SUM
////	//int arr[] = {1,5,1,1,0,2,0,1,1};//{ 1,2,-1,5,-3,8,0,1,1};
////
////	//int mx = sub_arr(arr, 10, 4);
////
////	//cout << "MAXIMUN SUBARRAY HAVING SUM EQUAL TO GIVEN SUM: "<<mx << endl;
////	//cout <<"\n\n\n\n======================================================\n\n\n"<<endl;
////	//}
////	//
////	//
////	//{//ROTATE A PART OF ARRAY 
////	//    
////	// {//BY USING GCD
////	//	 cout <<"REVERSE A PART OF ARRAY ; BY USING GCD"<<endl;
////	//	  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
////	//	leftRotate(arr, 6, 9);
////	//	printArray(arr, 9);
////	//	cout <<"\n\n\n\n======================================================\n\n\n"<<endl;
////	// }
////
////	// {//REVERSAL ALGORTIHM
////	//	  cout <<"REVERSE A PART OF ARRAY ; REVERSAL ALGORTIHM"<<endl;
////	//	  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
////	//	rev(arr, 9, 6);
////	//	printArray(arr,9);	 
////	//	cout <<"\n\n\n\n======================================================\n\n\n"<<endl;
////
////	//	{//O(Logn) search in sorted rotated
////	//		cout << "index of 1 in array: " << bn_srch(arr, 0, 9, 9)+1;
////	//		cout <<"\n\n\n\n======================================================\n\n\n"<<endl;
////	//	}
////	// }
////	//}
////
////	//{//find largest sum of (i*arr[i])
////	//	
////	//	int arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};//{1,20,2,10};
////	//	int size = sizeof(arr)/sizeof(int);
////	//	int sum = 0;
////
////	//	for(int i = size; i>0; i--)
////	//	{
////	//		int lsum = 0;
////	//		for(int j=0; j <size; j++)
////	//		{
////	//			lsum += arr[j]* ((i+j)%size);			
////	//		}		
////
////	//		if(sum < lsum)
////	//			sum = lsum;
////	//	}
////
////	//	cout << " largest sum of (i*arr[i]): " << sum;
////	//	cout <<"\n\n\n\n======================================================\n\n\n"<<endl;
////	//}
////
////	//{//display array after k rotations
////
////	//	int arr[] = {1, 3, 5, 7, 9};
//// //       int k1 = 14; 
////
////	//	int size = sizeof(arr)/sizeof(int);
////	//	k1 = k1%size;
////
////	//	cout <<"Array after "<<k1<<" rotations: ";
////	//	int i = k1;
////	//	do
////	//	{
////	//		if(i == size)
////	//			i=0;
////
////	//		cout << arr[i] << "\t";
////	//		i++;		
////	//	
////	//	}while(i!= k1);	
////	//	cout <<"\n\n\n\n======================================================\n\n\n"<<endl;
////	//}
////
////	//getchar();
////
////	vector<int> A;
////	int arr[] = {3, 0, 0, 2, 0, 4};
////
////	int size = sizeof(arr)/sizeof(arr[0]);
////
////	for(int i=0; i< size; i++)
////	{
////		A.push_back(arr[i]);
////	}
////	//
////	//prn_vec(A);
////	//arrange(A);
////
////	//prn_vec(A);
////
////	//string A("/a/./b/../../c/");
////
////	//simplifyPath(A);
////
////	cout << trap(A);
////
////	return 0;
////}
////
////
//
//#include <iostream>
//#include <fstream>
//#include<sstream>
//#include <map>
//using namespace std;
//#include <vector>
//#include <stack>
//
//int largestRectangleArea(vector<int> &A) {
//
//    int area = 0;
//    vector<int> lft;
//    lft.push_back(0);
//    vector<int> rt;
//    rt.push_back(A.size()-1);
//    stack<int> st;
//    st.push(0);
//    
//    for(int i=1; i< A.size(); i++)
//    {
//        while(!st.empty() && A[st.top()] > A[i]) st.pop();
//        
//        if(!st.empty())
//            lft.push_back(st.top()+1);
//        else
//            lft.push_back(0);
//        
//        st.push(i);
//    }
//    
//    while(!st.empty())
//        st.pop();
//    
//    st.push(A.size()-1);
//    for(int i=A.size()-2; i >=0; i--)
//    {
//        while(!st.empty() && A[st.top()] > A[i]) st.pop();
//        
//        if(!st.empty())
//            rt.push_back(st.top()-1);
//        else
//            rt.push_back(A.size()-1);
//        
//        st.push(i);
//    }
//    
//    std::reverse(rt.begin(), rt.end());
// 
//    for(int i=0; i < A.size(); i++)
//    {
//        int width = rt[i]-lft[i]+1;
//        if(!width) width =1;
//        
//        if(area < width*A[i])
//        {
//            area = width*A[i];
//        }
//    }
//    return area;
//}
//
//#include <queue>
//
//class TreeNode
//{
//public:
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//
//	TreeNode(int data)
//	{
//		val = data;
//		left = nullptr;
//		right = nullptr;
//	}
//};
//
//vector<vector<int>>  BTree_verprnt(TreeNode* A)
//{
//	queue<pair<int, TreeNode*>> que;
//
//	que.push(pair<int, TreeNode*> (0, A));
//
//	pair<int, TreeNode*> pr;
//	TreeNode* temp = nullptr;
//	int val=0;
//
//	map<int, vector<int>> mp;
//
//	while(!que.empty())
//	{
//		pr = que.front();
//		val = pr.first;
//		temp = pr.second;
//	    que.pop();
//
//		mp[val].push_back(temp->val);
//
//		if(temp->left)
//		{
//			que.push(pair<int,TreeNode*>(val-1, temp->left));
//		}
//
//		if(temp->right)
//		{
//			que.push(pair<int,TreeNode*>(val+1, temp->right));
//		}
//	}
//
//	vector<vector<int>> vvec;
//
//	map<int, vector<int>>::iterator mpitr = mp.begin();
//
//	for(; mpitr != mp.end(); mpitr++)
//	{
//		vvec.push_back(mpitr->second);
//	}
//
//	return vvec;
//}
//
//vector<int> solve(string A, vector<string> &B) {
//    vector<string> svec;
//    map<int,vector<int>> vmap;
//    
//	
//    int pos = 0;
//    int nxpos = A.find("_", pos);
//    
//    while(nxpos != string::npos)
//    {
//        svec.push_back(A.substr(pos, nxpos-pos));
//        pos = nxpos+1;
//		nxpos = A.find("_", pos);
//    }    
//    svec.push_back(A.substr(pos,A.size()-pos) );
//
//	string srev;
//	for(int i=0; i < B.size(); i++)
//	{
//		srev = B[i];
//		int flag = 0;
//		for(int j=0; j< svec.size(); j++)
//		{
//			if(srev.find(svec[j]) != string::npos)
//				flag++;
//		}
//
//		vmap[flag].push_back(i);
//	}
//    
//vector<int> ivec;
//
//map<int,vector<int>>::reverse_iterator vmapitr;
//
//for(vmapitr = vmap.rbegin(); vmapitr != vmap.rend(); vmapitr++)
//{
//	for(int i = 0; i < vmapitr->second.size(); i++)
//	{
//		ivec.push_back(vmapitr->second[i]);
//	}
//}
//
//return ivec;
//}
//
//
//
// int checkbal(TreeNode* A, int& bal)
// {
//	int dpth = 0;
//    int lftdp = -1;
//    int rtdp = -1;
//    
//    if(A->left)
//        lftdp = checkbal(A->left, bal);
//    
//    if(bal)
//    {
//        if(A->right)
//            rtdp = checkbal(A->right, bal);
//    }
//
//
//    if(abs(lftdp-rtdp) <= 1)
//	{		
//		if(lftdp > -1 || rtdp >-1)
//			dpth += std::max(lftdp, rtdp);
//		
//		bal = 1;
//	}
//	else
//	{
//		bal = 0;
//	}
//        
//    return dpth;
// }
// 
//int isBalanced(TreeNode* A) {
//  int bal = 0;
//  int dpth = checkbal(A, bal);
//        
//    return bal;    
//}
//
// int find(TreeNode* A, int B, int C)
// {
//    if(!A) return 0;
//    
//    int res = 0;
//     
//    if(A->val == B || A->val == C)
//    {
//        res = 1;
//        
//        if(B == C)
//        {
//            return ++res;
//        }
//        
//        if(A->left)
//            res += find(A->left, B, C);
//        
//        if(A->right)
//            res += find(A->right, B, C);
//    }
//    return res;
// }
// 
//int lca(TreeNode* A, int B, int C) {
//    
//  if(!A) return -1;
//  
//  if(B == C && A->val == B)
//  {
//    return A->val;
//  }
//  
//  int lres = 0, rres = 0;
//  
//  if(A->left) 
//  {
//    lres = find(A->left, B, C);
//    
//    if(lres == 2)
//    {
//        return lca(A->left, B,C);
//    }
//  }
//  
//  if(A->right)
//  {
//    rres = find(A->right, B, C);
//    
//    if(rres == 2)
//    {
//        return lca(A->right, B,C);
//    }  
//  }
//  
//  if(lres == 1 && rres == 1)
//    return A->val;
//  else if(lres == 0 && rres == 0)
//    return -1;
//  else if(A->val == B || A->val == C)
//    return A->val;
//  
//  return -1;
//}
//
//bool isprime(int num)
//{
//	if(num <=1) return false;
//	if(num <=3) return true;
//
//	if(num%2 ==0 || num %3 == 0) return false;
//
//	for(int i = 5; i*i <= num; i+=6)
//	{
//		if(num % i == 0 || num%(i+2) == 0)
//			return false;
//	}
//	return true;
//}
//
//void prmynessutil(string cstr, string& fstr, int indx, vector<string>& svec)
//{
//	string nstr;
//
//	for(int j=indx; j< fstr.size(); j++)
//	{
//		nstr = cstr;
//		nstr += fstr[j];
//		svec.push_back(nstr);
//		prmynessutil(nstr, fstr, j+1, svec);
//	}
//}
//
//int prmyness(string str)
//{
//	int cnt =0;
//
//	vector<string> svec;
//	string cstr("");
//
//	prmynessutil(cstr, str, 0, svec);
//
//	for(int i=0; i<svec.size(); i++)
//	{
//		cout << svec[i] << endl;
//	}
//
//	
//	return cnt;
//}
//
//int main()
//{
//	string s;
//	cin >>s;
//	cout << prmyness(s);
//
//	/*TreeNode* root = new TreeNode(1);
//	root->left = new TreeNode(2);
//	root->right = new TreeNode(3);
//	root->left->left = new TreeNode(4);
//	root->left->right = new TreeNode(5);
//	root->left->right->left = new TreeNode(6);
//
//	cout << lca(root, 5,6);*/
//	//cout << isBalanced(root);
//
////	string A("cool_ice_wifi");
////	vector<string> B; //"cool_wifi_speed", "water_is_cool", "cold_ice_drink"
////	B.push_back("water_is_cool");
////	B.push_back("cold_ice_drink");
////	B.push_back("cool_wifi_speed");
////
////vector<int> ivec;
////
////	ivec = solve(A,B);
////
////	for(int i=0; i < ivec.size(); i++)
////		cout << ivec[i] <<endl;
//
//	//TreeNode* root = new TreeNode(1);
//
//	//root->right = new TreeNode(2);
//	////root->left->right = new TreeNode(4);
//	////root->right = new TreeNode(3);
//
//	//vector<vector<int>> vvec;
//	//
//	//vvec = BTree_verprnt(root);
//
//	//for(int i =0; i < vvec.size(); i++)
//	//{
//	//	for(int j=0; j < vvec[i].size(); j++)
//	//	{
//	//		cout << vvec[i][j] << " ";
//	//	}
//
//	//	cout << endl;
//	//}
//	//
//
//
//
//
//
//	//vector<int> A;
//	//int arr[] = {90, 58, 69, 70, 82, 100, 13, 57, 47, 18};
//
//	//int size = sizeof(arr)/sizeof(arr[0]);
//
//	//for(int i=0; i< size; i++)
//	//{
//	//	A.push_back(arr[i]);
//	//}
//
//	//largestRectangleArea(A);
//
//
//	/*ifstream infile("input.txt");
//	string line;
//	map<string, int> stmap;
//
//	if(infile.is_open())
//	{
//		while(getline(infile,line) && line.size())
//		{
//			string id;
//			int num;
//
//			int frstindx = line.find_first_of(",");
//			int lstindx = line.find_last_of(",");
//
//			if(frstindx == -1 || lstindx == -1)
//				continue;
//
//			id = line.substr(0, frstindx);
//			num = stoi(line.substr(lstindx+2, line.size()-lstindx-2));
//
//			stmap[id] = stmap[id] + num; 
//		
//		}	
//	}
//
//	map<string, int>::iterator mpitr;
//
//	int cnt =0;
//	for(mpitr = stmap.begin(); mpitr != stmap.end(); mpitr++)
//	{
//		if(mpitr->second >=100)
//			cnt++;
//	}
//
//	ofstream outfile("output.txt");
//
//	if(outfile.is_open())
//	{
//		outfile<<cnt;
//	}*/
//
//	return 0;
//}


#include <iostream>
using namespace std;

int gcd(int s, int b)
{
	int j = b % s;

	if(j == 0 )
		return s;

	return gcd(j, s);
}

void rotate(int arr[], int d, int n)
{
	for(int i=0; i < gcd(d,n); i++)
	{
		int temp = arr[i];
		int j = i;
		int k;
		while(1)
		{
			k=j+d;

			if(k >= n)
				k = k-n;

			if(k == i)
				break;

			arr[j] = arr[k];
			j = k;
		}
		arr[j] = temp;
	}
}

void rearrange(int arr[], int size)
{
	int j=0;
	for(int i=0; i < size; i++)
	{
		if(arr[i] < 0)
		{
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
			j++;
		}
	}
}
#include<functional>
#include<algorithm>
//#include<string>

void checkpal()
{
	char arr[] = "geeksfofskeeh";

	int st = 0;
	int en = sizeof(arr)-2;
	int size = en;
	bool fnd=0;

	while(st < size)
	{
		if(arr[st] == arr[en])
		{
			int st2 = st+1;
			int en2 = en-1;

			while(st2 < en2 && arr[st2] == arr[en2])
			{
				st2++;
				en2--;
			}

			if(st2 == en2)
			{
				fnd = 1;
				break;
			}
		}
		en--;

		if(st == en && st < size)
		{
			st++;
			en=size;
		}
	}

	if(fnd)
	{
		cout << st << "\t"<<en<<endl;
	}
}

int max (int x, int y) { return (x > y)? x : y; }
 
// Returns the length of the longest palindromic subsequence in seq
int lps(char *seq, int i, int j)
{
   // Base Case 1: If there is only 1 character
   if (i == j)
     return 1;
 
   // Base Case 2: If there are only 2 characters and both are same
   if (seq[i] == seq[j] && i + 1 == j)
     return 2;
 
   // If the first and last characters match
   if (seq[i] == seq[j])
      return lps (seq, i+1, j-1) + 2;
 
   // If the first and last characters do not match
   return max( lps(seq, i, j-1), lps(seq, i+1, j) );
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int size = sizeof(arr)/sizeof(arr[0]);

	int d = 6;
	char carr[]="geeksforgeeks";
	lps(carr,0,13);
	//checkpal();
	//rotate(arr, d,size);
	
	//rearrange(arr, size);

	//for(int i =0; i< size; i++)
	//	cout << arr[i] <<"  ";

	/*int gmx = arr[0];
	int lmx = arr[0];
	int gst=0, lst=0, gen=0;

	for(int i=0; i < size; i++)
	{
		if(arr[i] > lmx+arr[i])
		{
			lst = i;
		}
		
		lmx = std::max(arr[i], lmx+arr[i]);

		if(gmx < lmx)
		{
			gst = lst;
			gen = i;
		}
		gmx = std::max(gmx, lmx);
	}
	cout<<gmx<<endl;
	cout<<"Starting Index: "<<gst<<"\t Ending index: "<<gen<<endl;
	cout<<"\n\n\n";*/

	//std::sort(arr, arr+size);

	//int arr2[7];
	//for(int i=0; i<size; i++)
	//{
	//	arr2[i] = arr[i]; 
	//}

	//int i = size;
	//if(i % 2 != 0)
	//	--i;

	//for(int j=size-1; i>1; i-=2, j--)
	//{
	//	arr[i-1] = arr2[j];
	//}

	//i=size;
	//if(i % 2 == 0)
	//	--i;

	//for(int j=0; i>=0; i-=2, j++)
	//{
	//	arr[i-1] = arr2[j];
	//}

	//for(int i=0; i<size; i++)
	//{
	//	cout << arr[i] <<"\t";
	//}

	//cout<<"\n\n\n";











}
