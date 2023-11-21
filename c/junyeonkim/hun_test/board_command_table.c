#include "board_command_table.h"
#include "func_list/func_list.h"
#include "func_write/func_write.h"
void choose_menu(void (**board_menu)(void))
{
    board_menu[0] = list_board;
    board_menu[1] = write_board;
}