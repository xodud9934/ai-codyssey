#include <stdio.h>
#include <stdlib.h>

int main() {
    char judges_array[5][512]; // json
    char projectName[100];
    int judgeCount = 0;

    printf("####################################\n");
    printf("#       심사자 풀 데이터 입력       #\n");
    printf("####################################\n");

    printf("> 참여 프로젝트: ");
    scanf_s(" %[^\n]", projectName, (unsigned)sizeof(projectName));

    while (judgeCount < 5) { 
        char name[50], gender[5], so[100], name2[100], pro[100], email[100], phone[20];

        printf("++++++++++++++++++++++++++++++++++++\n");
        printf("심사자 %d 정보 입력:\n", judgeCount + 1);

        printf("이름: ");
        scanf(" %[^\n]", name, (unsigned)sizeof(name));

        // 체크
        if (name[0] == '\0') continue;

        printf("성별: ");
        scanf(" %[^\n]", gender, (unsigned)sizeof(gender));
        if (gender[0] == '\0') continue;

        printf("소속: ");
        scanf(" %[^\n]", so, (unsigned)sizeof(so));
        if (so[0] == '\0') continue;

        printf("직함: ");
        scanf(" %[^\n]", name2, (unsigned)sizeof(name2));
        if (name2[0] == '\0') continue;

        printf("전문 분야: ");
        scanf(" %[^\n]", pro, (unsigned)sizeof(pro));
        if (pro[0] == '\0') continue;

        printf("메일: ");
        scanf(" %[^\n]", email, (unsigned)sizeof(email));
        if (email[0] == '\0') continue;

        printf("전화: ");
        scanf(" %[^\n]", phone, (unsigned)sizeof(phone));
        if (phone[0] == '\0') continue;

       
        snprintf(judges_array[judgeCount], sizeof(judges_array[judgeCount]),
            "이름:%s \n성별:%s \n소속:%s\n직함%s\n전문 분야:%s\n메일:%s\n전화\:%s",
            name, gender, so, name2, pro, email, phone); //json 저장

        judgeCount++;
    }

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("     심사자 풀 입력이 끝났습니다.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    char m;
    printf("  [PROJECT] 심사자 풀을 확인할까요? (Y/N): ");
    scanf(" %c", &m);

    if (m == 'Y') {
        printf("####################################\n");
        printf("#       심사자 풀 데이터 출력       #\n");
        printf("####################################\n");

        for (int i = 0; i < judgeCount; i++) {
            printf("[심사자 %d]\n", i + 1);
            printf("%s\n", judges_array[i]); //json 출력
            printf("-----------------------------------\n");
        }
    }

    return 0;
}
