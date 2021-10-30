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

![1_LllBj5cbV91URiuzAB-xzw](https://user-images.githubusercontent.com/75937169/136015389-1bedac01-0dd7-4e4d-819a-45dd775f9ba8.gif)


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

![1_onU9OmVftR5WeoLWh14iZw](https://user-images.githubusercontent.com/75937169/136017639-559ff09d-620d-4d46-a851-a2a4cdde5abc.gif)


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

