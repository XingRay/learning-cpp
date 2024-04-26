//
// Created by leixing on 2024/4/26.
//

#include "Lesson_076_Optional.h"
#include <iostream>
#include <fstream>
#include <optional>

/**
 * 读取文件, 这种方式无法区分打开失败还是文件内容为空
 * @param filePath
 * @return
 */
std::string readFile(const std::string& filePath){
    std::fstream fs(filePath);
    if(fs){
        std::string result = "data ...";
        // read file
        fs.close();
        return result;
    }else{
        return "";
    }
}


std::optional<std::string> readFile2(const std::string& filePath){
    std::fstream fs(filePath);
    if(fs){
        std::string result = "data ...";
        // read file
        fs.close();
        return result;
    }else{
        return {};
    }
}

void optionalTest(){
    std::string data = readFile("data.txt");
    if(data!=""){
        std::cout<<"data: "<<data<<std::endl;
    }else{
        std::cout<<"can not read data"<<std::endl;
    }

    std::optional<std::string> data2 = readFile2("data.txt");
    if(data2.has_value()){
        std::cout<<"data2: "<<data2.value()<<std::endl;
    }else{
        std::cout<<"can not read data"<<std::endl;
    }

    std::optional<std::string> data3 = readFile2("data.txt");
    if(data3){
        std::cout<<"data3: "<<data3.value()<<std::endl;
    }else{
        std::cout<<"can not read data"<<std::endl;
    }

    std::optional<std::string> data4 = readFile2("data.txt");
    std::cout<<"data4: "<<data4.value_or("no data")<<std::endl;

    std::optional<std::string> data5 = readFile2("data5.txt");
    std::cout<<"data5: "<<data5.value_or("no data")<<std::endl;
}