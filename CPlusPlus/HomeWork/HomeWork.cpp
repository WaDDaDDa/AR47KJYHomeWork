
#include <iostream>

// 영어만 씁니다.

// 문자열을 넣어주면 글자 개수를 알아냅니다.
// 0을 포함할지 아닐지는 스스로 정하세요

int StringCount(const char* _String)  // 완성.
{
    int count = 0;

    while (0 != _String[count])
    {
        char A = _String[count];
        count++;
    }
    
    count++;
    return count;
}

int TrimDelete(char* _String)  // 완성.  띄어쓰기를 지워주는 함수.
{
    int count = 0;

    while (0 != _String[count])
    {
        char A = _String[count];
        if (' ' == A)
        {
            count++;
        }
        else
        {
            putchar(A);
            count++;
        }
    }

    return 0;
}

int StringToInt(const char* _String)  // 숫자로된 문자열을 int로 변환해주는 함수.
{
    
    int num = 0;
    int count = 0;
    while (_String[count] != 0)
    {
        int Anum = _String[count];
        num = num * 10 + (Anum - '0');  // 아스키코드상 '0'을뺀다면 그 수에 해당하는 int
        count++;                              // int값이 나오는 것을 이용.
    }                                // ex) '1'은 아스키 코드상  49 '0'은 48 이므로
                                       // 49-48 = 1  이된다.
    return num;
}
// 다른 방식의 작성은 가능할까?

int StringToInt2(const char* _String)
{
    int count = 0;

    return 0;
}


int main()
{
    int Return0 = StringCount("abcdef");
    int Return1 = StringCount("aaaa ggg sss");

    char Arr0[1024] = "a b c d e";
    char Arr1[1024] = "a    b c    d    e";
    char Arr2[1024] = "ab    cde    ";

    TrimDelete(Arr0);
    printf_s(Arr0);
    TrimDelete(Arr1);
    printf_s(Arr1);
    TrimDelete(Arr2);
    printf_s(Arr2);

    // 영어나 다른글자가 섞여 들어가있는것을 가정하지 않는다.
    int RValue0 = StringToInt("1234"); // RValue0 에 1111이 들어가야함.
    int RValue1 = StringToInt("432");
    int RValue2 = StringToInt("4523312");
    int RValue3 = StringToInt("432231");

}
