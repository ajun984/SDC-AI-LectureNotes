#include "how_to_make_file.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>



int file_open(char *filename, int option, unsigned int permission)
{
    int file_descriptor = open(filename, option, permission);

    if (file_descriptor == ERROR)
    {
        printf("open() System Call error!\n");
        return ERROR;
    }

    return file_descriptor;
}

int create_file_descriptor(char* txt_name)
    {
        char address_txt[1024] = {0};
        snprintf(address_txt, sizeof(address_txt), "/home/eddi/proj/SDC-AI-LectureNotes/c/junyeonkim/hun_test/create_file/%s", txt_name);
        int file_descriptor = file_open(address_txt,  O_CREAT | O_RDWR | O_TRUNC, 0644);
        
        return file_descriptor;
    }

void file_close(int file_descriptor)
{
    close(file_descriptor);
}