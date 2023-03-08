```#include <iostream>				//중간이나 기말에 나옴//
using namespace std;
class CMath{
	private: int w,h;
	public:
		CMath(){
			 w=4, h=5;}				//overloading 합수는 중복정의 될수 있다 중복정의 = 매개변수 형,개수//
CMath(int a, int b){
	w=a; h=b;
}
		
		int rect(){
			return (w*h);
		}
		
};
int main(){
	CMath re(20, 30);
	CMath k(8, 16);			//데이터형 뒤에 *를 붙이면 포인터가 된다 포인터느 반드시 초기화되어야한다//
	CMath c;
	CMath* p;
	p = &re;					//주소로서 포인터를 초기화한다//
	cout << k.rect() << endl;
	cout << p->rect() << endl;
	cout << c.rect() << endl;
	return 0;
}
```
```#include <iostream> 
using namespace std;
class Cmath{				//클래스 선언, class 함수 왜씀?  관련있는  데이터와 관련있는  함수를 묶기에 아주 좋다 class member 함수와 class memeber 변수가 있다//
private:					//클래스는 보안성이 있다 private를 사용해서//
int a,b;

public:
Cmath(){a=2; b=2;			//요거시 생성자 특징 : 클래스 이름과 동일한 함수, 초기화를 하기에 적합하다, 생성자는 리턴값이 없다 * 퀴즈시험 1번//
}

int Add(){
return (a+b);}

int Sub(){
	reutnr (a-b);}
};							//클래스 뒤에는 세미콜론//

int main(){
	Cmath me;				//class 정의, class 변수//
	cout << me.Add();
	return 0;
	
}

//두수를 더하는 프로그램을 클래스를 활용하여 작성하시오, 초기값 3,5//
#include <iostream>
using namespace std;
class CMath{
	private: int a, b;
	public:
	CMath(){
		a=3, b=5;
	}
	int add(){
		return (a+b);
	}	
};
int main(){
		CMath me;
		cout << me.add();
		return 0;
	}
  
  
  #include <iostream>
using namespace std;
class CRect{
	private: int w,h;
	public:
	CRect(){
		w=4, h=5;
	}
	int Area(){
		return (w*h);
	}	
};
int main(){
		CRect rect;
		cout << rect.Area();
		return 0;
	}
  ```
