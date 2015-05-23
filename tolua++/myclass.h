#ifndef MYCLASS_H
#define MYCLASS_H

#include <stdio.h>
#include <stdlib.h>

class MyClass
{
public:
    MyClass() : number_(0) {}

    void SetNumber(int num) {
        printf("c++: MyClass::SetNumber()\n");
        number_ = num;
    }
    int GetNumber() {
        printf("c++: MyClass::GetNumber()\n");
        return number_;
    }

private:    
    int number_;
};

#endif
