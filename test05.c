#include <stdio.h>

void sub(void);

// 실습 5: auto_count는 호출마다 초기화되고 static_count는 값을 유지한다.
// 결과: (auto_count, static_count)가 (1, 1), (1, 2), (1, 3) 순서로 출력된다.
int main(void)
{
    int i;

    for (i = 0; i < 3; i++)
    {
        sub();
    }

    return 0;
}

void sub(void)
{
    int auto_count = 0;
    static int static_count = 0;

    auto_count++;
    static_count++;
    printf("auto_count=%d\n", auto_count);
    printf("static_count=%d\n", static_count);
}
