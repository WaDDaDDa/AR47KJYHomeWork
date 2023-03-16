#include <iostream>

void EquipPtr(int* _Ptr) // 함수의 인자가 const가 아닐때에는 들어간 인자가 바뀌어서 나올수도 있다는 뜻
{                        // const가 붙은 인자라면 함수가 끝나도 변경되지 않기때문에 바뀌지않을때를
    *_Ptr = 300;         // 서로 사용자가 의도하는 사항에따라 사용할수 있음.
}

void EquipRef(int& _Ref)  // 재설명 하면 값이 들어가서 바뀌길 원할때에는 const를 사용하지 않고
{                         
    _Ref = 200;
}

void TestFunction(const int& _Ref) // 오히려 값이 바뀌지않길 원할땐 const를 사용해주는것이 맞다.
{
    _Ref;
    _Ref = 100;  // const 선언한 인자의 값이 바뀌는 것이므로 오류가 난다.
}

int main()
{
    // 레퍼런스라는 의미

    int Value = 0;
    int Value1 = 20;
    
    // 대부분의 언어에서 참조라는 의미는
    // => 특정 메모리영역의 위치를 가리킨다. 라는뜻.
    
    // 포인터 형 변수
    // 포인터는 언제든지 자신이 가리키고있는 (참조하고있는) 대상을 바꿀수 있다.
    int* Ptr = &Value;
    Ptr = &Value1;  
    
    *Ptr;  // 레퍼런스는 *Ptr == Ref 라고 생각하면된다.
    // 항상 그주소의 비트값을 끌어내서 사용하게 된다.

    // 참조 형 변수.
    // 무조건 누군가를 가리켜야 한다.  int& Ref = Value; 의 선언만하는 형식이 불가능하다.
    int& Ref = Value;
    // 이제부터 Value는 Ref와 동일하게 부르겠다.

    Ref = 100; // Ref == 100 == Value
    // 이러한 특성으로 인해 한번선언해서 참조한 메머리영역을 바꿀수가 없다.

    Ref = Value1; //실행하게되면 Ref == Value == Value1 == 100 의 형태가 아니라.
    // Value1의 값이 들어와서    Ref == Value == 20 의 형태가 되는것.

    {
        int Value0 = 10;
        int Value1 = 20;
        
        int* Ptr = &Value0;
        *Ptr = 100;
        *Ptr = Value1;
        
        // 위의 코드와 아래코드의 뜻은 완전히 동일하다.

        int& Ref = Value0;
        Ref = 100;
        Ref = Value1; 

        // 그렇다면 왜 사용하느냐?
        // 가장 큰 차이는 포인터는 값을 안넣을수있고 == nullptr
        // 레퍼런스는 그것이 불가능하다. 선언할때 반드시 참조할 대상을 같이 선언해야한다.

        // 예를 들어 장비를 장착한다고 할때
        // 장비를 끼고있는 상태와 해제하는 상태가 있을수있는데. 그것을 표현할때는 포인터의
        // nullptr이 가능한데 Ref는 용이하지않다.

        EquipPtr(nullptr); // 가능하지만
        EquipRef(10); // 해당 함수의 인자는 int형이지만 10은 const int 형이므로 오류가 난다.

        int itemEquip = 0; //을 선언하고
        EquipRef(itemEquip); // 절대로 값을 비워 놓을수 없다 라는 형식을 의도할때 Ref사용한다.

        TestFunction(2000);

        // 레퍼런스의 메모리 크기
        // 포인터의 경우 어떤 포인터이건 8바이트의 크기이다.
        // 레퍼런스도 기본 8바이트의 크기는 맞으나.
        int Value = sizeof(Ref); // 풀어쓰면 sizeof(*Ptr)인 것이므로 sizeof(int)로 4바이트를 출력.
        Value = sizeof(Ptr); // 8바이트
        
        EquipRef(nullptr);
    }

    // 정리 레퍼런스는 Ref == *Ptr로 이해하며, 선언시에 반드시 가리키는 곳을 같이 지정해 주어야한다.
    // nullptr을 가리킬수는 없다.
} 
