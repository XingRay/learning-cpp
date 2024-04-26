//
// Created by leixing on 2024/4/25.
//

#include "Lesson_066_TypePunning.h"

#include <iostream>

/**
 * Type punning
A form of pointer aliasing where two pointers and refer to the same location in memory but represent that location as different types.
 The compiler will treat both "puns" as unrelated pointers. Type punning has the potential to cause dependency problems for any data
 accessed through both pointers.
 */
namespace Lesson066 {
    struct Empty {
    };

    struct Entity {
        int x;
        int y;

        int * getPositions(){
            return &x;
        }
    };
}

/**
 * 1. 获取数据的指针
 * 2. 转换为目标类型的指针
 * 3. 解引用转化为对象操作
 */
void typePunningTest() {
    using namespace Lesson066;

    int a = 50;

    double value1 = a;
    std::cout << "value1: " << value1 << std::endl;

    double value2 = (double) a;
    std::cout << "value2: " << value2 << std::endl;

    double value3 = *(double *) &a;
    std::cout << "value3: " << value3 << std::endl;

    std::cout << (sizeof a) << " " << sizeof value3 << std::endl;

    Empty empty;
    // 1
    std::cout << sizeof empty << std::endl;

    Entity e = {5, 8};
    int *position = (int *) &e;
    std::cout << "position: " << position[0] << " " << position[1] << std::endl;

    int y = *(int *) ((char *) &e + 4);
    std::cout << "y: " << y << std::endl;

    int* positions = e.getPositions();
    positions[0] = 100;

}