//void swap(int& x, int& y)
//{
//	x = x+y;
//	y = x-y;
//	x = x-y;
//}
//
//
//void max_heap(int arr[], int st_ind, int lst_ind)
//{
//	if(lst_ind > ((2*st_ind)+1))
//	{
//		//int tmp;
//		max_heap(arr, ((2*st_ind)+1), lst_ind);
//		max_heap(arr, ((2*st_ind)+2), lst_ind);
//
//		if(arr[st_ind] < arr[((2*st_ind)+1)])
//		{
//			swap(arr[st_ind] , arr[((2*st_ind)+1)]);
//		}
//
//		if(arr[st_ind] < arr[((2*st_ind)+2)])
//		{
//			swap(arr[st_ind] , arr[((2*st_ind)+2)]);
//		}
//	}
//}
//
//void heap_sort(int arr[], int size)
//{
//
//	int lst_ind = size-1, tmp;
//
//	while(lst_ind > 0)
//	{
//		max_heap(arr, 0, lst_ind);
//
//		tmp = arr[0];
//		arr[0] = arr[lst_ind];
//		arr[lst_ind] = tmp;
//		lst_ind--;
//	}
//}
//
//// To heapify a subtree rooted with node i which is
//// an index in arr[]. n is size of heap
//void heapify(int arr[], int n, int i)
//{
//    int largest = i;  // Initialize largest as root
//    int l = 2*i + 1;  // left = 2*i + 1
//    int r = 2*i + 2;  // right = 2*i + 2
// 
//    // If left child is larger than root
//    if (l < n && arr[l] > arr[largest])
//        largest = l;
// 
//    // If right child is larger than largest so far
//    if (r < n && arr[r] > arr[largest])
//        largest = r;
// 
//    // If largest is not root
//    if (largest != i)
//    {
//        swap(arr[i], arr[largest]);
// 
//        // Recursively heapify the affected sub-tree
//        heapify(arr, n, largest);
//    }
//}
// 
//// main function to do heap sort
//void heapSort(int arr[], int n)
//{
//    // One by one extract an element from heap
//    for (int i=n-1; i>0; i--)
//    { 
//        // call max heapify on the reduced heap
//        heapify(arr, i, 0);
//
//		swap(arr[0], arr[i]);
//    }
//}
//
