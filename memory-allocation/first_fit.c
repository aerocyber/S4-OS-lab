#include <stdio.h>

void main() {
  int m, n;
  printf("Enter number of process:\t");
  scanf("%d", &n);
  printf("Enter number of blocks:\t");
  scanf("%d", &m);

  int memory[m];
  int process[n];

  printf("Enter memory block sizes\n\n");
  for (int i = 0; i < m; i++) {
    scanf("%d", &memory[i]);
  }

  printf("Enter process sizes\n\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &process[i]);
  }

  int allocation[n];
  for (int i = 0; i < n; i++) {
    allocation[i] = -1;
  }

  for(int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (memory[j] > process[i]) {
        allocation[i]= j;
        memory[j] -= process[i];
        break;
      }
    }
  }

  printf("\n\nPID\tSize\tBlock no\n");
  for (int i = 0; i < n; i++) {
    printf("%d\t%d\t", i + 1, process[i]);
    if (allocation[i] == -1) {
      printf("Not allocated\n");
    } else {
      printf("%d\n", allocation[i] + 1);
    }
  }
}
