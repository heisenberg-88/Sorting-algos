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
