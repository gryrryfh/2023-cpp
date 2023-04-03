## 도형 클래스 CPoly로부터 두 정수를 상속 받고, 면적 계산하는 과정을 함수 오버라이딩을 통해 다형성(Polymorphism) 을 구현하고 사각형의 가로 세로를 변수로 가지는 클래스를 정의하고, 가로와 세로 값을 출력하는 << 오퍼레이터를 오버로딩 하시오.
```
#include<iostream>
#define PI 3.14
using namespace std;
class CPoly{  //클래스 CPoly, 추상 클래스 
    protected:
        int w,h;
    public:
        virtual double Area() = 0; // 순수가상함수 - 상속받는 자식클래스에 사용 안할경우 에러가 뜸   
};
class CRect:public CPoly{  //CPoly를 상속받은 클래스 CRect, w,h변수를 사용할 수 있다 
    public:
        CRect(int _w, int _h){
            w=_w, h=_h;
        }
        double Area(){ //오버라이딩 - CPoly 클래스에서 상속받은 Area() 함수 재정의
            return w*h;
        }
        friend ostream& operator<<(ostream &os, CRect &r){  //friend함수  -클래스 외부에서 private변수에 접근하도록 허용  
            os<< r.w << "," << r.h;//연산자 오버로딩 - << 연산자를 CRect 클래스에서 재정의
            return os;
        }
};
class CCircle:public CPoly{ //CPoly를 상속받은 클래스 CCircle w,h변수를 사용할 수 있다 
    public:
        CCircle(int _w){
            w=_w;
        }
        double Area() { //오버라이딩-CPoly 클래스에서 상속받은 Area() 함수 재정의
            return w*w*PI;
        }

};
int main(){
    CRect r1(3,4);
    CCircle c(3);
    cout << r1 << endl;  // stream 객체 사용 
    cout << r1.Area() << endl;
    cout << c.Area() << endl;
}
```

### 설명
#### 1. 클래스: CRect, CCircle, CPoly
C++의 객체 지향 프로그래밍(OOP)은 클래스를 기반으로 합니다.
클래스는 객체를 만들기 위한 설계도와 같은 역할을 합니다.
위 코드에서 CRect, CCircle, CPoly는 클래스입니다.
#### 2. 상속 (Inheritance)
클래스는 다른 클래스에서 속성과 기능을 물려받을 수 있습니다.
위 코드에서 CRect와 CCircle 클래스는 CPoly 클래스를 상속받았습니다.
CRect와 CCircle 클래스는 CPoly 클래스에서 상속받은 w,h 변수를 사용할 수 있습니다.
#### 3. 가상 함수 (Virtual Functions)
가상 함수는 런타임 시점에 함수를 찾아가는 데 사용됩니다.
위 코드에서 CPoly 클래스의 Area() 함수는 가상 함수로 선언되어 있습니다.
이를 통해 CRect와 CCircle 클래스에서 Area() 함수를 다양하게 구현할 수 있습니다.
#### 추상 클래스 (Abstract Class)
CPoly 클래스는 순수 가상 함수인 Area() 함수를 가지고 있으며, 이를 통해 CPoly 클래스는 추상 클래스입니다.
추상 클래스는 객체를 직접 만들 수 없으며, 다른 클래스에서 상속하여 사용해야 합니다.
#### 오버라이딩 (Overriding)
상속받은 함수를 자식 클래스에서 재정의할 수 있습니다.
위 코드에서 CRect와 CCircle 클래스는 CPoly 클래스에서 상속받은 Area() 함수를 재정의하였습니다.
#### 우선순위 (Scope Resolution Operator)
:: 연산자를 통해 전역 변수 또는 함수를 사용할 수 있습니다.
위 코드에서 PI는 전역 변수이며, :: 연산자를 통해 사용되었습니다.
#### 스트림 (Stream)
입출력을 할 때 사용하는 스트림 객체를 제공합니다.
위 코드에서는 cout 객체를 사용하여 출력을 하였습니다.
#### 연산자 오버로딩 (Operator Overloading)
클래스에 새로운 의미를 부여하기 위해 연산자를 재정의할 수 있습니다.
위 코드에서는 << 연산자를 CRect 클래스에서 재정의하여 사용하였습니다.
#### friend 함수
클래스 외부에서 private 변수에 접근할 수 있도록 허용합니다.
위 코드에서 << 연산자 함수는 CRect 클래스의 friend 함수로 선언되어 있으며, CRect 클래스의 private 변수에 접근할 수 있습니다.


