#include<iostream>
#include<vector>
using namespace std;

//to return the partition's index after arranging the elements accordingly 
int pindx(vector<int> &arr, int l, int h){
    int i=l;
    int j=h;
    int pivot=arr[l];

    while(i<j){
        while(i<=h-1 && arr[i]<=pivot) i++; // this part might cause seg falut ciz this one update the value which might end up in unwanted location 
        while(j>=l+1 & arr[j]>pivot) j--;

        if(i<j)
        swap(arr[i],arr[j]);
    }
    swap(arr[j],arr[l]);

    return j;
}

void quicksort(vector<int> &arr, int l, int h){
    if(l<h){
        int partition=pindx(arr,l,h);
        quicksort(arr, l, partition-1);
        quicksort(arr, partition+1, h);
    }
    else 
        return;
}

void print(vector<int> &arr, int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
int main(){
    vector<int> arr;
    arr={4,6,2,5,7,9,1,3};
    quicksort(arr,0,8-1);
    print(arr,8);
}
/*
The crucial part is to find the partition index at which the pivot elemet is set at which we partition the array and recursicvely call the quick sort function !
*/
/*The quicksort algo works by partitioning the array just as the merge sort but ineasted to taking extra space we are able to do it in a constant space , the only space needed is the recursion call stack*/