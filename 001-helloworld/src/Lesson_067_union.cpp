//
// Created by leixing on 2024/4/25.
//

#include "Lesson_067_union.h"
#include <iostream>


struct UnionTest01{
    union {
        float a;
        int b;
    };
};

struct Vec2{
    float x;
    float y;
};

struct Vec4{
    float x;
    float y;
    float z;
    float w;

    Vec2& getA(){
        return *(Vec2*)&x;
    }
};


struct UnionTest02{
    union {
        struct {
            float x;
            float y;
            float z;
            float w;
        };
        struct {
            Vec2 v1;
            Vec2 v2;
        };
    };
};

void unionTest(){
    UnionTest01 test01;
    test01.a = 2.0f;

    std::cout<< "a: "<<test01.a << " b: "<<test01.b<<std::endl;

    UnionTest02 test02 = {1.0f, 2.0f, 3.0f, 4.0f };
    test02.y = 100.0f;

    std::cout<< "x: "<<test02.x << " y: "<<test02.y<< " z: "<<test02.z<< " w: "<<test02.w<<std::endl;
    std::cout<< "v1.x: "<<test02.v1.x << " v1.y: "<<test02.v1.y<<std::endl;
    std::cout<< "v2.x: "<<test02.v2.x << " v2.y: "<<test02.v2.y<<std::endl;
}