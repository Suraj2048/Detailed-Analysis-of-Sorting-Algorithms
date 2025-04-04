#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void merge(char A[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = A[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(char A[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);

        merge(A, left, mid, right);
    }
}

int main() {
    char A[102400];  // Array to store characters
    int n = 0;

    // Read data from the file and insert it into the array
    FILE* file = fopen("Char(100000).txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    while (fscanf(file, " %c", &A[n]) == 1) {
        n++;
    }

    fclose(file);

    clock_t start_time = clock();
    mergeSort(A, 0, n - 1);
    clock_t end_time = clock();

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Print the sorted array of characters
    for (int i = 0; i < n; i++) {
        printf("%c ", A[i]);
    }
    printf("\nSorting took %lf seconds to execute.\n", time_taken);

    return 0;
}
