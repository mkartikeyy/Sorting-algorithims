// Merge sort is an Recursive algorithim which divides the provided into a single unit and recombines it in a sorted fashion.
/*
              36  42  12  23
                    / \
             36  42     12  23
             /   \       /   \
           36    42     12    23 
*/

#include <iostream>
#include <vector>
using namespace std;

//a helper function which merges the two sorted arrays it gets
void merge(int *arr , int s, int mid, int e){
    vector<int> v;
    int i=s;
    int j=mid+1;
    int k=0;

    while(i<=mid && j<=e){
        if(arr[i]<arr[j])
            v.push_back(arr[i++]);
        else
            v.push_back(arr[j++]);
    }
    while(i<=mid)
        v.push_back(arr[i++]);
    while(j<=e)
        v.push_back(arr[j++]);

    //copying elements to original 
    for(int i=s;i<=e;i++){
        arr[i]=v[i-s];
    }
}

void mergeSort(int *arr,int  s, int e){
    //if the value for the n gets 0 or 1 we assume that its sorted
    if(s>=e)
        return;

    int middle=s+(e-s)/2;

    mergeSort(arr, s, middle);//call for left part
    mergeSort(arr, middle+1, e);//call for right part 
    merge(arr, s, middle, e);
}

void print(int *arr,int n){
    for (int i = 0; i <7; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]={38,27,43,3,9,82,10};
    mergeSort(arr,0,7);
    print(arr,7);
    
}