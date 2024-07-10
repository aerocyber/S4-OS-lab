#include <stdio.h>
#include <sys/stat.h>

void main()
{
  struct stat sfile;
  stat("./hello.txt", &sfile);
  printf("st_mode=%o\n", sfile.st_mode);
  printf("UID=%d\n", sfile.st_uid);
  printf("Size=%d\n", sfile.st_size);
}
