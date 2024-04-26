//
// Created by leixing on 2024/4/25.
//

#include "Lesson_068_VirtualDestructor.h"
#include <iostream>


class Base01 {
public:
    Base01() {
        std::cout << "Base01 Constructor" << std::endl;
    }

    ~Base01() {
        std::cout << "Base01 Destructor" << std::endl;
    }
};

class Derived01 : public Base01 {
public:
    Derived01() {
        std::cout << "Derived01 Constructor" << std::endl;
    }

    ~Derived01() {
        std::cout << "Derived01 Destructor" << std::endl;
    }
};

class Base02 {
public:
    Base02() {
        std::cout << "Base02 Constructor" << std::endl;
    }

    virtual ~Base02() {
        std::cout << "Base02 Destructor" << std::endl;
    }
};

class Derived02 : public Base02 {
public:
    Derived02() {
        std::cout << "Derived02 Constructor" << std::endl;
    }

    ~Derived02() override {
        std::cout << "Derived02 Destructor" << std::endl;
    }
};

void virtualDestructorTest() {
    //Base01 Constructor
    //Base01 Destructor
    Base01 *base01 = new Base01();
    delete base01;

    std::cout << " ----------------- " << std::endl;

    //Base01 Constructor
    //Derived01 Constructor
    //Derived01 Destructor
    //Base01 Destructor
    Derived01 *derived01 = new Derived01();
    delete derived01;

    std::cout << " ----------------- " << std::endl;

    //Base01 Constructor
    //Derived01 Constructor
    //Base01 Destructor
    // 没有调用 Derived01 Destructor , 如果在Derived01中持有堆内存会产生内存泄漏
    Base01 *derived0102 = new Derived01();
    delete derived0102;

    // 解决办法, 将 Base 的 Destruct 声明为 Virtual

    std::cout << " ----------------- " << std::endl;

    //Base02 Constructor
    //Derived02 Constructor
    //Derived02 Destructor
    //Base02 Destructor
     Base02 *derived02 = new Derived02();
    delete derived02;
}
