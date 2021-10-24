#pragma GCC diagnostic error "-std=c++14"

#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    try {
        for (int j = 0; j < 15; ++j) {
            static int i = 3; //位置
            //逆推 i = i - i / 3
            int temp = i;
            i = 3 * i / 2;
            if (!(i % 3) && i - i / 3 == temp) {
                cout << i << " ";
            } else {
                ++i;
                if (!(i % 3) && i - i / 3 == temp) {
                    cout << "\b[" << i << "]";
                    continue;
                }
                i -= 2;
                if (!(i % 3) && i - i / 3 == temp) {
                    cout << "\b<" << i << ">";
                    continue;
                }
                throw runtime_error(to_string(temp) + "reverse i = i - i / 3");
            }
            //逆推 i = i - i / 2
            temp = i;
            i = 2 * i - 1;
            if (!(i % 2) && i - i / 2 == temp) {
                cout << i << " ";
            } else {
                ++i;
                if (!(i % 2) && i - i / 2 == temp) {
                    cout << "\b[" << i << "]";
                    continue;
                }
                i -= 2;
                if (!(i % 2) && i - i / 2 == temp) {
                    cout << "\b<" << i << ">";
                    continue;
                }
                throw runtime_error(to_string(temp) + "reverse i = i - i / 3");
            }
        }
    } catch (runtime_error &e) {
        cout << endl << "an error occurred at i = " << e.what();
    }
}