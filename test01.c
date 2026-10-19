#include <stdio.h>

// 실습 1: y를 while 밖에 선언해야 블록이 끝난 뒤에도 사용할 수 있다.
// 수정 전 코드는 test01-before/main.c에 있다. 수정 후 결과: y = 4
int main(void)
{
    int flag = 1;
    int y;

    while (flag != 0)
    {
        y = 3;
        flag = 0;
    }

    y = 4;
    printf("y = %d\n", y);

    return 0;
}
