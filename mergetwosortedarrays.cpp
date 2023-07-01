// A logic to merger two sorted arrays which is required in the merge sort algorithim
#include <iostream>
using namespace std;
void merger(int one[], int two[], int o, int t, int ans[]){
    int i=0; int j=0; int k=0;
    
    while(i<o && j<t){
        if(one[i]<two[j]){
            ans[k]=one[i];
            i++;k++;
        }
        else{
            ans[k]=two[j];
            j++;k++;
        }
    }
    while(i<o){
        ans[k]=one[i];
        i++;k++;
    }
    while(j<t){
        ans[k]=two[j];
        j++;k++;
    }
}

int main() {
    int one[6]={1,3,4,6,7,8};
    int two[4]={2,5,6,7};
    int ans[10];
    
    merger( one,two, 6, 4, ans);
    
    for(int i=0;i<10;i++)
        cout<<ans[i]<<" ";
}