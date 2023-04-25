시험
문제 코딩4문제+그외 8문제
코딩 4문제

#### 1.cpoly crect ctri 포인터

```
 crect포인터를 써서
CRect* p = new CRect(3,4);
```
	

#### 2.템플릿박스
```c++
#include <iostream>

using namespace std;

template<typename T>
class Box {
public:
    Box(T value) : value(value) {}

    T getValue() const {
        return value;
    }

private:
    T value;
};

int main() {
    Box<int> intBox(42);
    Box<double> doubleBox(3.14);
    Box<string> stringBox("Hello, World!");

    cout << "Integer box: " << intBox.getValue() << endl;
    cout << "Double box: " << doubleBox.getValue() << endl;
    cout << "String box: " << stringBox.getValue() << endl;

    return 0;
}
```
#### 3.오퍼레이터overloading
```
#include <iostream>

using namespace std;

class CPnt {
public:
    CPnt(int x = 0, int y = 0) : x(x), y(y) {}

    friend ostream& operator<<(ostream& os, const CPnt& p);
    friend istream& operator>>(istream& is, CPnt& p);

private:
    int x, y;
};

ostream& operator<<(ostream& os, const CPnt& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

istream& operator>>(istream& is, CPnt& p) {
    is >> p.x >> p.y;
    return is;
}

int main() {
    CPnt p1(3, 4);
    cout << "Point 1: " << p1 << endl;

    CPnt p2;
    cout << "Enter x and y for Point 2: ";
    cin >> p2;
    cout << "Point 2: " << p2 << endl;

    return 0;
}
```
#### 4.생성자함수오버로딩
```
#include <iostream>
using namespace std;
int op(int a, int b)
{
  return (a+b);
}
double op(double a, double b)
{
  return (a-b);
}
int main ()
{
  int x=5,y=2;
  double n=5.0,m=2.0;
  cout << op(x,y) << '\n';
  cout << op(n,m) << '\n';
  return 0;
}
```
나머지 8문제

#### 1.참조에 의한 호출
```
#include<iostream>
void Foo(int& a){
	a = a + 100;
}
int main(){
	int a = 5;
	Foo(a);
	std::cout << a;
}
```
#### 2.const, dynamic memory
```
#include <iostream>

int main() {
    // 동적 배열 크기
    const int size = 5;

    // 동적 배열을 생성합니다.
    int *arr = new int[size];

    // 배열에 값을 할당합니다.
    arr[0] = 1;
    arr[1] = 3;
    arr[2] = 2;
    arr[3] = 5;
    arr[4] = 4;

    // 배열의 합을 계산합니다.
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }

    // 합을 출력합니다.
    std::cout << "배열의 합: " << sum << std::endl;

    // 동적으로 할당된 메모리를 해제합니다.
    delete[] arr;

    return 0;
}
```
#### 3.stl의 예제 
```
const==바꾸지마세요 라는뜻
stl에 대해서 vector를 중심으로
stl의 주요 구성요소 3가지
1. 컨테이너, 2. 알고리즘, 3. 반복자
```

#### 4.c++의 장점 10가지
```
높은 성능: C++은 높은 성능을 가지는 언어로, 컴파일러를 통해 기계어로 변환되므로 실행 속도가 빠릅니다.

메모리 제어: C++은 메모리를 직접 제어할 수 있어 메모리를 효율적으로 사용할 수 있습니다.

객체 지향 프로그래밍: C++은 객체 지향 프로그래밍을 지원하므로 코드를 모듈화하여 유지보수와 재사용성을 높일 수 있습니다.

다중 상속: C++은 다중 상속을 지원하여 여러 부모 클래스에서 상속받을 수 있습니다.

표준 라이브러리: C++에는 표준 라이브러리가 내장되어 있어 유용한 기능들을 쉽게 사용할 수 있습니다.

저수준 제어: C++은 하드웨어를 직접 조작할 수 있는 저수준 제어가 가능합니다.

이식성: C++은 운영체제와 하드웨어에 종속되지 않으므로 이식성이 높습니다.

대용량 데이터 처리: C++은 대용량 데이터를 처리하는 데 효과적입니다.

컴파일러와 연동: C++은 컴파일러와 직접 연동할 수 있는 기능이 있어 코드의 최적화나 디버깅이 용이합니다.

무료 오픈소스: C++은 무료이며, 오픈소스로 공개되어 있어 개발자들이 함께 개발하고 개선할 수 있습니다.
```

#### 5.c++에서 c언어에 없는 키워드
```
c언어와 c++의 차이? 새로운 키워드??
class public private protected new delete,
reinterpret_cast, static_cast, template, namespace
```

#### 6.람다add와 add의 차이

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



#### 7.stl의 주요 구성요소
```
stl의 장점 5가지
유연성, 표준화, 생산성 향상, 코드 재사용성, 성능향상
```
#### 8.static??????
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
```


