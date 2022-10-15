#include <dirent.h>
#include <stdio.h>

int main() {

  DIR *dir = opendir(".");

  if (dir == NULL) {
    printf("Couldn't load directory");
    return 1;
  }

  struct dirent *dirent;

  while ((dirent = readdir(dir)) != NULL)
    printf("%s\n", dirent->d_name);

  closedir(dir);

  return 0;
}