* 상속도 나옴
* stl의 소팅?
* 함수의 포인터
``` C++
#include <iostream>
using namespace std;
int add(int a, int b) {
    return a + b;
}
int main() {
    int (*pAdd)(int, int) = add;
    int a = 2, b = 3;
    cout << pAdd(a, b) << endl;
    return 0;
}
```
* 람다함수
 ```C++
 #include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    vector<int> nums = {3, 2, 5, 1, 4};
    sort(nums.begin(), nums.end(), [](int a, int b) {
        return a < b;
    });
    for(auto n : nums) {
        std::cout << n << " ";
    }
    return 0;
}
```
* 기말 예상문제: 1) https://www.w3schools.com/cpp/  퀴즈, Exercises 2문항/25, Exercesis 3문항
* 전처리기의 종류를 5가지 이상 기억(#include, #define, #elif, #endif, ???)
* 퀵정렬
for_each도 무조건 나옴
* 바인딩 무조건 나옴
```
#include <iostream>
#include <vector>
#include <algorithm> // for std::transform

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::vector<int> result(nums.size());
    
    std::transform(nums.begin(), nums.end(), result.begin(), [](int x) {
        return x * x;
    });
    
    for (int i : result) {
        std::cout << i << " ";
    }

    return 0;
}
```
* 삼각형 사각형 도형에서 상속받는 순수가상함수 무조건 무조건 나옴
```
#include<iostream>
using namespace std;
class CPoly {
		int h, w;
	public:
		virtual int Area()=0;
};
class CRect: public CPoly {
	public:
		CRect() {
			w = 2;
			h = 3;
		}
		int Area() {
			return (a*b);
		}
};
class CTry: public CPoly {
	public:
		CTry() {
			w = 2;
			h = 3;
		}
		int Area() {
			return (a*b/2);
		}
};
int main() {
	CRect r;
	CTri t;
	CPoly *p = &r;
	cout << p->Area() <<endl;
	p = &t;
	cout << p->Area() <<endl;
}
```
* C++언어와 경쟁이 되는 언어들
Rust: Rust는 안전성, 병행성 및 성능에 중점을 둔 시스템 프로그래밍 언어입니다. C++의 일부 문제를 해결하고자 설계되었으며, 메모리 안전성, 스레드 안전성 및 높은 성능을 강조합니다.

Go: Go는 간단하고 가독성이 높은 문법을 가지며, 효율적인 병행성을 제공하는 프로그래밍 언어입니다. C++보다 간단한 문법과 간결한 코드를 제공하여 개발자 생산성을 높이는데 초점을 맞추고 있습니다.

Swift: Swift는 애플의 iOS 및 macOS 애플리케이션 개발을 위해 설계된 프로그래밍 언어입니다. C++와 비교하여 보다 간결하고 안전한 문법을 제공하며, 빠른 컴파일 속도와 효율적인 성능을 갖추고 있습니다.

Kotlin: Kotlin은 안드로이드 애플리케이션 개발을 위한 공식적인 언어로서 인기가 높아지고 있습니다. C++와 비교하여 더 간결하고 가독성이 높은 문법을 가지며, 자바와의 상호 운용성을 제공합니다.

* 템플릿도?
* 소팅 안나옴 대신 람다함수쓰는 소팅 나옴
* 


