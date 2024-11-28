#include <stdio.h>
#include <math.h>

// 훈련 분야의 개수
#define NUM_FIELDS 9

// 훈련 분야를 나타내는 enum
enum Fields {
    PHYSICAL = 0, KNOWLEDGE, SELF_MANAGEMENT, TEAMWORK,
    KOREAN, VOCAL, DANCE, VISUAL, ACTING
};

// 훈련 분야 이름 배열
const char *field_names[NUM_FIELDS] = {
    "체력", "지식", "자기관리", "팀워크", "한국어", "보컬", "댄스", "비주얼", "연기"
};

// 최소 점수 (1~10 점 사이)
int min_scores[NUM_FIELDS];

// 각 분야별 점수를 저장할 배열 (팀원별 점수 입력)
int scores[NUM_FIELDS];

// 팀 평균 점수를 계산하는 함수
int calculate_team_average(int team_scores[NUM_FIELDS]) {
    int total = 0;
    for (int i = 0; i < NUM_FIELDS; i++) {
        total += team_scores[i];
    }
    return total / NUM_FIELDS;  // 소수점 버림
}

// 데뷔 점수 확인 함수
int check_debut_score(int score) {
    if (score >= 95) {
        return 1;  // 탁월한 점수, 데뷔 가능
    }
    return 0;  // 데뷔 불가
}

// 각 분야 점수 입력 함수
void input_scores() {
    for (int i = 0; i < NUM_FIELDS; i++) {
        printf("%s 분야의 점수를 입력하세요 (1 ~ 11): ", field_names[i]);
        scanf("%d", &scores[i]);

        // 최소 점수 체크
        if (scores[i] < 1 || scores[i] > 11) {
            printf("잘못된 점수입니다. 점수는 1과 11 사이여야 합니다.\n");
            i--;  // 다시 입력 받기 위해
            continue;
        }

        // 최소 점수 미달 확인
        if (scores[i] < min_scores[i]) {
            printf("%s 분야의 점수가 최소 점수에 미달하였습니다. 해당 분야를 재응시해야 합니다.\n", field_names[i]);
            exit(0);  // 프로그램 종료
        }
    }
}

// 팀 평균 점수와 데뷔 점수를 계산하고 출력
void evaluate_team() {
    int team_score = 0;
    int total_score = 0;

    for (int i = 0; i < NUM_FIELDS; i++) {
        if (check_debut_score(scores[i])) {
            printf("%s 분야는 탁월한 점수로 데뷔 가능!\n", field_names[i]);
        }
        total_score += scores[i];  // 총 점수 계산
    }

    // 팀 평균 점수 계산
    team_score = calculate_team_average(scores);
    printf("\n팀 평균 점수: %d\n", team_score);

    // 총점 출력
    printf("각 분야의 최소 점수 미달이 없으므로 인증 시험을 통과했습니다!\n");
    printf("총점: %d/100\n", total_score);
}

int main() {
    // 최소 점수 설정 (각 분야별 최소 점수를 1~10 사이로 설정)
    min_scores[PHYSICAL] = 3;
    min_scores[KNOWLEDGE] = 3;
    min_scores[SELF_MANAGEMENT] = 4;
    min_scores[TEAMWORK] = 3;
    min_scores[KOREAN] = 5;
    min_scores[VOCAL] = 5;
    min_scores[DANCE] = 6;
    min_scores[VISUAL] = 4;
    min_scores[ACTING] = 5;

    // 훈련 분야 점수 입력
    input_scores();

    // 팀 평균 점수 및 데뷔 점수 평가
    evaluate_team();

    return 0;
}
