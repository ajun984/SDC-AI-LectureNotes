#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#include "file_io/how_to_make_file.h"
#include "file_io/how_to_write_content.h"
#include "file_io/how_to_read_content.h"

#include "format_test/form_test.h"
#include "format_test/make_file_from_format.h"

#include "board_command_table.h"

#include "func_list/func_list.h"
#include "func_write/func_write.h"


#include "ui/console/user_keyboard_input.h"

#define MAX_OUTPUT_MESSAGE          256


int main (void)
{
    char keyboard_input[MAX_USER_KEYBOARD_INPUT] = { 0 };
    char output_message[MAX_OUTPUT_MESSAGE] = 
    {
        
        "0번. 게시물 조회\n"
        "1번. 게시물 작성\n"
        "2번. 게시물 삭제\n"
        "3번. 게시물 읽기\n"
        "4번. 게시물 수정\n"
        "5번. 프로그램 종료\n"

    };
    //char password_message[MAX_OUTPUT_MESSAGE] = { "비밀번호 입력: " };

     //get_user_keyboard_input(keyboard_input);
     //printf("사용자 입력 데이터: %s\n", keyboard_input);

    get_user_keyboard_input_with_message(output_message, keyboard_input);
    printf("사용자 입력: %d\n", atoi(keyboard_input));
     
     void (**board_menu)(void) = (void (**)(void))malloc(sizeof(void (*)(void)) * 2);
     choose_menu(board_menu);
     board_menu[atoi(keyboard_input)]();

    test_form *format;

    
    char title_keyboard_input[MAX_USER_KEYBOARD_INPUT] = { 0 };
    char user_keyboard_input[MAX_USER_KEYBOARD_INPUT] = { 0 };
    char self_introduction_keyboard_input[MAX_USER_KEYBOARD_INPUT] = { 0 };
    
    char read_board_keyboard_input[MAX_USER_KEYBOARD_INPUT] = { 0 };
    
     char title_output_message[MAX_OUTPUT_MESSAGE] = {
         "제목을 입력해주세요.\n"
     };
     get_user_keyboard_input_with_message(title_output_message, title_keyboard_input);
    
     char user_output_message[MAX_OUTPUT_MESSAGE] = {
         "작성자을 입력해주세요.\n"
     };
     get_user_keyboard_input_with_message(user_output_message, user_keyboard_input);

     char self_introduction_output_message[MAX_OUTPUT_MESSAGE] = {
         "내용을 입력해주세요.\n"
     };
     get_user_keyboard_input_with_message(self_introduction_output_message, self_introduction_keyboard_input);

     format = init_test_form(title_keyboard_input, user_keyboard_input, self_introduction_keyboard_input);
     write_format_to_file(format);
    
    
    /*
    char read_board_output_message[MAX_OUTPUT_MESSAGE] = {
        "읽어볼 게시물의 제목을 입력하세요.\n"
    };
    get_user_keyboard_input_with_message(read_board_output_message, read_board_keyboard_input);
    read_file_to_format(read_board_keyboard_input);
    */

    
    

    

    return 0;
}
