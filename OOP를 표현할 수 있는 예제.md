## 도형 클래스 CPoly로부터 두 정수를 상속 받고, 면적 계산하는 과정을 함수 오버라이딩을 통해 다형성(Polymorphism) 을 구현하고 사각형의 가로 세로를 변수로 가지는 클래스를 정의하고, 가로와 세로 값을 출력하는 << 오퍼레이터를 오버로딩 하시오.
```
#include<iostream>
#define PI 3.14
using namespace std;
class CPoly{
    protected:
        int w,h;
    public:
        virtual double Area() = 0;
};
class CRect:public CPoly{
    public:
        template <typename T>
        CRect(T _w, T _h){
            w=_w, h=_h;
        }
        double Area(){
            return wh;
        }
        friend ostream& operator<<(ostream &os, CRect &r){
            os<< r.w << "," << r.h;
            return os;
        }
};
class CCircle:public CPoly{
    public:
        CCircle(int _w){
            w=_w;
        }
        double Area() {
            return ww*PI;
        }

};
int main(){
    CRect r1(3,4);
    CCircle c(3);
    cout << r1 << endl;
    cout << r1.Area() << endl;
    cout << c.Area() << endl;
}
```
