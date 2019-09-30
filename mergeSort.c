#include<stdio.h>

void mergeSort(int*, int, int);
void merge(int*, int, int, int);
void display(int*,int);

int main(){
    int a[10]={1,3,5,7,9,3,7,0,1}, n=9;

    mergeSort(a,0,n-1);
    display(a,n);

    return 0;
}

void mergeSort(int a[], int p, int r){
    int q;

    if(p<r){
        q = (p+r)/2;
        mergeSort(a,p,q);
        mergeSort(a,q+1,r);
        merge(a,p,q,r);
    }
}

void merge(int a[], int p, int q, int r){
    int b[10],l1,r1,i;
    l1=p;
    r1=q+1;
    i=p;

    while(l1<=q && r1<=r){
        if(a[l1]<=a[r1])
            b[i++]=a[l1++];
        else
            b[i++]=a[r1++];
    }

    while(l1<=q)
        b[i++]=a[l1++];

    while(r1<=r)
        b[i++]=a[r1++];

    for(i=p; i<=r; i++)
        a[i]=b[i];
}

void display(int a[], int n){
    for(int i=0; i<n; i++)
        printf("%d ",a[i]);
}


