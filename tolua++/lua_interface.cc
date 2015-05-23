#include "lua_interface.h"
#include "myclass.h"

void SetNumber(void* obj, int num)
{
    ((MyClass*)obj)->SetNumber(num);
}

int GetNumber(void* obj)
{
    return ((MyClass*)obj)->GetNumber();
}
