//
// Created by leixing on 2024/4/26.
//

#include "Lesson_075_struct_binding.h"
#include <tuple>
#include <string>
#include <iostream>

class Person {
public:
    std::string name;
    int age;

    Person(std::string name, int age):name(name), age(age){}
};

std::tuple<std::string, int> createPerson() {
    return {"AAA", 12};
}

Person createPerson2() {
    return {"BBB", 14};
}



void structBindingTest() {
    // 使用tuple, 比较麻烦
    std::tuple<std::string, int> person01 = createPerson();
    std::string& name = std::get<0>(person01);
    int age = std::get<1>(person01);
    std::cout << "name: " << name << " age:" << age << std::endl;

    // 使用 class/struct , 需要定义
    Person person02 = createPerson2();
    std::cout << "name2: " << person02.name << " age2:" << person02.age << std::endl;

    // 使用 tie
    std::string name3;
    int age3;
    std::tie(name3, age3) = createPerson();
    std::cout << "name3: " << name3 << " age3:" << age3 << std::endl;

    // 使用结构化绑定, 类似于js的解构表达式
    auto [name4, age4] = createPerson();
    std::cout << "name4: " << name4 << " age4:" << age4 << std::endl;

}