#include <stdlib.h>
#include <assert.h>

#include "maths/maths.h"

void test_map() {
    assert(map(25.0f, 0.0f, 100.0f, 0.0f, 1.0f) == 0.25f);
    assert(map(0.0f, -1.0f, 1.0f, 0.0f, 1.0f) == 0.5f);
    assert(map(1.0f, 0.0f, 1.0f, 0.0f, 1.0f) == 1.0f);
    assert(map(0.0f, 0.0f, 1.0f, 0.0f, 1.0f) == 0.0f);
}

int main() {
    test_map();
    return EXIT_SUCCESS;
}