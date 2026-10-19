// 다른 파일의 static 전역변수에는 extern으로 접근할 수 없다.
extern int all_files;

void sub(void)
{
    all_files = 10;
}
