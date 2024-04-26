//
// Created by leixing on 2024/4/25.
//

#include "Lesson_065_Sort.h"

#include <algorithm>
#include <vector>
#include <functional>
#include <random>
#include <iostream>

void sort() {
    std::vector<int> values = {3,5,1,4,2};
    std::sort(values.begin(), values.end());
    for(const auto &v: values){
        std::cout<<v<<" ";
    }
    std::cout<<std::endl;

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(values.begin(), values.end(), g);

    for(const auto &v: values){
        std::cout<<v<<" ";
    }
    std::cout<<std::endl;

    std::sort(values.begin(), values.end(), std::greater());
    for(const auto &v: values){
        std::cout<<v<<" ";
    }
    std::cout<<std::endl;

    std::sort(values.begin(), values.end(), std::less());
    for(const auto &v: values){
        std::cout<<v<<" ";
    }
    std::cout<<std::endl;

    std::sort(values.begin(), values.end(), [&](int a, int b)->bool{
        return a>b;
    });
    for(const auto &v: values){
        std::cout<<v<<" ";
    }
    std::cout<<std::endl;

    std::sort(values.begin(), values.end(), [&](int a, int b)->bool{
        return a<b;
    });
    for(const auto &v: values){
        std::cout<<v<<" ";
    }
    std::cout<<std::endl;


    std::sort(values.begin(), values.end(), [&](int a, int b)->bool{
        if(a==1){
            return false;
        }
        if(b==1){
            return true;
        }
        return a<b;
    });
    for(const auto &v: values){
        std::cout<<v<<" ";
    }
    std::cout<<std::endl;
}