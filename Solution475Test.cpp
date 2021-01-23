
#include <iostream>

#include "catch.hpp"

extern "C" {
#include "Solution475.h"
}

TEST_CASE("[1,2,3], [2] = 1", "[475]") {
    int houses[] = {1, 2, 3};
    int heaters[] = {2};
    auto result = findRadius(houses, sizeof(houses) / sizeof(int), heaters, sizeof(heaters) / sizeof(int));
    REQUIRE(result == 1);
}

TEST_CASE("[1,3,2], [2] = 1", "[475]") {
    int houses[] = {1, 3, 2};
    int heaters[] = {2};
    auto result = findRadius(houses, sizeof(houses) / sizeof(int), heaters, sizeof(heaters) / sizeof(int));
    REQUIRE(result == 1);
}

TEST_CASE("[1,2,3,4], [1,4] = 1", "[475]") {
    int houses[] = {1, 2, 3, 4};
    int heaters[] = {1, 4};
    auto result = findRadius(houses, sizeof(houses) / sizeof(int), heaters, sizeof(heaters) / sizeof(int));
    REQUIRE(result == 1);
}

TEST_CASE("[1,5], [2] = 3", "[475]") {
    int houses[] = {1, 5};
    int heaters[] = {2};
    auto result = findRadius(houses, sizeof(houses) / sizeof(int), heaters, sizeof(heaters) / sizeof(int));
    REQUIRE(result == 3);
}

TEST_CASE("[1,5], [10] = 9", "[475]") {
    int houses[] = {1, 5};
    int heaters[] = {10};
    auto result = findRadius(houses, sizeof(houses) / sizeof(int), heaters, sizeof(heaters) / sizeof(int));
    REQUIRE(result == 9);
}

TEST_CASE("unsorted heaters", "[475]") {
    int houses[] = {282475249, 622650073, 984943658, 144108930, 470211272, 101027544, 457850878, 458777923};
    int heaters[] = {823564440, 115438165, 784484492, 74243042, 114807987, 137522503, 441282327, 16531729, 823378840,
                     143542612};
    auto result = findRadius(houses, sizeof(houses) / sizeof(int), heaters, sizeof(heaters) / sizeof(int));
    REQUIRE(result == 161834419);
}

TEST_CASE("large distances", "[475]") {
    int houses[] = {474833169, 264817709, 998097157, 817129560};
    int heaters[] = {197493099, 404280278, 893351816, 505795335};
    auto result = findRadius(houses, sizeof(houses) / sizeof(int), heaters, sizeof(heaters) / sizeof(int));
    REQUIRE(result == 104745341);
}