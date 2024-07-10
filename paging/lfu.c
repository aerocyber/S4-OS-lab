#include <stdio.h>

struct frame {
  int page;
  int freq;
};

void main() {
  int n, f;
  printf("Enter number of frames:\t");
  scanf("%d", &f);
  printf("Enter number of pages:\t");
  scanf("%d", &n);

  int pages[n];
  struct frame frames[f];

  printf("Enter pages:\t");
  for (int i = 0; i < n; i++) {
    scanf("%d", &pages[i]);
  }

  for (int i = 0; i < n; i++) {
    int pgin = 0;
    for (int j = 0; j < f; j++) {
      if (pages[i] == frames[i].page) {
        pgin = 1;
        break;
      }
    }

    if (pg == 1) {} else {
      
    }
  }
}
