#include <stdio.h>

#include "player/entity/player.h"
#include "dice/entity/dice.h"
#include "utility/random.h"
#include "utility/common.h"

#define MAX_PLAYER          2
#define MAX_DICE            2   // for 문 돌리기 위해 최대 숫자 선언

#define FIRST_DICE          0
#define SECOND_DICE         1

int find_target_dice(int current_index)   // 타겟팅 리턴
{
    return current_index ? 0 : 1;
}

//                          player *plyer_object[MAX_PLAYER];
//                          배열의 이름을 받을 수 있는 것은 포인터. *가 하나 더 생김
void player_info_allocation(player **player_object_array, char **name)
{
    int i;

    for (i = 0; i < MAX_PLAYER; i++)
    {
        player_object_array[i] = init_player_object();
        set_player_name(player_object_array[i], name[i]);
        print_player_object(player_object_array[i]);
    }
}

void dice_memory_allocation(dice *dice_array[MAX_PLAYER][MAX_DICE])
{
    int i, j;

    random_seed_config();

    for (i = 0; i < MAX_PLAYER; i++)
    {
        for (j = 0; j < MAX_DICE; j++)
        {
            dice_array[i][j] = init_dice_object();
        }
    }
}

void apply_dice_skill(bool isFirstDiceIsEven, 
                    dice *dice_array[MAX_PLAYER][MAX_DICE], 
                    int player_index)
{
    if (isFirstDiceIsEven)
    {
        int target_index;
        int second_dice = get_dice_number(
            dice_array[player_index][SECOND_DICE]);

        switch (second_dice)
        {
            case 2:
                printf("2번 스킬: +3\n");
                add_score(dice_array[player_index][SECOND_DICE]);
                break;
            
            case 3:
                printf("3번 스킬: -4\n");
                target_index = find_target_dice(player_index);
                sub_score(dice_array[target_index][SECOND_DICE]);
                break;
            
            case 4:
                printf("뒤졌음: -4444\n");
                death(dice_array[player_index][SECOND_DICE]);
                break;
            
            default:
                break;
        }
    }
}

void play_dice_game(dice *dice_array[MAX_PLAYER][MAX_DICE])
{
    int i, j;

    for (i = 0; i < MAX_PLAYER; i++)
    {
        printf("player: %d\n", i);
        for (j = 0; j < MAX_DICE; j++)
        {
            bool isFirstDiceIsEven = false;
            if (j == SECOND_DICE)
            {
                // '!' 는 NOT 연산자로
                // 참을 부정하면 거짓
                // 거짓을 부정하면 참
                isFirstDiceIsEven = decision_even(
                        get_dice_number(dice_array[i][FIRST_DICE]));

                if (!isFirstDiceIsEven)
                {
                    break;
                }
            }

            roll_dice(dice_array[i][j]);
            print_dice_object(dice_array[i][j]);

            apply_dice_skill(isFirstDiceIsEven, dice_array, i);
        }
    }
}

int main (void)
{
    // int i, j;
    // player 객체를 관리하는 배열
    // Player playerArray[MAX_PLAYER]; <- Java
    // player는 무엇인가?
    // 우리가 커스텀한 데이터 타입임
    // int와 int * (인트 포인터)의 차이점은 무엇인가 ?
    // int number = 4;
    // int *pointer = &number;
    //
    // number의 메모리       4
    //    pointer        number
    player *player_object[MAX_PLAYER];
    char *name[MAX_PLAYER] = {
        "낵아마",
        "낵아뭐"
    };

    dice *dice_array[MAX_PLAYER][MAX_DICE];

    printf("Eighth work\n");

    player_info_allocation(player_object, name);

    /*
    for (i = 0; i < MAX_PLAYER; i++)
    {
        player_object[i] = init_player_object();
        set_player_name(player_object[i], name[i]);
        print_player_object(player_object[i]);
    }
    */

    dice_memory_allocation(dice_array);
    /*
    random_seed_config();

    for (i = 0; i < MAX_PLAYER; i++)
    {
        for (j = 0; j < MAX_DICE; j++)
        {
            dice_array[i][j] = init_dice_object();
        }
    }
    */

    play_dice_game(dice_array);

   /*
    for (i = 0; i < MAX_PLAYER; i++)
    {
        printf("player: %d\n", i);
        for (j = 0; j < MAX_DICE; j++)
        {
            bool isFirstDiceIsEven = false;
            if (j == SECOND_DICE)
            {
                // '!' 는 NOT 연산자로
                // 참을 부정하면 거짓
                // 거짓을 부정하면 참
                isFirstDiceIsEven = decision_even(
                        get_dice_number(dice_array[i][FIRST_DICE]));

                if (!isFirstDiceIsEven)
                {
                    break;
                }
            }

            roll_dice(dice_array[i][j]);
            print_dice_object(dice_array[i][j]);

            apply_dice_skill(isFirstDiceIsEven, dice_array, i);

            if (isFirstDiceIsEven)
            {
                int target_index;
                int second_dice = get_dice_number(
                    dice_array[i][SECOND_DICE]);

                switch (second_dice)
                {
                    case 2:
                        printf("2번 스킬: +3\n");
                        add_score(dice_array[i][SECOND_DICE]);
                        break;
                    
                    case 3:
                        printf("3번 스킬: -4\n");
                        target_index = find_target_dice(i);
                        sub_score(dice_array[target_index][SECOND_DICE]);
                        break;
                    
                    case 4:
                        printf("뒤졌음: -4444\n");
                        death(dice_array[i][SECOND_DICE]);
                        break;
                    
                    default:
                        break;
                }
            }
        }
    }
    */
    
    return 0;
}