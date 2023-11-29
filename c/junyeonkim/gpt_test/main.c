#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ui/console/user_keyboard_input.h"

#define MAX_POSTS 100
#define MAX_TITLE_LENGTH 100
#define MAX_CONTENT_LENGTH 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} Post;

Post posts[MAX_POSTS];
int numPosts = 0;

void createPost() {
    if (numPosts >= MAX_POSTS) {
        printf("더 이상 게시글을 작성할 수 없습니다.\n");
        return;
    }

    printf("제목을 입력하세요: ");
    getchar(); // 버퍼 비우기 위한 getchar() 호출
    fgets(posts[numPosts].title, MAX_TITLE_LENGTH, stdin);

    printf("내용을 입력하세요: ");
    fgets(posts[numPosts].content, MAX_CONTENT_LENGTH, stdin);

    numPosts++;

    printf("게시글이 작성되었습니다.\n");

    listPosts(); // 작성 후 목록을 바로 보여줌
}

void listPosts() {
    if (numPosts == 0) {
        printf("작성된 게시글이 없습니다.\n");
        return;
    }

    printf("==== 게시글 목록 ====\n");
    for (int i = 0; i < numPosts; i++) {
        printf("%d. %s", i+1, posts[i].title);
    }

    // 게시글 목록을 파일로 저장
    FILE *file = fopen("post_list.txt", "w");
    if (file == NULL) {
        printf("게시글 목록 파일을 생성할 수 없습니다.\n");
        return;
    }

    for (int i = 0; i < numPosts; i++) {
        fprintf(file, "%d. %s", i+1, posts[i].title);
    }

    fclose(file);

    // 생성된 게시글 목록 파일을 탐색기에서 열기
    system("explorer post_list.txt");
}

void readPost() {
    if (numPosts == 0) {
        printf("작성된 게시글이 없습니다.\n");
        return;
    }

    printf("조회할 게시글 번호를 입력하세요: ");
    int postNumber;
    scanf("%d", &postNumber);

    if (postNumber < 1 || postNumber > numPosts) {
        printf("잘못된 게시글 번호입니다.\n");
        return;
    }

    printf("==== 게시글 내용 ====\n");
    printf("제목: %s", posts[postNumber - 1].title);
    printf("내용: %s", posts[postNumber - 1].content);
}

void updatePost() {
    if (numPosts == 0) {
        printf("작성된 게시글이 없습니다.\n");
        return;
    }

    printf("수정할 게시글 번호를 입력하세요: ");
    int postNumber;
    scanf("%d", &postNumber);

    if (postNumber < 1 || postNumber > numPosts) {
        printf("잘못된 게시글 번호입니다.\n");
        return;
    }

    printf("새로운 제목을 입력하세요: ");
    getchar(); // 버퍼 비우기 위한 getchar() 호출
    fgets(posts[postNumber - 1].title, MAX_TITLE_LENGTH, stdin);

    printf("새로운 내용을 입력하세요: ");
    fgets(posts[postNumber - 1].content, MAX_CONTENT_LENGTH, stdin);

    printf("게시글이 수정되었습니다.\n");

    listPosts(); // 수정 후 목록을 다시 보여줌
}

void deletePost() {
    if (numPosts == 0) {
        printf("작성된 게시글이 없습니다.\n");
        return;
    }

    printf("삭제할 게시글 번호를 입력하세요: ");
    int postNumber;
    scanf("%d", &postNumber);

    if (postNumber < 1 || postNumber > numPosts) {
        printf("잘못된 게시글 번호입니다.\n");
        return;
    }

    // 게시글 삭제 후 배열 앞으로 당기기
    for (int i = postNumber - 1; i < numPosts - 1; i++) {
        strcpy(posts[i].title, posts[i + 1].title);
        strcpy(posts[i].content, posts[i + 1].content);
    }

    numPosts--;

    printf("게시글이 삭제되었습니다.\n");

    listPosts(); // 삭제 후 목록을 다시 보여줌
}

int main() {
    int choice;

    while (1) {
        printf("\n==== 게시판 ====\n");
        printf("1. 글 작성\n");
        printf("2. 글 목록 보기\n");
        printf("3. 글 읽기\n");
        printf("4. 글 수정\n");
        printf("5. 글 삭제\n");
        printf("6. 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createPost();
                break;
            case 2:
                listPosts();
                break;
            case 3:
                readPost();
                break;
            case 4:
                updatePost();
                break;
            case 5:
                deletePost();
                break;
            case 6:
                printf("프로그램을 종료합니다.\n");
                exit(0);
            default:
                printf("잘못된 메뉴 선택입니다.\n");
        }
    }

    return 0;
}