#include <stdio.h>
#define MAX 7


void sort(int arr[], int n){
    int temp;


    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
    }
    
}

int binarySearch(int arr[], int n, int query){
    int l = 0, h = n-1, result;

    while (l<=h)
    {
        int mid = (l+h)/2;

        if (arr[mid] == query) {
            return mid;
        } else if (query < arr[mid]) {
            h = mid-1;
        } else {
            l = mid+1;
        }
    }
    
    return -1;
}


int main(){
    int query;
    int arr[MAX];


    printf("Enter the elements in the array - \n");
    for (int i = 0; i < MAX; i++)
    {
        printf("Element %d:  ", i); scanf("%d", &arr[i]);
    }
    
    sort(arr, MAX);

    printf("The Sorted array is as follows - \n");
    for (int i = 0; i < MAX; i++)
    {
        printf("%d, ", arr[i]);
    }

    printf("Enter number we are searching for:    "); scanf("%d", &query);
    int result = binarySearch(arr, MAX, query);

    if (result == -1){
        printf("Result not found in the array");
    } else {
        printf("Found in index:    %d", result);
    }
    

    return 0;
}