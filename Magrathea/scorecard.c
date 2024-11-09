#include <stdio.h>
#include <stdlib.h>

#define CANDIDATE_COUNT 6
#define FIELD_COUNT 5    // 5개 분야 점수
#define SCORE_COUNT (FIELD_COUNT + 1)  // 5개 분야 점수 + 총점

int main() {
    // 후보자 정보를 저장하기 위한 구조체 정의
    typedef struct {
        char name[50];
        int id; // 고유 ID, 중복되지 않는 6자리 정수
    } Candidate;

    // 후보자 점수 시트를 저장하는 구조체 정의
    typedef struct {
        int id; // 후보자 고유 ID
        int scores[SCORE_COUNT]; // 5개 분야 점수 + 총점
    } ScoringSheet;

    // 후보자 초기화 (이름과 고유 ID)
    Candidate candidates[CANDIDATE_COUNT] = {
        {"박지연", 100001},
        {"Ethan Smith", 100002},
        {"Helena Silva", 100003},
        {"Liam Wilson", 100004},
        {"김하린", 100005},
        {"Chloe Nguyen", 100006}
    };

    // 점수 시트 배열
    ScoringSheet scoring_sheets[CANDIDATE_COUNT] = { 0 };

    // 각 분야 이름
    char* fields[FIELD_COUNT] = { "소양", "소양", "소양", "소양", "소양" };

    // 각 분야별 심사자 정보 입력
    typedef struct {
        char judge_name[50];
        char specialty[50];
    } Judge;

    Judge judges[FIELD_COUNT];

    // 각 분야별 심사자 정보 입력
    for (int i = 0; i < FIELD_COUNT; i++) {
        printf("####################################\n");
        printf("#       오디션 심사 결과 입력       #\n");
        printf("####################################\n");
        printf("> 심사자 이름: ");
        scanf_s("%s", judges[i].judge_name, (unsigned)_countof(judges[i].judge_name));
        printf("> 전문 분야(음악, 댄스, 보컬, 비주얼, 전달력): ");
        scanf_s("%s", judges[i].specialty, (unsigned)_countof(judges[i].specialty));
        printf("++++++++++++++++++++++++++++++++++++\n");

        // 각 후보자에 대해 해당 분야의 점수 입력
        for (int j = 0; j < CANDIDATE_COUNT; j++) {
            int score;
            printf("후보자: %s\n", candidates[j].name);
            printf("%s %s: ", judges[i].specialty, fields[i]);
            while (1) {
                scanf_s("%d", &score);
                if (score >= 10 && score <= 100) break;
                printf("잘못된 점수입니다. 10~100 점 사이로 다시 입력해 주세요.\n");
            }
            scoring_sheets[j].id = candidates[j].id;
            scoring_sheets[j].scores[i] = score;  // 각 분야 점수 저장
            printf("------------------------------------\n");  // 후보자별 구분
        }
    }

    // 점수 입력 완료 후 검토
    printf("입력을 모두 완료했습니다.\n입력하신 내용을 검토하세요!\n");
    for (int i = 0; i < CANDIDATE_COUNT; i++) {
        int total_score = 0;
        for (int j = 0; j < FIELD_COUNT; j++) {
            total_score += scoring_sheets[i].scores[j];  // 각 분야 점수 합산
        }
        scoring_sheets[i].scores[FIELD_COUNT] = total_score;  // 총점 저장
        printf("%s: 총점 = %d\n", candidates[i].name, total_score);
    }

    // 제출 여부 확인
    char submit;
    printf("제출하시겠습니까? (Y/N): ");
    while (1) {
        scanf_s(" %c", &submit, 1);
        if (submit == 'Y' || submit == 'N') break;
        printf("잘못된 입력입니다. Y 또는 N을 입력하세요: ");
    }

    if (submit == 'Y') {
        printf("***최종 제출을 완료했습니다.***\n");
    }
    else {
        printf("처음으로 돌아갑니다...\n");
        return 0; // 다시 시작하도록 main 종료
    }

    // 총점 기준으로 후보자들 정렬 (내림차순)
    for (int i = 0; i < CANDIDATE_COUNT - 1; i++) {
        for (int j = i + 1; j < CANDIDATE_COUNT; j++) {
            if (scoring_sheets[i].scores[FIELD_COUNT] < scoring_sheets[j].scores[FIELD_COUNT]) {
                // ScoringSheet 스왑
                ScoringSheet temp = scoring_sheets[i];
                scoring_sheets[i] = scoring_sheets[j];
                scoring_sheets[j] = temp;

                // Candidate 스왑 (순서 맞추기 위해)
                Candidate temp_candidate = candidates[i];
                candidates[i] = candidates[j];
                candidates[j] = temp_candidate;
            }
        }
    }

    // 최종 선발 멤버 출력
    printf("=======================================\n");
    printf("후보 선발 결과 집계 중 ...\n");
    printf("=======================================\n");
    printf("#######################################\n");
    printf("# 밀리웨이즈의 멤버가 된 걸축하합니다!  #\n");
    printf("#######################################\n");

    // 상위 4명 출력
    for (int i = 0; i < 4; i++) {
        printf("%d. %s (총점: %d)\n", i + 1, candidates[i].name, scoring_sheets[i].scores[FIELD_COUNT]);
    }

    return 0;
}
