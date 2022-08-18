#include<bits/stdc++.h>
using namespace std;

void selectionsort(vector<int> &arr,int n){
    for(int i=0;i<n;i++){
        int iMin = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[iMin]){
                iMin = j;
            }
        }
        swap(arr[iMin],arr[i]);
    }
}

void insertionsort(vector<int> &arr,int n){
    int value,hole;
    for(int i=1;i<n;i++){
        value = arr[i];
        hole = i;
        while(hole > 0 && arr[hole-1]>value){
            arr[hole] = arr[hole-1];
            hole--;
        }
        arr[hole] = value;
    }
}

void bubblesort(vector<int> &arr,int n){
    bool swapped;
    for(int i=0;i<n-1;i++){
        swapped = false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j+1],arr[j]);
                swapped = true;
            }
        }
        if(swapped == false){
            break;
        }
    }
    
}




int partition(vector<int> &arr,int start,int end){
    int pivot = arr[end];
    int partition_index = start;
    
    for(int i=start;i<end;i++){
        if(arr[i]<=pivot){
            swap(arr[i],arr[partition_index]);
            partition_index++;
        }
    }
    swap(arr[partition_index],arr[end]);
    return partition_index;
}
void quicksort(vector<int> &arr,int start,int end){
    if(start<end){
        int pivot = partition(arr,start,end);
        quicksort(arr,start,pivot-1);
        quicksort(arr,pivot+1,end);
    }
}

int main(){
    vector<int> arr = {5,4,3,2,1,55,3453};
    int n = 7;
    // selectionsort(arr,n);
    // insertionsort(arr,n);
    // bubblesort(arr,n);
    quicksort(arr,0,6);
    for(auto i:arr){
        cout<<i<<endl;
    }
}
