#include <stdio.h>
#include <stdlib.h>

struct mem {
    char name[50]; // 1성명
    char birth[11]; //2생일
    char gender;   //3성별
    char email[100]; //4메일
    char nat[50]; //5국적
    float bmi; //6BMI
    char mskill[50]; //7주 스킬
    char sskill[50]; // 8보조스킬
    int grade; // 9한국어 둥급
    char mbti[5]; // 10mbti
    char intr[256]; //11소개
};



int main(){
    struct mem c[6];
    int i;

    printf("####################################\n");
    printf("     오디션 후보자 데이터 입력\n");
    printf("####################################\n");

    while (i < 6){
        printf("%d번째 후보자의 정보를 입력합니다.\n", i + 1);
        printf("---------------------------------\n");
        
        printf("1. 성명: ");
        scanf("%s", c[i].name);
        
        printf("2. 생일(YYYY/MM/DD 형식): ");
        scanf("%s", c[i].birth);
        
        printf("3. 성별(여성이면 F 또는 남성이면 M): ");
        scanf(" %c", &c[i].gender); 
        
        printf("4. 메일 주소: ");
        scanf("%s", c[i].email);
        
        printf("5. 국적: ");
        scanf("%s", c[i].nat);
        
        printf("6. BMI: ");
        scanf("%f", &c[i].bmi);
      
        printf("7. 주 스킬: ");
        scanf("%s", c[i].mskill);
     
        printf("8. 보조 스킬: ");
        scanf("%s", c[i].sskill);
        
        printf("9. 한국어 등급: ");
        scanf("%d", &c[i].grade);
        
        printf("10. MBTI: ");
        scanf("%s", c[i].mbti);

        printf("11. 소개: ");
        getchar();
        fgets(c[i].intr, sizeof(c[i].intr), stdin);
        
              
        // 개행 문자를 수동으로 처리하지 않음
        c[i].intr[255] = '\0'; // 안전하게 마지막에 널 문자 추가


        printf("=================================\n");
        i++; // 후보자 수 증가

    }

    printf("####################################\n");
    printf("     오디션 후보자 데이터 조회 \n");
    printf("####################################\n");
    printf("=============================================================================================\n");
    printf("성   명 | 생   일 | 성별 | 메   일            | 국적 | BMI | 주스킬 | 보조스킬 | TOPIK | MBTI |\n");
    printf("=============================================================================================\n");

    for(i=0; i<6; i++){
        printf("%s|%s|%c|%s|%s|%f|%s|%s|%s|%s\n",
        c[i].name,
        c[i].birth,
        c[i].gender,
        c[i].email,
        c[i].nat,
        c[i].bmi,
        c[i].mskill,
        c[i].sskill,
        (c[i].grade == 0) ? "원어민" : "기타", // 등급 출력
        c[i].mbti);
        printf("--------------------------------------------------\n");
        printf("%s\n",c[i].intr);
        printf("--------------------------------------------------\n");
        }
}





        
