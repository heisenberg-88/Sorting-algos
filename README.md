# Sorting-algos
All sorting algos

## Selection sort algorithm ------------------------- ( Big O: best/worst = O(N²) )
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





## Bubble sort algorithm ------------------------- ( Big O: best = O(N), worst = O(N²) )

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




## Insertion sort algorithm ------------------------- ( Big O: best = O(N), worst = O(N²) )

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
