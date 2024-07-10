#include <stdio.h>


void main() {
  int res, proc;

  printf("Enter number of resource types:\t");
  scanf("%d", &res);
  printf("Enter number of processes:\t");
  scanf("%d", &proc);
  
  int alloc[proc][res], max[proc][res], need[proc][res], avail[res], work[res], safe[proc], finish[proc];
  int index = 0, flag;

  printf("Allocation matrix\n");
  for (int i = 0; i < proc; i++) {
    for (int j = 0; j < res; j++) {
      printf("Process:\t%d\nResource %d instances:\t", i + 1, j + 1);
      scanf("%d", &alloc[i][j]);
    }
  }
  
  printf("Maximum allocation matrix\n");
  for (int i = 0; i < proc; i++) {
    for (int j = 0; j < res; j++) {
      printf("Process:\t%d\nResource %d instances:\t", i + 1, j + 1);
      scanf("%d", &max[i][j]);
    }
  }

  printf("Availability matrix\n");
  for (int j = 0; j < res; j++) {
    printf("Resource %d instances:\t", j + 1);
    scanf("%d", &avail[j]);
    work[j] = avail[j];
  }

  // Need matrix
  for (int i = 0; i < proc; i++) {
    for (int j = 0; j < res; j++) {
      need[i][j] = max[i][j] - alloc[i][j];
    }
  }

  // Init finish arr
  for (int i = 0; i < proc; i++) {
    finish[i] = 0;
  }

  // Safe sequence
  for (int i = 0; i < proc; i++) {
    for (int j = 0; j < proc; j++) {
      if (finish[j] == 0) {
        flag = 0;
        for (int k = 0; k < res; k++) {
          if (need[j][k] > work[k]) {
            flag = 1;
            break;
          }
        }

        if (flag == 0) {
          safe[index++] = j;
          for (int x = 0; x < res; x++) {
            work[x] += alloc[j][x];
          }
          finish[j] = 1;
        }
      }
    }
  }

  // Check if done
  flag = 1;
  for (int i = 0; i < proc; i++) {
    if (finish[i] == 0) {
      flag = 0;
      break;
    }
  }

  if (flag == 0) {
    printf("No safe sequence found.\n");
  } else {
    printf("Safe sequence found:\t");
    for (int i = 0; i < proc; i++) {
      printf("%d", safe[i]);
      if (i != proc - 1) {
        printf(" -> ");
      } else {
        printf(".\n");
      }
    }
  }
}
