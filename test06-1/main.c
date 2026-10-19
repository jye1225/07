#include <stdio.h>

int all_files;
extern void sub(void);

// 실습 6-1: main.c와 sub.c를 함께 빌드한다. 결과: 10
// sub.c의 extern 선언은 여기서 정의한 전역변수와 연결된다.
int main(void)
{
    sub();
    printf("%d\n", all_files);

    return 0;
}
