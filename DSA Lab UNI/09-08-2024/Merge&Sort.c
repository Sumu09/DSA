#include <stdio.h>

int main() {
  int n1, n2, i, j;

  printf("Enter the size of the first array: ");
  scanf("%d", &n1);
  int arr1[n1];
  printf("Enter the elements of the first array:\n");
  for (i = 0; i < n1; i++)
    scanf("%d", &arr1[i]);

  printf("Enter the size of the second array: ");
  scanf("%d", &n2);
  int arr2[n2];
  printf("Enter the elements of the second array:\n");
  for (i = 0; i < n2; i++)
    scanf("%d", &arr2[i]);

  int merged[n1 + n2];
  for (i = 0; i < n1; i++)
    merged[i] = arr1[i];
  for (i = 0; i < n2; i++)
    merged[n1 + i] = arr2[i];

  // sort korar process
  for (i = 0; i < n1 + n2 - 1; i++) {
    for (j = i + 1; j < n1 + n2; j++) {
      if (merged[i] > merged[j]) {
        int temp = merged[i];
        merged[i] = merged[j];
        merged[j] = temp;
      }
    }
  }

  printf("Sorted merged array:\n");
  for (i = 0; i < n1 + n2; i++)
    printf("%d ", merged[i]);
  printf("\n");

  return 0;
}

