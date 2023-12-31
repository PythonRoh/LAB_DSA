#include <stdio.h>
#include <stdlib.h>

void merge(int left[], int right[], int lsize, int rsize, int merged[]) {
    int i = 0, j = 0, k = 0;
    while (i < lsize && j < rsize) {
        if (left[i] <= right[j]) {
            merged[k++] = left[i++];
        } else {
            merged[k++] = right[j++];
        }
    }
    while (i < lsize)
        merged[k++] = left[i++];
    while (j < rsize)
        merged[k++] = right[j++];
}

void mergesort(int arr[], int s, int e) {
    if (s < e) {
        int mid = (s + e) / 2;

        mergesort(arr, s, mid);
        mergesort(arr, mid + 1, e);

        int lsize = mid - s + 1;
        int rsize = e - mid;

        int *left = malloc(lsize * sizeof(int));
        int *right = malloc(rsize * sizeof(int));

        for (int i = 0; i < lsize; i++)
            left[i] = arr[s + i];
        for (int i = 0; i < rsize; i++)
            right[i] = arr[mid + 1 + i];

        int merged[lsize + rsize];

        merge(left, right, lsize, rsize, merged);

        for (int i = 0; i < lsize + rsize; i++)
            arr[s + i] = merged[i];

        free(left);
        free(right);
    }
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergesort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}