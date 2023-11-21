#include "board_command_table.h"
#include "func1/func1.h"
#include "func2/func2.h"
void choose_menu(void (**board_menu)(void))
{
    board_menu[0] = write_board;
    board_menu[1] = func2;
    
}