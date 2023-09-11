#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

void bubble_sort(int arr[], int n)[

    for(int j = 0; j < n-2; j++){

        if(arr[j] > arr[j+1]){
            temp = arr[1];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
]