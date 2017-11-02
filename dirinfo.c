#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>

int main(){
	DIR * current_directory = opendir(".");
	struct dirent * dir = readdir(current_directory);
	do{
		printf("%s:%d\n",dir->d_name,dir->d_type);
		dir = readdir(current_directory);
	}while(dir);
	closedir(current_directory);
}
