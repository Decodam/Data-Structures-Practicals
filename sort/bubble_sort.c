#include <stdio.h>
#define MAX 5 

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




int main(){

    int array[MAX] = {2, 9, 4, 3, 6};

    sort(array, MAX);

    printf("Sorted Array: ");
    for (int i = 0; i < MAX; i++)
    {
        printf("%d, ", array[i]);
    }
    

    return 0;
}