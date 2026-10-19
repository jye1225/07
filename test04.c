#include <stdio.h>

void f(void);
int i;

// 실습 4: 두 반복문이 같은 전역변수 i를 사용한다. 결과: # 열 개
// f()가 i를 10으로 만든 뒤 main의 i++로 11이 되어 바깥 반복이 끝난다.
int main(void)
{
    for (i = 0; i < 5; i++)
    {
        f();
    }
    printf("\n");

    return 0;
}

void f(void)
{
    for (i = 0; i < 10; i++)
    {
        printf("#");
    }
}
