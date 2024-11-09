#include <stdio.h>
#include <stdlib.h>

#define CANDIDATE_COUNT 6

// 후보자 정보 구조체 정의
typedef struct {
    char name[50];
    int id;
    int birthdate;  // 생년월일 (YYYYMMDD 형식)
    char gender[10];
    char email[50];
    char nationality[20];
    float bmi;
    char main_skill[20];
    char sub_skill[20];
    int korean_level;
    char mbti[5];
    char nickname[20];
    char education[20];
    float height;  // 키 (m 단위)
    float weight;  // 몸무게 (kg 단위)
    char blood_type[5];
    char allergy[50];
    char hobbies[100];
    char sns[50];
    int passed;  // 합격 여부 (0: 불합격, 1: 합격)
} Candidate;

// 합격한 후보자들을 담을 배열 (milliways##_arr 배열)
Candidate milliways_arr[CANDIDATE_COUNT];

// 후보자 데이터 초기화 (합격 여부 포함)
Candidate candidate_arr[CANDIDATE_COUNT] = {
    {"박지연", 100001, 20060415, "여", "jiyeon@outlook.com", "한국", 18.5, "댄스", "작곡", 0, "ENFJ", "Ariel", "고1중퇴", 1.68, 52, "A", "유제품", "댄스 연습, 작곡", "Instagram - @Ariel_Jiyeon", 1},
    {"Ethan Smith", 100002, 20050822, "남", "ethan@outlook.com", "미국", 21.2, "보컬", "작사", 2, "ISTP", "Simba", "중3중퇴", 1.78, 72, "O", "땅콩", "노래 작곡, 헬스 트레이닝", "Twitter - @Simba_Ethan", 1},
    {"Helena Silva", 100003, 20070310, "여", "helena@outlook.com", "브라질", 20.8, "보컬", "작곡 및 작사", 1, "ENFP", "Belle", "중졸", 1.63, 55, "B", "생선", "노래 부르기, 그림 그리기", "Instagram - @Belle_Helena", 1},
    {"Liam Wilson", 100004, 20061108, "남", "liam@outlook.com", "호주", 20.1, "댄스", "작곡 및 작사", 3, "ENTJ", "Aladdin", "중2중퇴", 1.75, 65, "AB", "갑각류", "춤추기, 음악 프로듀싱", "Instagram - @Aladdin_Liam", 0},
    {"김하린", 100005, 20051205, "여", "harin@outlook.com", "한국", 19.0, "보컬", "댄스", 0, "ISFJ", "Jenna", "고등학교", 1.65, 50, "B", "밀", "노래 부르기, 독서", "Instagram - @Harin_Kim", 1},
    {"Chloe Nguyen", 100006, 20031230, "여", "chloe@outlook.com", "베트남", 18.7, "댄스", "연기", 1, "INFJ", "Chloe", "고2중퇴", 1.70, 58, "A", "돼지고기", "영화 감상, 연기", "Twitter - @Chloe_Nguyen", 0}
};

// BMI를 통해 몸무게 계산
float calculate_weight(float height, float bmi) {
    return bmi * height * height;
}

// 인터뷰를 통해 추가 정보를 수집
void collect_interview_data(int idx) {
    Candidate *candidate = &milliways_arr[idx];

    printf("\n%s의 인터뷰를 진행합니다.\n", candidate->name);

    // 몸무게 계산 (키와 BMI로 몸무게 계산)
    candidate->weight = calculate_weight(candidate->height, candidate->bmi);

    printf("몸무게가 %.1f kg으로 계산되었습니다.\n", candidate->weight);
    
    printf("주 스킬: ");
    scanf_s("%s", candidate->main_skill, (unsigned)_countof(candidate->main_skill));

    printf("보조 스킬: ");
    scanf_s("%s", candidate->sub_skill, (unsigned)_countof(candidate->sub_skill));

    printf("한국어 등급: ");
    scanf_s("%d", &candidate->korean_level);

    printf("MBTI: ");
    scanf_s("%s", candidate->mbti, (unsigned)_countof(candidate->mbti));

    printf("닉네임: ");
    scanf_s("%s", candidate->nickname, (unsigned)_countof(candidate->nickname));

    printf("학력: ");
    scanf_s("%s", candidate->education, (unsigned)_countof(candidate->education));

    printf("혈액형: ");
    scanf_s("%s", candidate->blood_type, (unsigned)_countof(candidate->blood_type));

    printf("알러지: ");
    scanf_s("%s", candidate->allergy, (unsigned)_countof(candidate->allergy));

    printf("취미: ");
    scanf_s("%s", candidate->hobbies, (unsigned)_countof(candidate->hobbies));

    printf("SNS: ");
    scanf_s("%s", candidate->sns, (unsigned)_countof(candidate->sns));
}

int main() {
    int milliways_count = 0;

    // 합격한 후보자들의 데이터만 milliways_arr로 복사하고 인터뷰 진행
    for (int i = 0; i < CANDIDATE_COUNT; i++) {
        if (candidate_arr[i].passed == 1) {
            // 기존 후보자 정보를 milliways_arr에 복사
            milliways_arr[milliways_count] = candidate_arr[i];

            // 인터뷰 진행
            collect_interview_data(milliways_count);
            
            // 합격자 수 증가
            milliways_count++;
        }
    }

    // 최종 결과 출력
    printf("\n=== 최종 합격자의 인터뷰 결과 ===\n");
    for (int i = 0; i < milliways_count; i++) {
        Candidate *candidate = &milliways_arr[i];
        
        printf("\n%s (ID: %d)\n", candidate->name, candidate->id);
        printf("생년월일: %d\n", candidate->birthdate);
        printf("성별: %s\n", candidate->gender);
        printf("이메일: %s\n", candidate->email);
        printf("국적: %s\n", candidate->nationality);
        printf("BMI: %.1f\n", candidate->bmi);
        printf("주 스킬: %s\n", candidate->main_skill);
        printf("보조 스킬: %s\n", candidate->sub_skill);
        printf("한국어 등급: %d\n", candidate->korean_level);
        printf("MBTI: %s\n", candidate->mbti);
        printf("닉네임: %s\n", candidate->nickname);
        printf("학력: %s\n", candidate->education);
        printf("키: %.2f m\n", candidate->height);
        printf("몸무게: %.1f kg\n", candidate->weight);
        printf("혈액형: %s\n", candidate->blood_type);
        printf("알러지: %s\n", candidate->allergy);
        printf("취미: %s\n", candidate->hobbies);
        printf("SNS: %s\n", candidate->sns);
    }

    return 0;
}
