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
```c++
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
```c++
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
```c++
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
```c++
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

[4문1택] 객체 지향 프로그래밍 특징 중 틀린 것은?
답) 4

1. 추상화

2. 캡슐화

3. 정보 은닉

4. 유지성

​

[참/거짓]

protected는 누구나 사용이 가능하다

답) 거짓
​

[단답형]

클래스 안에 데이터와 함수를 묶어 객체로 만드는 것은?

답) 캡슐화

2023.04.19. 15:11 답글쓰기
프로필 사진
천준영
[4문 1택] 상속 관계에 있는 클래스에서 부모 클래스의 함수를 자식 클래스에서 다시
정의하는 것을 무엇이라고 하는가?
1. 오버로딩
2. 오버라이딩
3. 캡슐화
4. 상속
답) 오버라이딩

[참/거짓]
C++에서 private로 명시된 변수는 외부의 함수에서 사용가능 하다.
답) 거짓

[단답형]
C++ 언어에서 여러 개의 같은 이름을 가진 함수를 정의하되
매개변수의 개수, 타입, 또는 const 속성이 다른 경우에 서로 다른 함수로
인식되도록 하는 기능을 무엇이라고 하는가
답) 오버로딩

2023.04.19. 15:25 답글쓰기
프로필 사진
양용석
[4문 1택]

다음 중 종류가 다른 키워드는?

1. public:
2. private:
3. template
4. protected:

정답 : 3

[참/거짓]

'static' 키워드가 사용될 때는, 해당 함수가 선언된 파일 안에서만 사용 가능하며, 다른 파일에서는 호출할 수 없다.

정답 : T

[단답형]

[#] 다음에 선언된 멤버는 클래스 외부에서도 접근 가능하다.

정답 : public:

2023.04.19. 15:40 답글쓰기
프로필 사진
박형민
[4문1택] 생성자의 특징으로 옳바르지 않은것은?
답) 4

1. 초기화의 역활을한다.
2. 리턴값이 없다.
3. 오버로딩 할 수 있다.
4. 오버로딩 할 수 없다.


[참/거짓]
클래스는 보안성이 없다.

답) 거짓


[단답형]
클래스이름과 동일한 함수는?

답) 생성자

2023.04.19. 15:36 답글쓰기
프로필 사진
최성욱
[4문 1택]

C++를 학습해야 하는 이유에 맞지 않은 제목은?

1) 다중 패러다임 지원
2) 제네릭 프로그래밍
3) 표준 템플릿 라이브러리
4) 동적 타입 시스템

답 4 c++은 정적 타입 시스템을 사용함

[참/거짓]

Friend 함수는 클래스의 멤버 함수가 아니지만, 해당 클래스의 멤버 함수에 접근할 수 있는 함수나 클래스를 의미합니다.

답: 참

[단답형]

다음 코드는 실행시 오류가 나는데 어떤 코드를 입력하거나 혹은 수정해야 하는가?

#include <iostream>

int main() {
int a = 10;
int b = 20;
int sum = a + b;
cout << "The sum of " << a << " and " << b << " is " << sum << endl;
return 0;
}

답: std::cout << "The sum of " << a << " and " << b << " is " << sum << std::endl; 혹은 using namespace std;

2023.04.19. 15:52 답글쓰기
프로필 사진
지은
(4문 1택)

부모 클래스가 자식 클래스에 자신의 맴버 변수를 사용할 수 있게 하는것은?
1. private 2. public 3. default 4. protected
답: 4. protected


(참/거짓)

소멸자는 클래스의 이름 앞에 !를 붙이면 된다.
답 : 거짓

(단답형)

C++ 표준 입출력 라이브러리는 [#]이다.
정답) <iostream>

2023.04.19. 15:54 답글쓰기
프로필 사진
김진원
(4문1택) C++언어의 특징이 아닌 것은 ?
(1) 추상화 (2) 정보은닉 (3)스크립트언어 (4) 다형성
답:(3)

(참/거짓)
ostream override에서 friend ______ operator << (_____ os, CMy p) {
의 빈칸에는 ostream 이 들어간다.
답:거짓 (ostream& 이 들어감)

(칸 메우기)
다음 로컬변수를 글로벌변수로 바꿔라 ______ int x=0;
답:static

2023.04.19. 15:59 답글쓰기
프로필 사진
cpp황찬영
[단답형]
STL의 중요한 데이터 구조가 아닌것은?
1. vector
2. list
3. map
4. templete
답) 4번

[참/거짓]
상속은기존클래스의속성과메서드를새로운클래스에전달하는기능으로, 코드의재사용성을높인다.
답) 참

[단답형]
클래스의 이름과 동일한 함수이며, 초기화가 가능하고, return 값이 없으며, 오버로딩이 가능한 것의 이름은?
답) 생성자

2023.04.19. 16:02 답글쓰기
프로필 사진
20211083김홍빈
[4문 1택]

다음 보기 중, C언어에는 없는 C++언어의 키워드가 아닌 것은?

