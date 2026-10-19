#include <stdio.h>

// 실습 2: 반복 블록에 들어올 때마다 temp가 다시 생성되고 1로 초기화된다.
// 결과: temp = 1이 다섯 번 출력된다.
int main(void)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        int temp = 1;
        printf("temp = %d\n", temp);
        temp++;
    }

    return 0;
}
