#include<stdio.h>

int Bsearch(int arr[], int key, int size){
    int lo=0;
    int h=size-1;
    int mid=(h+lo)/2;

    while(h>lo && key!=arr[mid]){
            mid=(lo+h)/2;
        if(key>arr[mid]){
            lo=mid+1;
        }else if(key<arr[mid]){
            h=mid-1;
        }
    }
    if(h>=lo && key==arr[mid]){
        return 1;
    }

    if(h<lo){
        return 0;
    }
}

int main(){
    int m;
    printf("Write size of arr");
    scanf("%d", &m);
    int arr[100];
    for(int j=0; j<m; j++){
        scanf("%d", &arr[j]);
    }
    int key;
    printf("Write key to find");
    scanf("%d", &key);

    int val=Bsearch(&arr,key,6);
    if(val==1){
        printf("key found");
    }else{
        printf("key not found");
    }

}

