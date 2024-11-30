#include <stdio.h>
#include <string.h>

#define CANDIDATE_COUNT 6

// 후보자 데이터 구조체 정의
typedef struct {
    char name[50];
    int candidate_id;
    int birthdate;
    char gender[10];
    char email[50];
    char country[50];
    float height;
    char primary_skill[50];
    char secondary_skill[50];
    int failure_count;
    char mbti[5];
    char nickname[50];
    char education[50];
    float weight;
    int age;
    char blood_type[5];
    char allergy[50];
    char hobby[100];
    char social_media[100];
    int passed;  // 1: 합격, 0: 불합격
} Candidate;

// 후보자 배열 초기화
Candidate candidate_arr[CANDIDATE_COUNT] = {
    {"박지연", 100001, 20060415, "여", "jiyeon@outlook.com", "한국", 18.5, "댄스", "작곡", 0, "ENFJ", "Ariel", "고1중퇴", 1.68, 52, "A", "유제품", "댄스 연습, 작곡", "Instagram - @Ariel_Jiyeon", 1},
    {"Ethan Smith", 100002, 20050822, "남", "ethan@outlook.com", "미국", 21.2, "보컬", "작사", 2, "ISTP", "Simba", "중3중퇴", 1.78, 72, "O", "땅콩", "노래 작곡, 헬스 트레이닝", "Twitter - @Simba_Ethan", 1},
    {"Helena Silva", 100003, 20070310, "여", "helena@outlook.com", "브라질", 20.8, "보컬", "작곡 및 작사", 1, "ENFP", "Belle", "중졸", 1.63, 55, "B", "생선", "노래 부르기, 그림 그리기", "Instagram - @Belle_Helena", 1},
    {"Liam Wilson", 100004, 20061108, "남", "liam@outlook.com", "호주", 20.1, "댄스", "작곡 및 작사", 3, "ENTJ", "Aladdin", "중2중퇴", 1.75, 65, "AB", "갑각류", "춤추기, 음악 프로듀싱", "Instagram - @Aladdin_Liam", 0},
    {"김하린", 100005, 20051205, "여", "harin@outlook.com", "한국", 19.0, "보컬", "댄스", 0, "ISFJ", "Jenna", "고등학교", 1.65, 50, "B", "밀", "노래 부르기, 독서", "Instagram - @Harin_Kim", 1},
    {"Chloe Nguyen", 100006, 20031230, "여", "chloe@outlook.com", "베트남", 18.7, "댄스", "연기", 1, "INFJ", "Chloe", "고2중퇴", 1.70, 58, "A", "돼지고기", "영화 감상, 연기", "Twitter - @Chloe_Nguyen", 0}
};

// 롤링페이퍼 메시지
typedef struct {
    char author[50];  // 작성자
    char message[500];  // 메시지 내용
} RollingPaper;

// 각 후보자에 대한 롤링페이퍼 배열
RollingPaper rollingpp[CANDIDATE_COUNT][10];  // 각 후보자별로 최대 10개의 메시지 저장 가능

// 후보자 배열에서 메시지 입력 함수
void inputMessages() {
    int choice;
    char author[50];
    char message[200];

    // 메시지 전송 대상 선택
    printf("\n메시지를 보낼 후보자 번호를 선택하세요 (종료하려면 0을 입력):\n");
    for (int i = 0; i < CANDIDATE_COUNT; i++) {
        printf("[%d] %s (%s)\n", i + 1, candidate_arr[i].name, candidate_arr[i].passed == 1 ? "합격" : "불합격");
    }
    printf("[0] 초기화면\n");
    scanf_s("%d", &choice);
    printf("\n※알림※ %d번을 선택하셨습니다\n", choice);

    if (choice == 0) {
        printf("초기화면으로 돌아갑니다.\n");
        return;
    }

    // 메시지 작성자 입력
    if (choice >= 1 && choice <= CANDIDATE_COUNT) {
        printf("메시지 작성자: ");
        scanf_s("%s", author, sizeof(author));

        // 메시지 내용 입력
        printf("%s에게 보낼 메시지를 입력하세요: ", candidate_arr[choice - 1].name);
        scanf_s(" %[^\n]", message, sizeof(message));  // 여러 단어 입력을 받기 위해 " " 포함

        // 새로운 메시지 추가
        int msg_count = 0;
        while (strlen(rollingpp[choice - 1][msg_count].message) > 0) {
            msg_count++;  // 기존 메시지가 있는 위치로 이동
        }

        // 작성된 메시지 저장
        strcpy_s(rollingpp[choice - 1][msg_count].author, sizeof(rollingpp[choice - 1][msg_count].author), author);
        strcpy_s(rollingpp[choice - 1][msg_count].message, sizeof(rollingpp[choice - 1][msg_count].message), message);
    }
    else {
        printf("잘못된 선택입니다.\n");
    }
}

// 메시지 리스트 출력 함수
void printMessages() {
    int choice;
    printf("\n어떤 후보자에게 보낸 메시지를 출력할까요?\n");
    for (int i = 0; i < CANDIDATE_COUNT; i++) {
        printf("[%d] %s\n", i + 1, candidate_arr[i].name);
    }
    printf("[0] 종료\n");
    scanf_s("%d", &choice);
    printf("\n※알림※ %d번을 선택하셨습니다\n", choice);

    if (choice == 0) {
        printf("초기화면으로 돌아갑니다.\n");
        return;
    }

    if (choice >= 1 && choice <= CANDIDATE_COUNT) {
        printf("\n###################\n");
        printf("%s 롤링 페이퍼\n", candidate_arr[choice - 1].name);
        printf("###################\n");
        for (int i = 0; i < 10; i++) {
            if (strlen(rollingpp[choice - 1][i].message) > 0) {
                printf("----------------------------------------------------------------------------------------------------------\n");
                printf("%s: %s\n", rollingpp[choice - 1][i].author, rollingpp[choice - 1][i].message);
            }
        }
    }
    else {
        printf("잘못된 선택입니다.\n");
    }
}

// 프로그램 실행
int main() {
    int action;

    while (1) {
        // 사용자가 할 작업 선택
        printf("=====================================================\n");
        printf("        밀리웨이즈 오디션 디지털 롤링페이퍼\n");
        printf("=====================================================\n");
        printf("                번호를 선택해주세요!!\n");
        printf("                [1] 메시지 입력\n");
        printf("                [2] 메시지 출력\n");
        printf("                [0] 종료\n");
        scanf_s("%d", &action);

        if (action == 1) {
            inputMessages();  // 메시지 입력
        }
        else if (action == 2) {
            printMessages();  // 메시지 출력
        }
        else if (action == 0) {
            printf("프로그램을 종료합니다.\n");
            break;  // 종료
        }
        else {
            printf("잘못된 선택입니다.\n");
        }
    }

    return 0;
}
