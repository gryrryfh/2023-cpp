시험
dynamic memory 동적메모리
이것도 코드짜기인가???
```
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
```

const==바꾸지마세요 라는뜻

stl에 대해서 vector를 중심으로

```
c언어와 c++의 차이? 새로운 키워드??
class public private protected new delete,
reinterpret_cast, static_cast, template, namespace
```
	
```
참조에 의한 호출???callbyreference
```
	
```
c++장점 5가지이상
```

```
코딩은 후위증가, <<
abstract overloading
```

```
템플릿박스
```
	
```
cpoly crect ctri 4문제?
``` 

```
	##### 람다함수 두수더하기를 람다함수로 제목 안적고 
auto add = [](int a, int b){return a+b;};
    #include <iostream>
using namespace std;
int main(){
	auto add=[](int a, int b)-> int { //특히 요부분
	return a+b;
	};
	int result =add(3,4);
	cout << "3+4="<<result<<endl;
	return 0;
	}
```

```
 crect포인터를 써서
CRect* p = new CRect(3,4);
```
	
```
stl의 장점 5가지
유연성, 표준화, 생산성 향상, 코드 재사용성, 성능향상
```
	
```
stl의 주요 구성요소 3가지
1. 컨테이너, 2. 알고리즘, 3. 반복자
```
```
static 
```
```
const
```
코딩 4문제
아닌거 10문제
10문제중 영어문항 w3c 50문항중 2문항
나머지 8
