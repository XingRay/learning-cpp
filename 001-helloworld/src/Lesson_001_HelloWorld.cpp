//
// Created by leixing on 2024/4/26.
//

#include "Lesson_001_HelloWorld.h"

#include <iostream>
#include "Log.h"
#include <array>
#include <string>
#include <Windows.h>
#include <locale>

class Point {
    int x;
    int y;

public:
    void print() {
        std::cout << "{x:" << x << ", y:" << y << "}" << std::endl;
    }
};

class Entity {
    // 默认构造
    // Entity(){}

    // 删除默认构造, 比如用于单例模式,
    // Entity() = delete
public:
    int x;
    int y;
};

// 设置枚举的底层类型
enum Example {
    A = 1,
    B = 2,
    C = 3,
};

class ConstTest {
private:
    int a;
    int b;
    // 允许在常量方法中修改值
    mutable int c;
public:
    int getValue() const {
        c += 1;
        return a + b;
    }
};


void helloWorldTest(){
    SetConsoleOutputCP(CP_UTF8);
    std::locale loc("chs");
//locale loc( "Chinese-simplified" );
    std::wcout.imbue(loc);
    std::locale::global(std::locale(""));

    std::cout << "Hello, World!" << std::endl;
    // '<<' 操作符重载, '<<' 实际上是方法, 类似于 std::cout.print("Hello, World!").print(std::endl);

    int a = 1;
    int b = 10;
    std::cout << "line1" << std::endl;
    std::cout << "line2" << std::endl;

    log("this is log");
    char result[20];
    sprintf(result, "a+b = %d", a + b);
    log(reinterpret_cast<const char *>(result));

    if (b == true) {
        log("b==true");
    } else {
        log("b!=true");
    }

    int c = b + true;
    std::cout << "c:" << c << std::endl;

    Point p;
    int *px = (int *) &p;
    *px = 8;
    p.print();

    Entity entity;
    // error
    // std::cout << entity.x << std::endl;

    std::array<int, 5> nums;
    for (int i = 0; i < nums.size(); i++) {
        nums[i] = i;
    }

    for (const auto &item: nums) {
        std::cout << item << std::endl;
    }

//    std::string str1 = "aa"+"bb";
    std::string str1 = std::string("aa") + "bb";
    std::cout << "str1: " << str1 << std::endl;

    using namespace std::string_literals;
    std::string str2 = "aa"s + "bb";
    std::cout << "str2: " << str2 << std::endl;

    std::string str3 = "测试";
    std::cout << "str3: " << str3 << std::endl;

    const wchar_t *str4 = L"aaabbb";
    std::wcout << "str4:" << str4 << std::endl;

    const wchar_t *str41 = L"中文测试";
    std::wcout << "str41:" << str41 << std::endl;

    const char16_t *str5 = u"aaabbb";
    // 输出 char16_t 类型的字符串
    std::cout << "UTF-16 string: ";
    for (int i = 0; str5[i] != u'\0'; ++i) {
        std::cout << static_cast<char>(str5[i]); // 将 char16_t 转换为 char 输出
    }
    std::cout << std::endl;

    const char32_t *str6 = U"aaabbb";
    // 输出 char32_t 类型的字符串
    std::cout << "UTF-32 string: ";
    for (int i = 0; str6[i] != U'\0'; ++i) {
        std::cout << static_cast<char>(str6[i]); // 将 char32_t 转换为 char 输出
    }
    std::cout << std::endl;

    const char *str7 = R"(---
aaa
bbb
)";
    std::cout << "str7: " << str7 << std::endl;


    // 使用 char 类型输出中文
    std::cout << "这是一段中文文本。" << std::endl;

    // 使用 wchar_t 类型输出中文
    const wchar_t *chineseStr = L"这也是一段中文文本。";
    std::wcout << "chineseStr: " << chineseStr << std::endl;

    setlocale(LC_ALL, "chs");
    std::wcout << L"你好，世界!" << std::endl; // 输出宽字符字符串


    std::wcout << L"中国" << std::endl;
}
