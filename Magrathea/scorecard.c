#include <stdio.h>
#include <stdlib.h>

#define CANDIDATE_COUNT 6
#define SCORE_COUNT 5 // 음악 소양, 댄스, 보컬, 비주얼, 전달력

int main() {
    // 후보자 정보를 저장 [구조체 정의]
    typedef struct {
        char name[50];
        int id; // 고유 ID
    } Candidate;

    // 심사자 정보를 저장 [구조체 정의]
    typedef struct {
        char judge_name[50];
        char specialty[20]; // 전문 분야
    } Judge;

    // 후보자 점수 시트를 저장[ 구조체 정의]
    typedef struct {
        int id; // 후보자 고유 ID
        int scores[SCORE_COUNT]; // 5개 점수
        int total_score; // 총점
    } ScoringSheet;

    // 후보자 초기화 [name, 고유 ID]
    Candidate candidates[CANDIDATE_COUNT] = {
        {"박지연", 123456},
        {"Ethan Smith", 654321},
        {"Helena Silva", 112233},
        {"Liam Wilson", 223344},
        {"김하린", 334455},
        {"Chloe Nguyen", 445566}
    };

    // 점수 시트 배열
    ScoringSheet scoring_sheets[CANDIDATE_COUNT] = { 0 };

    // 심사자 정보 입력
    Judge judge;
    printf("심사자 이름을 입력하세요: ");
    scanf_s("%s", judge.judge_name, (unsigned)_countof(judge.judge_name));
    printf("심사자 전문 분야를 입력하세요(분야: 음악 소양, 댄스, 보컬, 비주얼, 전달력): ");
    scanf_s("%s", judge.specialty, (unsigned)_countof(judge.specialty));

    // 심사 점수 입력
    printf("####################################\n");
    printf("#       오디션 심사 결과 입력       #\n");
    printf("####################################\n");
    printf("> 심사자 이름: %s\n", judge.judge_name);
    printf("> 전문 분야: %s\n", judge.specialty);
    printf("++++++++++++++++++++++++++++++++++++\n");

    for (int i = 0; i < CANDIDATE_COUNT; i++) {
        printf("후보자: %s\n", candidates[i].name);
        printf("%s 점수: ", judge.specialty);

        int score;
        while (1) {
            scanf_s("%d", &score);
            if (score >= 10 && score <= 100) break;
            printf("잘못된 점수입니다. 다시 입력해 주세요 (10~100): ");
        }

        scoring_sheets[i].id = candidates[i].id;
        scoring_sheets[i].scores[0] = score;
        scoring_sheets[i].total_score = score; // 전문 분야 점수 초기화
        printf("------------------------------------\n");
    }

    // 완료 후 내용 검토
    printf("입력을 모두 완료했습니다.\n입력하신 내용을 검토하세요!\n");
    for (int i = 0; i < CANDIDATE_COUNT; i++) {
        printf("%s: %d\n", candidates[i].name, scoring_sheets[i].total_score);
    }

    // 제출 확인
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
        return 0; // 값
    }

    // 최종 선발 기준 -> 총점 높은순서
    for (int i = 0; i < CANDIDATE_COUNT - 1; i++) {
        for (int j = i + 1; j < CANDIDATE_COUNT; j++) {
            if (scoring_sheets[i].total_score < scoring_sheets[j].total_score) {
                // ScoringSheet 스왑
                ScoringSheet temp = scoring_sheets[i];
                scoring_sheets[i] = scoring_sheets[j];
                scoring_sheets[j] = temp;

                Candidate temp_candidate = candidates[i];
                candidates[i] = candidates[j];
                candidates[j] = temp_candidate;
            }
        }
    }

    printf("=======================================\n");
    printf("후보 선발 결과 집계 중 ...\n");
    printf("=======================================\n");
    printf("#######################################\n");
    printf("# 밀리웨이즈의 멤버가 된 걸축하합니다!  #\n");
    printf("#######################################\n");

   // 1등부터 4등까지 출력
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    return 0;
}
