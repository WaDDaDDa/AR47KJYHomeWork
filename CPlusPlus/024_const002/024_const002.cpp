#include <iostream>

int main()
{
    {
        const int;  // 그자체로 새로운 자료형
        int; // 둘이 서로 다른 자료형이다.

        int Value = 10;
        int Value1 = 10;
        int* Ptr = &Value;

        const int* cPtr = &Value;  // (const int)* cPtr 과 같다.

        // const int* 변수가 사용할때 *을 붙인다는것은
        // 자신의 자료형에서 *을 뺀 자료형으로 사용하겠다는 뜻이다.
        // ex) *Ptr 
        // Ptr == const int*
        // *Ptr == const int 
        *cPtr = 20; // 그래서 수정이 불가능하다.

        //  * 를 기점으로  오른쪽과 왼쪽으로 본다.
        const int* cptr = &Value1;
        // * 뒤에 뭔가를 붙이는건 이제부터 *에 영향을 주는것이다.


        //번외
        const int ValueTTT = 10;  // 완전히 동일한 코드이다.... 앞뒤 관계없이.
        int const ValueTT1 = 10;  // 보기 좋게 그냥 앞에 const 붙여서 사용하는것으로 통일하자.
    }

    {
        // 100번지에 있는 'A'
        char Test0 = 'A';
        // 110번지에 있는 'B'
        char Test1 = 'B';
        // 120번지에 있는 100번지
        const char* Chr = &Test0;

        Chr = &Test1; // 변경이 가능하다. 100번지에 있는 값을  const화 해서 100번지는 변경 가능.
        // const char
        *Chr = 'C';  // 변경이 불가능하다. 100번지에 있는 값을 const화 해서 그 값의 변경이 불가능. 
        Chr = &Test1;

        // 다른애를 Reference 처럼 못가리키게 하고싶을때,
        // 100번지를 200번지로 못바꾸게 하고싶을때.
        // 100번지를 const화 시키는것.
        char* const CCh = &Test0; // 을 사용하여 값은 바꿀수있지만 주소는 못바꿈.

        const char* const CCCH = &Test0; // 값도 못바꾸고 주소도 못바꿈.

        //  왼쪽 : 자료형   *을기점으로  const 유: 주소값을 바꾸지않겟다.  무: 주소값 바꿀수있다.
        // const char        *    const     CCCH = &Test0;

    }


}
