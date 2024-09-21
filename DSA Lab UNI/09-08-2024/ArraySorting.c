#include <stdio.h>
// use function
int main() {
  int n = 0;
  printf("Enter the size of the array:");
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) {
    printf("Enter the %d value of the array:", i);
    scanf("%d", &a[i]);
  }
  printf("the unreversed array is:\n");
  for (int i = 0; i < n; i++) {
    printf("%d", a[i]);
  }
  printf("the reversed array is:");
  for (int i = n - 1; i >= 0; i--) {
    printf("%d", a[i]);
  }
  return 0;
}
