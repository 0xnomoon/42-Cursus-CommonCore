#include "Array.hpp"
#include <string>

int main()
{
    try {
        Array<int> intArr;
        intArr[0] = 10;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    Array<float> floatArr(10);
    int size = floatArr.size();
    for (int i = 0; i < size; ++i)
        floatArr[i] = static_cast<float>(i) * 2;
    std::cout << floatArr << std::endl;

    Array<std::string> stringArr(4);
    stringArr[0] = "ab";
    stringArr[1] = " cd";
    stringArr[2] = " e";
    stringArr[3] = " fg";
    std::cout << stringArr << std::endl;

    try {
        stringArr[10] = " yyyyy";
        std::cout << stringArr << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}