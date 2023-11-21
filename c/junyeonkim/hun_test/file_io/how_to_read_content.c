#include "how_to_read_content.h"
#include "how_to_make_file.h"

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUDDY_PAGE_SIZE         (1)

void read_content_from_file_and_print(int file_descriptor, char *read_content)
{
    int read_bytes;

    while ((read_bytes = read(file_descriptor, read_content, BUDDY_PAGE_SIZE)) > 0)
    {
        write(1, read_content, read_bytes);
    }
    printf("\n");
}

void read_content_from_file(int file_descriptor, char *read_content)
{
    read(file_descriptor, read_content, 4096);
}

int read_file_descriptor(char* txt_name)
    {
        char address_txt[1024] = {0};
        snprintf(address_txt, sizeof(address_txt), "/home/eddi/proj/SDC-AI-LectureNotes/c/junyeonkim/hun_test/create_file/%s", txt_name);
        int file_descriptor = file_open(address_txt, O_RDONLY, 0644);
        
        return file_descriptor;
    }

void reset_file_pointer(int file_descriptor)
{
    // https://elixir.bootlin.com/linux/latest/source/include/linux/fdtable.h#L49
    // https://elixir.bootlin.com/linux/latest/source/include/linux/fs.h#L1007
    lseek(file_descriptor, 0, SEEK_SET);
}