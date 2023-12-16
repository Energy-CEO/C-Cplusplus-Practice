#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

// 두 수를 입력받아 더하는 함수 형성
void get_two_integers_and_add()
{
    int a, b;
    printf("첫 번째 정수를 입력하세요 : ");
    scanf("%d", &a);
    printf("두 번째 정수를 입력하세요 : ");
    scanf("%d", &b);
    printf("두 수의 합은 %d입니다.\n", a+b);
}

// 구구단
void multiplication_table()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            printf("%d * %d = %d\n", i, j, i*j);
        }
    }
}

// domain 관점이 들어가지 않은 랜덤 속도 생성 함수
void velocity_generation()
{
    srand(time(NULL));
    
    for (int i = 0; i < 10; i++)
    {
        int angle = rand() % 360 + 1;
        int speed = rand() % 10 + 1;
        double direction = (2 * M_PI) / 360 * angle;
        printf("현재 물체의 속도는 %d m/s 입니다.\n", speed);
        printf("현재 물체의 방향은 %.2lf 라디안 입니다.\n", direction);
        printf("따라서 x축 속도는 %.2lf 이며 y축 속도는 %.2lf 이라는 것을 알 수 있습니다.\n", speed*cos(direction), speed*sin(direction));
        printf("\n");
    }
}

int main (void)
{
    // multiplication_table();
    velocity_generation();
    return 0;
}