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
    int worst = -1;
    for (int j = 0; j < m; j++) {
      if (memory[j] > process[i]) {
        if (worst == -1) {
          worst = j;
        } else if (memory[worst] < memory[j]) {
          worst = j;
        }
      }
    }
    if (worst != -1) {
      allocation[i] = worst;
      memory[worst] -= process[i];
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
