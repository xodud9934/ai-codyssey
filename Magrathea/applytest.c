#include <stdio.h>
#include <math.h>

#define NUM_FIELDS 9
#define MIN_DAYS 30
#define MAX_DAYS 100

// 훈련 분야를 나열한 배열
const char* fields[NUM_FIELDS] = {
    "체력", "지식", "자기관리", "팀워크",
    "한국어", "보컬", "댄스", "비주얼", "연기"
};

// 훈련 시작 날짜
int start_date;

// 응시 날짜 배열
int exam_dates[NUM_FIELDS];

// 각 분야별 최소 날짜 (훈련 시작일 + 최소 30일)
int min_exam_dates[NUM_FIELDS];

// 각 분야별 최대 날짜 (훈련 시작일 + 최대 100일)
int max_exam_dates[NUM_FIELDS];

// 훈련 프로그램의 진행 상태 (0: 응시 안함, 1: 응시 완료)
int exam_status[NUM_FIELDS] = { 0 };

// 훈련 시작 날짜를 입력받는 함수
void input_start_date() {
    printf("훈련 시작 날짜를 입력하세요 (YYYYMMDD): ");
    scanf_s("%d", &start_date);

    // 최소 30일 이후부터 응시할 수 있음
    for (int i = 0; i < NUM_FIELDS; i++) {
        min_exam_dates[i] = start_date + MIN_DAYS;
        max_exam_dates[i] = start_date + MAX_DAYS;
    }
}

// 응시 가능한 날짜를 확인하는 함수
int is_exam_possible(int field, int exam_date) {
    if (exam_date < min_exam_dates[field]) {
        return 0; // 최소 날짜 이전에는 응시 불가능
    }
    if (exam_date > max_exam_dates[field]) {
        return 0; // 최대 날짜 이후에는 응시 불가능
    }
    return 1; // 응시 가능
}

// 인증 시험 응시 예약을 진행하는 함수
void reserve_exam() {
    int field, exam_date;

    printf("훈련 분야를 선택하세요 (1: 체력, 2: 지식, 3: 자기관리, 4: 팀워크, 5: 한국어, 6: 보컬, 7: 댄스, 8: 비주얼, 9: 연기): ");
    scanf_s("%d", &field);
    field--;  // 배열은 0부터 시작하므로 1을 빼야 함

    printf("응시 날짜를 입력하세요 (YYYYMMDD): ");
    scanf_s("%d", &exam_date);

    if (exam_status[field] == 1) {
        printf("%s 분야는 이미 응시 완료되었습니다.\n", fields[field]);
        return;
    }

    // 응시 가능 여부 확인
    if (is_exam_possible(field, exam_date)) {
        exam_dates[field] = exam_date;
        exam_status[field] = 1; // 응시 완료 상태로 변경
        printf("%s 분야의 인증 시험 예약이 완료되었습니다.\n", fields[field]);
    }
    else {
        printf("%s 분야는 %d일 이후 %d일 이내에만 응시 가능합니다.\n", fields[field], min_exam_dates[field], max_exam_dates[field]);
    }
}

// 인증 시험 예약 결과 출력
void print_exam_results() {
    printf("\n--- 인증 시험 예약 결과 ---\n");
    for (int i = 0; i < NUM_FIELDS; i++) {
        if (exam_status[i] == 1) {
            printf("%s 분야: %d\n", fields[i], exam_dates[i]);
        }
        else {
            printf("%s 분야: 응시하지 않음\n", fields[i]);
        }
    }
}

int main() {
    // 훈련 시작 날짜 입력
    input_start_date();

    // 인증 시험 예약을 반복적으로 진행
    int continue_reserving = 1;
    while (continue_reserving) {
        reserve_exam();

        printf("계속해서 시험 예약을 진행하시겠습니까? (1: 예, 0: 아니오): ");
        scanf_s("%d", &continue_reserving);
    }

    // 시험 예약 결과 출력
    print_exam_results();

    return 0;
}
