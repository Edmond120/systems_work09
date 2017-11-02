#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>

int main(){
	DIR * current_directory = opendir(".");
	struct dirent * dir = readdir(current_directory);
	long total_size = 0;
	struct stat buffer;
	do{
		printf("%d\n",dir->d_type);
		printf("%s   :   ",dir->d_name);
		if(dir->d_type == DT_REG){
			stat(dir->d_name,&buffer);
			printf("regular file of size: %ld bytes\n",buffer.st_size);
			total_size += buffer.st_size;
		}
		else if (dir->d_type == DT_DIR){
			printf("directory\n");
		}
		else{
			printf("not a directory or regular file\n");
		}
		dir = readdir(current_directory);
	}while(dir);
	printf("total size of regular files: %ld bytes\n",total_size);
	closedir(current_directory);

}
