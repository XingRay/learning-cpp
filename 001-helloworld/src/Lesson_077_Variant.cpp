//
// Created by leixing on 2024/4/26.
//

#include "Lesson_077_Variant.h"

#include <iostream>
#include <string>
#include <variant>

void variantTest() {
    std::variant<std::string, int> data;
    data = 2;
    // data.index() 返回 数据的类型 在声明列表 <std::string, int> 中的下标, 这里 string是0 int 是 1
    std::cout << data.index() << std::endl;
    if (data.index() == 0) {
        // index == 0 说明是string
        std::cout << "data: " << std::get<std::string>(data) << std::endl;
    } else if (data.index() == 1) {
        // index == 1 说明是 int
        std::cout << "data: " << std::get<int>(data) << std::endl;
    }

    // 转换错了会包异常, 可以使用try-catch

    // get_if
    std::string *p = std::get_if<std::string>(&data);
    if (p != nullptr) {
        std::cout << "data: " << *p << std::endl;
    } else {
        std::cout << "data: is not string" << std::endl;
    }

    data= "test_string";
    // 简单写法
    if(auto* p = std::get_if<std::string>(&data)){
        std::cout << "data: " << *p << std::endl;
    }

    // variant 的内存占用
    // variant 不同于 union, variant 中每个数据是单独保存的
    std::cout<< sizeof (std::string )<<std::endl;
    std::cout<< sizeof (int )<<std::endl;
    std::cout<< sizeof (data)<<std::endl;
}