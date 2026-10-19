#include <stdio.h>

static int all_files;
extern void sub(void);

// 실습 6-2: main.c와 sum.c를 함께 빌드하면 링크 오류가 나는 것이 예상 결과다.
// static 때문에 이 변수는 main.c 안에서만 연결되며 다른 파일에 공개되지 않는다.
int main(void)
{
    sub();
    printf("%d\n", all_files);

    return 0;
}
