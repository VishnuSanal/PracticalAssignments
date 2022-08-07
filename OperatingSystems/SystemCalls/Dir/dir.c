#include<stdio.h>
#include<dirent.h>

void main() {
	
	DIR *dir = opendir (".");
	
	if (dir == NULL) {
		printf("Couldn't load directory");
		return;
	}
	
	struct dirent *dirent;
	
	while((dirent = readdir(dir)) != NULL)
		printf("%s\n", dirent->d_name);
		
	closedir(dir);		

}
