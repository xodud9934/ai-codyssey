#include <stdio.h>
#include <stdlib.h>

int main() {
    char name[60];       
    char date[11];      
   
    printf("[현재 날짜를 \"yyyy-mm-dd\" 형식으로 입력하세요]: ");
    scanf("%s", date);  

    printf("[당신의 이름을 입력하세요]: ");
    scanf(" %s", name);  

    printf("**입력이 정상적으로 처리되었습니다.**\n");
    
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("                         [마그라테아 ver 0.1]                               \n");
    printf("           풀 한 포기 없는 황무지에서 반짝이는 행성을 만들내는 곳 마그라테아,         \n");
    printf("         사람들이 보지 못하는 잠재력을 찾고 전문가의 손길을 더해 보석을 빗는 곳,    \n");
    printf("                    마그라테아에 오신걸 환영합니다.\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("[사용자]: %s                                   [실행 시간]: %s\n", name, date);
    printf("================================================================================\n");

    system("pause");
    return 0;
}