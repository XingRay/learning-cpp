//
// Created by leixing on 2024/5/1.
//

#include "Lesson_090_move.h"
#include <cstring>
#include <memory>
#include <iostream>

class MyString {
private:
    size_t size;
    char *data;

public:
    // default constructor
    MyString():size(0), data(nullptr){

    };

    // constructor
    MyString(const char *chars) {
        std::cout << "MyString Constructor\n";
        size = strlen(chars)+1;
        data = (char *) malloc(size);
        memcpy(data, chars, size);
    }

    // copy constructor
    MyString(const MyString &src) {
        std::cout << "MyString copy Constructor\n";
        size = src.size;
        data = (char *) malloc(size);
        memcpy(data, src.data, size);
    }

    // move constructor
    MyString(MyString &&other) {
        std::cout << "MyString move Constructor\n";
        size = other.size;
        data = other.data;

        other.size = 0;
        other.data = nullptr;
    }

    // copy
    MyString &operator=(const MyString &other) {
        std::cout << "MyString assign copy =\n";
        size = other.size;
        data = (char *) malloc(size);
        memcpy(data, other.data, size);

        return *this;
    }



    MyString &operator=(MyString &&other) {
        std::cout << "MyString move copy\n";
        delete[] data;

        if (this != &other) {
            this->size = other.size;
            this->data = other.data;

            other.size = 0;
            other.data = nullptr;
        }

        return *this;
    }


    ~MyString() {
        delete[] data;
        size = 0;
    };

    void print() {
        std::cout << "{ data:";
        for(uint32_t i = 0; i<size; i++){
            putchar(data[i]);
        }
        std::cout<<", size:" << size << "}\n";
    }
};

class Entity {
private:
    MyString myString;
    int otherData;

public:
    Entity() {

    }

    Entity(MyString string){

    }

    ~Entity() {

    }


};

void moveTest() {
    MyString s1 = "test string";
    MyString s2;

    std::cout << "s1\n";
    s1.print();
    std::cout << "s2\n";
    s2.print();

    s2 = std::move(s1);

    std::cout << "s1\n";
    s1.print();
    std::cout << "s2\n";
    s2.print();


}