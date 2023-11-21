#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// 게시물 Entity 구조체
typedef struct {
    char title[100];
    char author[100];
    char content[1000];
} Post;

// 게시판 구조체
typedef struct {
    Post* posts[100];
    int count;
} Board;

// 게시판 초기화
void initializeBoard(Board* board) {
    board->count = 0;
}

// 게시물 추가
void addPost(Board* board, Post* post) {
    board->posts[board->count] = post;
    board->count++;
    write(1, "게시물이 작성되었습니다.\n", strlen("게시물이 작성되었습니다.\n"));
}

// 게시물 리스트 출력
void viewPosts(Board* board) {
    if (board->count == 0) {
        write(1, "게시물이 없습니다.\n", strlen("게시물이 없습니다.\n"));
        return;
    }

    write(1, "=== 게시물 목록 ===\n", strlen("=== 게시물 목록 ===\n"));
    for (int i = 0; i < board->count; i++) {
        write(1, board->posts[i]->title, strlen(board->posts[i]->title));
        write(1, "\n", 1);
    }
}

// 게시물 수정
void editPost(Board* board, int index, char* newTitle, char* newContent) {
    if (index < 1 || index > board->count) {
        write(1, "유효하지 않은 게시물 번호입니다.\n", strlen("유효하지 않은 게시물 번호입니다.\n"));
        return;
    }

    Post* post = board->posts[index - 1];
    strcpy(post->title, newTitle);
    strcpy(post->content, newContent);
    write(1, "게시물이 수정되었습니다.\n", strlen("게시물이 수정되었습니다.\n"));
}

// 게시물 삭제
void deletePost(Board* board, int index) {
    if (index < 1 || index > board->count) {
        write(1, "유효하지 않은 게시물 번호입니다.\n", strlen("유효하지 않은 게시물 번호입니다.\n"));
        return;
    }

    for (int i = index - 1; i < board->count - 1; i++) {
        board->posts[i] = board->posts[i + 1];
    }
    board->count--;
    write(1, "게시물이 삭제되었습니다.\n", strlen("게시물이 삭제되었습니다.\n"));
}

// 게시물 읽기
void viewPost(Board* board, int index) {
    if (index < 1 || index > board->count) {
        write(1, "유효하지 않은 게시물 번호입니다.\n", strlen("유효하지 않은 게시물 번호입니다.\n"));
        return; 
    }

    Post* post = board->posts[index - 1];
    write(1, "=== 게시물 내용 ===\n", strlen("=== 게시물 내용 ===\n"));
    write(1, "제목: ", strlen("제목: "));
    write(1, post->title, strlen(post->title));
    write(1, "\n", 1);
    write(1, "작성자: ", strlen("작성자: "));
    write(1, post->author, strlen(post->author));
    write(1, "\n", 1);
    write(1, "내용: ", strlen("내용: "));
    write(1, post->content, strlen(post->content));
    write(1, "\n", 1);
}

int main() {
    Board board;
    initializeBoard(&board);

    while (1) {
        write(1, "=== 게시판 ===\n", strlen("=== 게시판 ===\n"));
        write(1, "1. 게시물 목록 보기\n", strlen("1. 게시물 목록 보기\n"));
        write(1, "2. 게시물 작성\n", strlen("2. 게시물 작성\n"));
        write(1, "3. 게시물 보기\n", strlen("3. 게시물 보기\n"));
        write(1, "4. 게시물 수정\n", strlen("4. 게시물 수정\n"));           
        write(1, "5. 게시물 삭제\n", strlen("5. 게시물 삭제\n"));
        write(1, "0. 종료\n", strlen("0. 종료\n"));
        write(1, "메뉴를 선택하세요: ", strlen("메뉴를 선택하세요: "));

        char choiceStr[2];
        read(0, choiceStr, sizeof(choiceStr)); // 표준 입력에서 데이터를 읽음
        int choice = atoi(choiceStr);

        switch (choice) {
            case 0:
                write(1, "프로그램을 종료합니다.\n", strlen("프로그램을 종료합니다.\n"));
                return 0;
            case 1:
                viewPosts(&board);
                break;
            case 2: {
                Post* post = malloc(sizeof(Post));

                write(1, "제목을 입력하세요: ", strlen("제목을 입력하세요: "));
                read(0, post->title, sizeof(post->title));
                post->title[strlen(post->title) - 1] = '\0'; // 개행 문자 제거

                write(1, "작성자를 입력하세요: ", strlen("작성자를 입력하세요: "));
                read(0, post->author, sizeof(post->author));
                post->author[strlen(post->author) - 1] = '\0';

                write(1, "내용을 입력하세요: ", strlen("내용을 입력하세요: "));
                read(0, post->content, sizeof(post->content));
                post->content[strlen(post->content) - 1] = '\0';

                addPost(&board, post);
                break;
            }
            case 3: {
                char indexStr[4];
                write(1, "게시물 번호를 입력하세요: ", strlen("게시물 번호를 입력하세요: "));
                read(0, indexStr, sizeof(indexStr));
                int index = atoi(indexStr);
                viewPost(&board, index);
                break;
            }
            case 4: {
                char indexStr[4];
                write(1, "수정할 게시물 번호를 입력하세요: ", strlen("수정할 게시물 번호를 입력하세요: "));
                read(0, indexStr, sizeof(indexStr));
                int index = atoi(indexStr);

                Post* post = board.posts[index - 1];
                write(1, "새로운 제목을 입력하세요: ", strlen("새로운 제목을 입력하세요: "));
                read(0, post->title, sizeof(post->title));
                post->title[strlen(post->title) - 1] = '\0';

                write(1, "새로운 내용을 입력하세요: ", strlen("새로운 내용을 입력하세요: "));
                read(0, post->content, sizeof(post->content));
                post->content[strlen(post->content) - 1] = '\0';

                write(1, "게시물이 수정되었습니다.\n", strlen("게시물이 수정되었습니다.\n"));
                break;
            }
            case 5: {
                char indexStr[4];
                write(1, "삭제할 게시물 번호를 입력하세요: ", strlen("삭제할 게시물 번호를 입력하세요: "));
                read(0, indexStr, sizeof(indexStr));
                int index = atoi(indexStr);
                deletePost(&board, index);
                break;
            }
            default:
                write(1, "유효하지 않은 메뉴 번호입니다.\n", strlen("유효하지 않은 메뉴 번호입니다.\n"));
                break;
        }
    }

    return 0;
}

