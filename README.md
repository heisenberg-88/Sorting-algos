# :european_castle: Sorting-algos :european_castle:
All sorting algos



---------------------------------------------------------------------------------------------------------------------------------------------------------------------------



## :radioactive: Selection sort algorithm ------------------------- ( Big O: best/worst = O(N²) )
![1_OA7a3OGWmGMRJQmwkGIwAw](https://user-images.githubusercontent.com/75937169/136012320-45321c8d-9049-47c4-8770-72a00522d768.gif)

```cpp

#include<bits/stdc++.h>
using namespace std;

void selectionSort(int A[],int n){

    for(int i=0;i<n-1;i++){
        int iMin = i;   //ith position: elements from i to n-1 are candidates

        for(int j=i+1;j<n;j++){
            if(A[j]<A[iMin]){
                iMin=j;  // updating the index of minimum element
            }
        }
        swap(A[i],A[iMin]);
    }
}

int main(){
    int A[] = {2,6,3,8,1,0,1};
    selectionSort(A,7);

    for(auto i:A){
        cout<<i<<" ";       // 0 1 1 2 3 6 8
    }

}



```


---------------------------------------------------------------------------------------------------------------------------------------------------------------------------





## :radioactive: Bubble sort algorithm ------------------------- ( Big O: best = O(N), worst = O(N²) )



https://user-images.githubusercontent.com/75937169/190440350-6841ab6a-bed8-430e-bb85-6da780e4958d.mp4




```cpp

#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int A[],int n){
    int i,j;
    bool swapped ;
    
    for(i=0;i<n-1;i++){
        swapped = false;
        for(j=0;j<n-i-1;j++){

            if(A[j]>A[j+1]){
                swap( A[j] , A[j+1] );  //swap if next element is smaller than current
                swapped = true;  
            }
        }

        if(swapped = false){
            /// if there were no swaps in last iteration , then the array is already sorted
            break;
        }
    }

}

int main(){
    int A[] = {2,6,3,8,1,0,1};
    bubbleSort(A,7);

    for(auto i:A){
        cout<<i<<" ";       // 0 1 1 2 3 6 8
    }

}

```


---------------------------------------------------------------------------------------------------------------------------------------------------------------------------




## :radioactive: Insertion sort algorithm ------------------------- ( Big O: best = O(N), worst = O(N²) )



https://user-images.githubusercontent.com/75937169/190439703-22aa0eaf-015b-4cc6-bd34-3e63a26004f0.mp4




```cpp

#include<bits/stdc++.h>
using namespace std;

void insertionSort(int A[],int n){
    int value, hole;

    //starting from i=1 because , 1st single element is already sorted
    for(int i=1;i<n;i++){
        value = A[i];  // put current number in value
        hole = i;      // make a hole at current position

        while(hole>0 && A[hole-1]>value){
            // this loop moves the bigger elements to the right side
            A[hole]=A[hole-1];
            hole--;
        }

        // now all bigger elements are moved to right side
        // so put the value in current hole

        A[hole] = value;
    }

}

int main(){
    int A[] = {2,6,3,8,1,0,1};
    insertionSort (A,7);

    for(auto i:A){
        cout<<i<<" ";       // 0 1 1 2 3 6 8
    }

}

```


---------------------------------------------------------------------------------------------------------------------------------------------------------------------------




## :radioactive: Merge sort algorithm ------------------------- ( Big O: O(N log N) )

![Merge-sort-example-300px](https://user-images.githubusercontent.com/75937169/136034590-43c6acca-b073-4b06-b438-2931ab2b8578.gif)

```cpp

#include<bits/stdc++.h>
using namespace std;


void merge(int A[],int l,int m,int r){

    // size of two aray to merge
    int n1 = m-l+1;
    int n2 = r-m;


    // make left & right arrays
    int larr[n1] , rarr[n2];
    for(int i=0;i<n1;i++){
        larr[i] = A[l+i];
    }
    for(int j=0;j<n2;j++){
        rarr[j] = A[m+1+j];
    }

    int i=0;
    int j=0;
    int k=l;

    // NOW MERGING STARTS
    while(i<n1 && j<n2){
        if(larr[i]<=rarr[j]){
            A[k] = larr[i];            // if larr[] element is smaller
            i++;
        }else{
            A[k] = rarr[j];            // if rarr[] element is smaller
            j++;
        }
        k++;
    }
    while(i<n1){
        A[k] = larr[i];             // extra elements left in larr[]
        i++;
        k++;
    }
    while(j<n2){
        A[k] = rarr[j];             // extra elements left in rarr[]
        j++;
        k++;
    }

}

void mergeSort(int A[],int l,int r){
    if(r>l){
        int m = l+ (r-l)/2;

        mergeSort(A,l,m);
        mergeSort(A,m+1,r);
        
        merge(A,l,m,r);
    }
    
}

int main(){
    int A[] = {2,6,3,8,1,0,1};

    mergeSort(A,0,6);

    for(auto ele:A){
        cout<<ele<<" "; 
    }

}

```


---------------------------------------------------------------------------------------------------------------------------------------------------------------------------




## :radioactive: Quicksort algorithm ------------------------- ( Big O: best = O(N log N), worst O(N²) )

![1_hk2TL8m8Kn1TVvewAbAclQ](https://user-images.githubusercontent.com/75937169/136071169-e9a0200b-3b6e-4b1f-bd64-8a9988f35c69.gif)



```cpp

#include<bits/stdc++.h>
using namespace std;

// to get a point where all elements to LEFT are smaller than pivot & elements to RIGHT are larger
int Partition(int * A, int start, int end){
    int pivot = A[end];
    int partition_index = start;  // start partition index as start

    for(int i=start;i<end;i++){
        if(A[i]<=pivot){
            swap(A[i],A[partition_index]);    // put all elements less than A[partition_index] to the left of it
            partition_index++;                // increment partition_index
        }
    }

    swap(A[partition_index] ,A[end]);  // swap pivot with partition_index
    return partition_index;
}




void quickSort(int *A ,int start, int end){
    if(start < end){
        int partition_index = Partition(A,start,end);

        quickSort(A,start,partition_index-1);
        quickSort(A,partition_index+1,end);
    }
}



int main(){
    int A[] = {8,7,6,5,4,3,2,1,0};

    quickSort(A,0,8);

    for(auto ele:A){
        cout<<ele<<" ";
    }
}

```


. <br />
. <br />
. <br />
. <br />
. <br />


## :radioactive: Heapsort algorithm
```cpp
// C++ program for implementation of Heap Sort

#include <iostream>
using namespace std;

// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int arr[], int N, int i)
{

	// Initialize largest as root
	int largest = i;

	// left = 2*i + 1
	int l = 2 * i + 1;

	// right = 2*i + 2
	int r = 2 * i + 2;

	// If left child is larger than root
	if (l < N && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest
	// so far
	if (r < N && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected
		// sub-tree
		heapify(arr, N, largest);
	}
}


// Main function to do heap sort
void heapSort(int arr[], int N)
{

	// Build heap (rearrange array)
	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);

	// One by one extract an element
	// from heap
	for (int i = N - 1; i > 0; i--) {

		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

// A utility function to print array of size n
void printArray(int arr[], int N)
{
	for (int i = 0; i < N; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

// Driver's code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	heapSort(arr, N);

	cout << "Sorted array is \n";
	printArray(arr, N);
}

```



. <br />
. <br />
. <br />
. <br />
. <br />
. <br />
. <br />
. <br />
. <br />
. <br />
. <br />
. <br />
. <br />
. <br />
. <br />
. <br />
. <br />
. <br />
. <br />

. <br />
. <br />

*** EXTRAS ***


```cpp
#include<bits/stdc++.h>
using namespace std;

void selectsort(vector<int> &v,int n){

	for(int i=0;i<n-1;i++){
		int imin = i;

		for(int j=i+1;j<n;j++){
			if(v[j]<v[i]){
				imin = j;
			}
		}
		swap(v[imin],v[i]);
	}
}

void insertsort(vector<int> &v,int n){
	int value,hole;

	for(int i=1;i<n;i++){
		value = v[i];
		hole = i;

		while(hole>0 && v[hole-1]>value){
			v[hole] = v[hole-1];
			hole--;
		}
		v[hole] = value;
	}
}

void merge(vector<int>& v, int l, int r, int m){
	int n1 = m-l+1;
	int n2 = r-m;

	int left[n1];
	int right[n2];

	for(int i=0;i<n1;i++){
		left[i] = v[i+l];
	}
	for(int j=0;j<n2;j++){
		right[j] = v[m+j+1];
	}

	int i = 0;
	int j = 0;
	int k = l;
	
	//merging starts
	while(i<n1 && j<n2){
		if(left[i]<=right[j]){
			v[k] = left[i];
			i++;
			k++;
		}
		else{
			v[k] = right[j];
			j++;
			k++;
		}
	}

	while(i<n1){
		v[k] = left[i];
		i++;
		k++;
	}
	while(j<n2){
		v[k] = right[j];
		j++;
		k++;
	}

}
void mergesort(vector<int>&v, int l, int r){
	if(l<r){
		int mid = l+ (r-l)/2;

		mergesort(v,l,mid);
		mergesort(v,mid+1,r);

		merge(v,l,r,mid);
	}
}

int main(){
	vector<int> v = {9,8,7,6,5,4,3,21};
	int n = 8;
	// selectsort(v,n);
	// insertsort(v,n);
	mergesort(v,0,n-1);
	for(auto i:v){
		cout<<i<<endl;
	}
}

```
