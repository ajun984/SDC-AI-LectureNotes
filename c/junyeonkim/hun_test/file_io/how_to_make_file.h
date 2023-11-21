#ifndef __HOW_TO_MAKE_FILE_H__
#define __HOW_TO_MAKE_FILE_H__

#define ERROR               (-1)

int file_open(char *filename, int option, unsigned int permission);
int create_file_descriptor(char* txt_name);
void file_close(int file_descriptor);

#endif