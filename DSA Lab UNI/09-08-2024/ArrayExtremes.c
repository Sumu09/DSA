#include <stdio.h>

int main() {
    int n, i, max, min, maxPos, minPos;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    max = min = arr[0];
    maxPos = minPos = 0;

    for(i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
            maxPos = i;
        }
        if(arr[i] < min) {
            min = arr[i];
            minPos = i;
        }
    }

    printf("Max value: %d at position %d\n", max, maxPos + 1);
    printf("Min value: %d at position %d\n", min, minPos + 1);

    return 0;
}