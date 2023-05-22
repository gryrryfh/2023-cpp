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
