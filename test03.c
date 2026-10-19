#include <stdio.h>

int inc(int counter);

// 실습 3: 매개변수 counter는 i의 값을 복사받는 별개의 지역변수다.
// 자료의 초기화 누락을 보완해 i = 10으로 시작한다. 호출 전후 모두 10이다.
int main(void)
{
    int i = 10;

    printf("함수 호출전 i=%d\n", i);
    inc(i);
    // 위 문장을 i = inc(i);로 바꾸면 반환값 11이 i에 저장된다.
    printf("함수 호출후 i=%d\n", i);

    return 0;
}

int inc(int counter)
{
    counter++;
    return counter;
}
