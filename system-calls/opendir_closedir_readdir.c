#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void main()
{
  struct dirent * dptr;
  DIR *dirp = opendir(".");
  if (dirp == NULL)
  {
    printf("Error\n");
    exit(1);
  }
  else
  {
    while((dptr = readdir(dirp)) != NULL)
    {
      printf("%s\n", dptr->d_name);
    }
    closedir(dirp);
  }
}
