#include "smart_ptr.hpp"
#include "unique_ptr.hpp"
#include <stdio.h>

class shape {
public:
    virtual ~shape() {}
};

class circle:public shape {
public:
    ~circle() {
        puts("~circle()");
    }
};

int main() 
{
    smart_ptr<circle> ptr1(new circle());
    printf("ptr1 smart_ptr():%p\n", &ptr1);
    printf("use count of ptr1 is %ld\n", ptr1.use_count());

    smart_ptr<shape> ptr2;
    printf("ptr2 smart_ptr():%p\n", &ptr2);
    printf("use count of ptr2 was %ld\n", ptr2.use_count());

    ptr2 = ptr1;
    printf("ptr1 after assign smart_ptr():%p\n", &ptr1);
    printf("ptr2 after assign smart_ptr():%p\n", &ptr2);
    printf("use count of ptr2 is now %ld\n", ptr2.use_count());

    if (ptr1) {
        puts("ptr1 is not empty");
    }

    smart_ptr<circle> ptr3 = dynamic_pointer_cast<circle>(ptr2);
    printf("ptr3 after cast smart_ptr():%p\n", &ptr3);
    printf("ptr2 after cast smart_ptr():%p\n", &ptr2);
    printf("use count of ptr3 is %ld\n", ptr3.use_count());
}