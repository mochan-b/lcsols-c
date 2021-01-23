
#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <cmocka.h>

#include "Solution475.h"

static void Soln475_test1(void **state) {
    int houses[] = {1, 2, 3};
    int heaters[] = {2};
    int result = findRadius(houses, sizeof(houses) / sizeof(int), heaters, sizeof(heaters) / sizeof(int));
    assert_int_equal(result, 1);
}

static void Soln475_test2(void **state) {
    int houses[] = {1, 3, 2};
    int heaters[] = {2};
    int result = findRadius(houses, sizeof(houses) / sizeof(int), heaters, sizeof(heaters) / sizeof(int));
    assert_int_equal(result, 1);
}

static void Soln475_test3(void **state) {
    int houses[] = {1, 2, 3, 4};
    int heaters[] = {1, 4};
    int result = findRadius(houses, sizeof(houses) / sizeof(int), heaters, sizeof(heaters) / sizeof(int));
    assert_int_equal(result, 1);
}

static void Soln475_test4(void **state) {
    int houses[] = {1, 5};
    int heaters[] = {2};
    int result = findRadius(houses, sizeof(houses) / sizeof(int), heaters, sizeof(heaters) / sizeof(int));
    assert_int_equal(result, 3);
}

static void Soln475_test5(void **state) {
    int houses[] = {1, 5};
    int heaters[] = {10};
    int result = findRadius(houses, sizeof(houses) / sizeof(int), heaters, sizeof(heaters) / sizeof(int));
    assert_int_equal(result, 9);
}

static void Soln475_test6(void **state) {
    int houses[] = {282475249, 622650073, 984943658, 144108930, 470211272, 101027544, 457850878, 458777923};
    int heaters[] = {823564440, 115438165, 784484492, 74243042, 114807987, 137522503, 441282327, 16531729, 823378840,
                     143542612};
    int result = findRadius(houses, sizeof(houses) / sizeof(int), heaters, sizeof(heaters) / sizeof(int));
    assert_int_equal(result, 161834419);
}

static void Soln475_test7(void **state) {
    int houses[] = {474833169, 264817709, 998097157, 817129560};
    int heaters[] = {197493099, 404280278, 893351816, 505795335};
    int result = findRadius(houses, sizeof(houses) / sizeof(int), heaters, sizeof(heaters) / sizeof(int));
    assert_int_equal(result, 104745341);
}

int main() {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(Soln475_test1),
            cmocka_unit_test(Soln475_test2),
            cmocka_unit_test(Soln475_test3),
            cmocka_unit_test(Soln475_test4),
            cmocka_unit_test(Soln475_test5),
            cmocka_unit_test(Soln475_test6),
            cmocka_unit_test(Soln475_test7),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}