#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 2000000

int main() {
  // declaring a string for the input
  char input[MAX];

  // count is 8 because we are taking the initial value of the vector as 8
  // i is the counter
  int count = 8, i = 0;

  // here we are allocating the array for the first time
  int *arr = (int *)malloc(count * sizeof(int));
  if (arr == NULL) {
    printf("Memory allocation failed.\n");
    return 1; // will return 1 if the allocation fails
  }
  while (true) {
    scanf("%s", input);     // reading the input
    int temp = atoi(input); // converting the string to int
    if (temp == 0)
      break;
    /*if the string doesnt contain any integer characters then it will return 0,
    and as a result, this while loop will be halted. */
    else {
      if (i < count)
        arr[i++] = temp;
      /*if the counter is less than the set limit of the vector then we will
      insert the element and increase the counter*/

      else if (i == count) {
        /*there would be a situation where the counter will be equal to our
        limit, meaning we cannot store more elements to the vector, and we need
        to double the size of the vector*/

        count *= 2;
        arr = realloc(arr, count * sizeof(int));
        if (arr == NULL) {
          printf("Memory allocation failed.\n");
          return 1;
        }

        /*inserting the element and increasing the counter*/
        arr[i++] = temp;
      }
    }
  }
  // printing the elements
  printf("Do you want to print the elements?: \n1. Yes\n2. No\n");
  int y;
  scanf("%d", &y);
  if (y == 1) {
    for (int j = 0; j < i; j++) {
      printf("%d, ", arr[j]);
    }
  }
  free(arr); // calling the deallocator
  return 0;
}