#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NAME 100

typedef struct phone{
    char name[NAME];
    char number[15];
}phone;

void output_all(phone* fri, int* cou);
void input_number(phone* fri, int* cou);
int s_name(phone* fri);
int removee(phone* fri, int* cou);

int main()
{
    phone friend[100]; // 최대 저장수를 100명으로 가정
    int cou = 0; //저장된 사람 수

    // 메뉴, 사용자의 입력이 잘 못 되면 반복해서 다시 받는다.
    int answer;
    while(1)
    {
        printf("\n"); 
        printf("====MENU==== \n");
        printf( "목록보기 : 1 \n");
        printf( "입력하기 : 2 \n");
        printf( "검색하기 : 3 \n");
        printf( "삭제하기 : 4 \n");
        printf( "종료하기 : 5 \n");
        printf( "============ \n");
        printf( "MENU를 선택하세요 : ");

        scanf("%d", &answer);

        if(answer == 1)
            output_all(friend, &cou);
        else if(answer == 2)
            input_number(friend, &cou);
        else if(answer == 3)
            s_name(friend);
        else if(answer == 4)
            removee(friend, &cou);
        else if(answer == 5)
            break;        
    }
    printf("프로그램을 종료\n");
    return 0;
}

// 출력
void output_all(phone* fri, int* cou) // cou: 사람 수
{
    printf("\n\n====목록====\n");
    for (int i = 0; i < *cou; i++) // 입력순서로 출력
        {
            printf("이름 : %s \n", fri[i].name);
            printf("번호 : %s ", fri[i].number);
            printf("\n\n");
        }
}

// 입력
void input_number(phone* fri, int* cou)
{
    printf("지정할 이름을 입력하세요: ");
    scanf("%s", fri[*cou].name);
    printf("새로운 전화번호를 입력하세요: ");
    scanf("%s", fri[*cou].number);

    (*cou)++;
    printf("입력완료\n");
}

// 검색
int s_name(phone* fri)
{
    char who[NAME];

    printf("검색할 이름 : ");
    scanf("%s", who);

    for (int i = 0; i < 100; i++) // 최대 저장수를 100으로 가정
        {
            if (strcmp(who, fri[i].name) == 0)
            {
                printf("번호 : %s \n", fri[i].number);
                return 0;
            }
        }
    printf("검색 결과 없음\n");
    return 0;
}

// 삭제
int removee(phone* fri, int* cou) 
{
    char who[NAME];
    printf("삭제할 이름 : ");
    scanf("%s", who);

    for (int i = 0; i < 100; i++) // 최대 저장수를 100으로 가정
    {
        if (strcmp(who, fri[i].name) == 0)
        {
            for (int j = i; j < 100; j++) // 최대 저장수를 100으로 가정, 삭제한 항목 다음 항목부터 하나씩 당겨오기
            {
                strcpy(fri[j].name, fri[j + 1].name);
                strcpy(fri[j].number, fri[j + 1].number);
            }
            printf("삭제 완료\n");
            (*cou)--;
            return 0;
        }
    }
    printf("없는 번호입니다\n");
    return 0;
}
