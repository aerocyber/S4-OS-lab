#include <stdio.h>

void main() {
  int n, f, first = 0, fault = 0;
  printf("Enter number of pages:\t");
  scanf("%d", &n);
  printf("Enter number of frames:\t");
  scanf("%d", &f);
  int frames[f], ref[n];
  printf("Enter reference string:\t");
  for (int i = 0; i < n; i++) {
    scanf("%d", &ref[i]);
  }
  for (int i = 0; i < f; i++) {
    frames[i] = -1;
  }

  printf("\nReference String |   Frames\t\t  |\tStatus\n");
  for (int i = 0; i < n; i++) {
    int fnd = 0;
    printf("\t%d\t\t", ref[i]);

    for (int j = 0; j < f; j++) {
      if (frames[j] == ref[i]) {
        fnd = 1;
        break;
      }
    }

    if (!fnd) {
      frames[first] = ref[i];
      first = (first + 1) % f;
      fault++;
    }

    for (int j = 0; j < f; j++) {
      if (frames[j] != -1) {
        printf("%d\t", frames[j]);
      } else {
        printf("-\t");
      }
    }

    if (fnd) {
      printf("HIT\n");
    } else {
      printf("MISS\n");
    }
    
  }
}
