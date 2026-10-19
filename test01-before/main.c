// 실습 1 수정 전: y는 while 안에서만 유효하므로 바깥의 y = 4에서 오류가 난다.
int main(void)
{
    int flag = 1;

    while (flag != 0)
    {
        int y;
        y = 3;
        flag = 0;
    }

    y = 4;

    return 0;
}
