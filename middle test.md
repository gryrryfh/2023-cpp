시험
dynamic memory 동적메모리
이것도 코드짜기인가???

static 코드주고 대답하기
#include <iostream>
class MyClass {
public:
    static int count;
    MyClass() {
        count++;
        std::cout << "Created\n";
    }
    ~MyClass() { std::cout << "Dying\n";}
};
int MyClass::count = 0;
int main() {
    MyClass obj1;
    std::cout << MyClass::count << std::endl;
    return 0;
}
요런 느낌??

const==바꾸지마세요 라는뜻

stl에 대해서 vector를 중심으로

c언어와 c++의 차이? 새로운 키워드??
class public private protected new delete,
reinterpret_cast, static_cast, template, namespace

참조에 의한 호출???callbyreference

c++장점들?10가지정도??

두수더하기를 람다함수로 제목 안적고 
auto add = [](int a, int b){return a+b;};

코딩은 후위증가, <<
포인터
템플릿박스
cpoly crect ctri 4문제?
    
    
    단답형
원본을 지적해서 원본과 같이된다?
참조에 의한 호출 

4문1택
local변수를 global변수처럼 사용하는것
1. static 2. stack 3. const 4. dynamic memory

참/거짓
static을 사용할때 생성자와 소멸자는 자동으로 소멸된다

static은 단 한번만 초기화한다.
