#include <stdio.h>

int main() {
  // Declaring the size of arrays
  int s1, s2, s3;
  printf("\n Enter the size of 1st array  ");
  scanf("%d", &s1);
  printf("\n Enter the size of 2nd array ");
  scanf("%d", &s2);

  s3 = s1 + s2;
  printf("\n Enter the elements of 1st array\n");
  
  // Declaring the arrays
  int arr1[s1], arr2[s2], arr3[s3];

  // Initializing the 1st array
  for (int i = 0; i < s1; i++) {
    scanf("%d", &arr1[i]);
    arr3[i] = arr1[i]; // Copy elements of arr1 to arr3
  }

  int k = s1; // Start merging at position s1

  printf("\nEnter the elements of 2nd array \n");
  
  // Initializing the 2nd array and merging with arr3
  for (int i = 0; i < s2; i++) {
    scanf("%d", &arr2[i]);
    arr3[k] = arr2[i]; // Corrected: Copy elements of arr2 to arr3
    k++;
  }

  printf("\nThe merged array before sorting: \n\t");
  for (int i = 0; i < s3; i++)
    printf("%d ", arr3[i]); // Print the merged array before sorting

  // Sorting the merged array using bubble sort
  for (int i = 0; i < s3; i++) {
    for (int j = i + 1; j < s3; j++) {
      if (arr3[i] > arr3[j]) {
        int temp = arr3[i];
        arr3[i] = arr3[j];
        arr3[j] = temp;
      }
    }
  }

  // Printing the sorted merged array
  printf("\n\nThe merged array after sorting: \n\t");
  for (int i = 0; i < s3; i++) {
    printf("%d ", arr3[i]);
  }

  return 0;
}