1. include

2. class

3. namespace

4. using

답: 1번



[참/거짓]

람다 함수를 사용하는 이유 중 하나는 익명이 아니기 때문이다

답: 거짓



[단답형]

아래 코드에 들어갈 키워드는?



#include<iostream>
using namespace std;

class CPoly{

protected:

int w, h;

public:

_______ int Area() = 0;

};



class CRect: public CPoly{

public:

CRect(int a, int b){w=a; h=b;}

int Area() override {return(w*h);}
};



class CTri: public CPoly{

public:
CTri(int a, int b){w=a; h=b;}

int Area() override {return(w*h);}

};



int main(){

CRect r(4,3);

CTri t(4,3);

CPoly* p=NULL;

p=&r; cout << p->Area() << endl;

p=&t; cout << p->Area() << endl;

}



답: virtual

2023.04.19. 17:02 답글쓰기
프로필 사진
컴공이동현
1. [서술형] 두 코드의 출력 결과를 각각 쓰고, 위 코드에서 정적 변수의 역할에 대해 짧게 서술하시오.
#include <iostream>
using namespace std;
void Foo(){
int a=0;
cout << ++a << "\n";
}
int main()
{
Foo();
Foo();
}
#include <iostream>
using namespace std;
void Foo(){
static int a=0;
cout << ++a << "\n";
}
int main()
{
Foo();
Foo();
}
답 : 1 1
1 2
static 정적 변수는 변수를 한 번만 초기화하기 때문에 Foo()를 두 번 호출하여도 a가 초기화되지 않고 ++a로 a를 1 증가시켜 다음과 같이 1 2의 출력 결과가 나옴.

2. [서술형] 위 코드를 call by address 형태로 수정하시오.
#include <iostream>
using namespace std;
void Foo(int a){
printf("Foo:%p\n", &a);
a = a + 10;
}
int main()
{
int a = 5;
printf("Main:%p\n", &a);
Foo(a);
cout << a;
return 0;
}
답 :
#include <iostream>
using namespace std;
void Foo(int *a){
printf("Foo:%p\n", a);
*a = *a + 10;
}
int main()
{
int a = 5;
printf("Main:%p\n", &a);
Foo(&a);
cout << a;
return 0;
}

3. [참/거짓] dynamic_cast는 컴파일 타임에 타입 변환을 수행하는 가장 일반적인 캐스팅 방법이며, 기본 데이터 타입 간의 변환(예: int에서 float로 변환)이나 상속된 클래스와 파생 클래스 사이의 포인터 변환에 사용된다.
답 : 거짓, 위의 타입 캐스팅은 static_cast에 대해 설명하고 있음.

2023.04.19. 18:48 답글쓰기
프로필 사진
추승범
(4문1택)다음과 같이 동적으로 배열을 선언했을 때 int *arr = new int[size];
동적으로 할당된 메모리를 해제하는 방법은?

1) delete arr;
2) delete[] arr;
3) free arr;
4) free(arr);

답 : 2)

(참/거짓)const는 타입 앞에 써서 변수를 초기화하면 값이 변하는 것을 막아준다.
답 : 참

(단답형)다음 코드에서 소멸자를 선언하는 기호를 채우시오.
#include <iostream>
class MyClass {
public:
static int count;
MyClass() {
count++;
std::cout << "Created\n";
}
1.__MyClass() { std::cout << "Dying\n";}
};
int MyClass::count = 0;
int main() {
MyClass obj1;
std::cout << MyClass::count << std::endl;
return 0;
}

답 : ~(틸트)

2023.04.19. 20:27 답글쓰기
프로필 사진
20180684 오예준
[4문 1택] C언어와 다른 C++의 특징으로 틀린 것을 고르시오

1) 추상화

2) 캡슐화

3) 함수

4) 다형성

답 : 3
[참/거짓] C++ 에서는 C언어의 문법을 사용할 수 없다

답 : 거짓



[단답형] 상수를 선언하는 키워드는 [] 다

답 : const

2023.04.19. 20:29 답글쓰기
프로필 사진
이재경
[4문1택] C언어와 비교했을 때 C++의 차이점 중 옳지 않은것은?

1. 객체지향프로그래밍 언어다.
2. 클래스를 상속받아 새로운 클래스를 정의할 수 있다.
3. 연산자 오버로딩이 가능하다.
4. 변수, 상수, 포인터, 배열등을 제공한다.

답) 4. 변수, 상수, 포인터, 배열 모두 C언어와 C++에서 모두 지원한다.



[참/거짓]

static변수는 단 한번만 초기화한다.

답) 참



[단답형] [#]은 C++ 표준 라이브러리 중 하나로, 자료구조와 알고리즘을 템플릿 클래스로 제공한다.

자료구조와 알고리즘을 간단하고 효율적으로 구현할 수 있으며, 코드의 가독성, 생산성, 유지보수성 등이 대폭 향상된다.

답) STL
