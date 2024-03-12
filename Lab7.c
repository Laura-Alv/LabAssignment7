#include <stdio.h>
#include <stdlib.h>

typedef struct element{
  int val;
  int num_swap;
} element;

element* bubbleSort(int arr[], int n) {
    element* swaps= malloc(sizeof(element)*n);
    for(int i=0; i<n; i++){
      swaps[i].val=arr[i];
      swaps[i].num_swap=0;
    }
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (swaps[j].val > swaps[j+1].val) {
                swaps[j].num_swap++;
                swaps[j+1].num_swap++;
                element temp = swaps[j];
                swaps[j] = swaps[j+1];
                swaps[j+1] = temp;
            }
        }
    }
  return swaps;
}

element* selectionSort(int arr[], int n) {
    element* swaps = malloc(sizeof(element) * n);
    for(int i = 0; i < n; i++) {
        swaps[i].val = arr[i];
        swaps[i].num_swap = 0;
    }
    int i, j;
    for (i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (swaps[j].val < swaps[minIndex].val) {
                minIndex = j;
            }
        }
        if (minIndex == i) continue;
        swaps[i].num_swap++;
        swaps[minIndex].num_swap++;
        // Swap values only, not entire elements
        int temp = swaps[i].val;
        swaps[i].val = swaps[minIndex].val;
        swaps[minIndex].val = temp;
    }
    return swaps;
}


int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);
    int count = 0;
    printf("array1 bubble sort:\n");
        element *bubble_sorted_array1 = bubbleSort(array1, n1);
        for (int i = 0; i < n1; i++) {
            printf("%d: %d\n", bubble_sorted_array1[i].val, bubble_sorted_array1[i].num_swap);
          count += bubble_sorted_array1[i].num_swap;
        }
        printf("%d\n\n", count/2);
        count = 0;
        free(bubble_sorted_array1);

        // Bubble sort for array2
        printf("\narray2 bubble sort:\n");
        element *bubble_sorted_array2 = bubbleSort(array2, n2);
        for (int i = 0; i < n2; i++) {
            printf("%d: %d\n", bubble_sorted_array2[i].val, bubble_sorted_array2[i].num_swap);
          count += bubble_sorted_array2[i].num_swap;
        }
        printf("%d\n\n", count/2);
        count = 0;
        free(bubble_sorted_array2);

        // Selection sort for array1
        printf("\narray1 selection sort:\n");
        element *selection_sorted_array1 = selectionSort(array1, n1);
        for (int i = 0; i < n1; i++) {
            printf("%d: %d\n", selection_sorted_array1[i].val, selection_sorted_array1[i].num_swap);
          count += selection_sorted_array1[i].num_swap;
        }
        printf("%d\n\n", count/2);
        count = 0;
        free(selection_sorted_array1);

        // Selection sort for array2
        printf("\narray2 selection sort:\n");
        element *selection_sorted_array2 = selectionSort(array2, n2);
        for (int i = 0; i < n2; i++) {
            printf("%d: %d\n", selection_sorted_array2[i].val, selection_sorted_array2[i].num_swap);
          count += selection_sorted_array2[i].num_swap;
        }
        printf("%d\n\n", count/2);
        count = 0;
        free(selection_sorted_array2);

        return 0;
    }