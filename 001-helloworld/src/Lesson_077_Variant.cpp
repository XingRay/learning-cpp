//
// Created by leixing on 2024/4/26.
//

#include "Lesson_077_Variant.h"

#include <iostream>
#include <string>
#include <variant>
#include <fstream>

enum ErrorCode{
    OK,
    NOT_EXIST,
    NO_ACCESS,
    UNKNOWN
};

std::variant<std::string, ErrorCode> readFile(const std::string& filePath){
    std::fstream fs(filePath);
    if(fs){
        std::string result = "data ...";
        // read file
        fs.close();
        return result;
    }else{
        return ErrorCode::NOT_EXIST;
    }
}

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

    // 64位处理器
    // 40
    std::cout<< sizeof (std::string )<<std::endl;
    // 4
    std::cout<< sizeof (int )<<std::endl;
    // 48 考虑内存对齐问题
    std::cout<< sizeof (data)<<std::endl;


    auto result = readFile("data.txt");
    if(auto* error = std::get_if<ErrorCode>(&result)){
        std::cout<<"error: "<<*error<<std::endl;
    }else{
        auto content = std::get<std::string>(result);
        std::cout<<"content: "<<content<<std::endl;
    }

    auto result2 = readFile("data2.txt");
    if(auto* error = std::get_if<ErrorCode>(&result2)){
        std::cout<<"error: "<<*error<<std::endl;
    }else{
        auto content = std::get<std::string>(result2);
        std::cout<<"content: "<<content<<std::endl;
    }
}