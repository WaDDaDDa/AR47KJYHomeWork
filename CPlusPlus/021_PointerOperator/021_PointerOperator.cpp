
#include <iostream>

void ValueChangePtr(int* Ptr) // 2번) 100번지 위치의 주소값을 가진다.
{
	*Ptr = 0; // 3번) 100번지 주소에 있는 비트값 10에 0을 넣어라.
}

void ValueChangeValue(int Ptr)  // 1-2번) 100번지의 비트값 10이 들어가게 되고
{
	Ptr = 0;  // 1-3번) 10 = 0 의 의미없는 처리를 하고 마치게 된다.
}


int main()
{

	// 100번지라고 가정
	int Value = 10;   // 100번지에 있는주소에 10의 비트값을 넣는다.
	
	// 번호붙은 순서대로 해석 해보기
	// 1번의 결과가 반영되지 않는다고 생각하고 1-1번해석에 유념할것.
	ValueChangePtr(&Value); // 1번) ValueChagePtr 함수를 실행
	
	ValueChangeValue(Value); // 1-1번) ValueChangeValue 함수를 실행

	int* Ptr = &Value;

	// 이중 포인터
	// 포인터의 포인터 (주소의 주소)
	// 10의 비트값을 가지는 포인터의 주소값 (주소값을 가진것의 주소값)
	
	int** PtrPtr = &Ptr;

	// Value의 주소값을 가지고있는 Ptr의 주소값을 가지고있는 PtrPtr
	//  10      '100번지'        100번지   '120번지'         120번지     

}
