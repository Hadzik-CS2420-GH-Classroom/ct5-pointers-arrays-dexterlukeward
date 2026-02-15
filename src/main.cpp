#include <iostream>

#include "arrays_as_pointers.h"
#include "pointers_and_arrays.h"
#include "pointers_as_arrays.h"

int main() {
    std::cout << "CT5 - Pointers & Arrays Basics" << '\n';
    std::cout << "===============================" << '\n';

    // Topic 1: Pointers and Arrays (4 items)
    pointersAndArrays();

    // Topic 2: Treating Pointers as Arrays (2 items)
    pointersAsArrays();

    // Topic 3: Treating Arrays as Pointers (1 item)
    arraysAsPointers();

    std::cout << "\n===============================" << '\n';
    std::cout << "CT5 Complete!" << '\n';

    return 0;
}
