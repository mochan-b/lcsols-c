
#include <stdlib.h>

#include "Solution475.h"

#ifndef max
#define max(a, b) ((a) > (b) ? (a) : (b))
#endif

#ifndef min
#define min(a, b) ((a) < (b) ? (a) : (b))
#endif


int findHeater(int house, int *heaters, int heatersSize) {
    int left = 0, right = heatersSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (heaters[mid] == house)
            return mid;
        if (heaters[mid] < house)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int compareFunction(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

int leftDistFn(int house, int *heaters, int heaterIndex) {
    return house - heaters[heaterIndex - 1];
}

int rightDistFn(int house, int *heaters, int heaterIndex) {
    return heaters[heaterIndex] - house;
}

int findRadius(int *houses, int housesSize, int *heaters, int heatersSize) {
    qsort(heaters, heatersSize, sizeof(int), compareFunction);

    int radius = 0;
    for (int i = 0; i < housesSize; i++) {
        int house = houses[i];
        int heaterIndex = findHeater(house, heaters, heatersSize);
        int heaterDist =
                heaterIndex == 0 ? rightDistFn(house, heaters, heaterIndex) : (heaterIndex == heatersSize ? leftDistFn(
                        house, heaters, heaterIndex) : min(leftDistFn(house, heaters, heaterIndex),
                                                           rightDistFn(house, heaters, heaterIndex)));
        radius = max(radius, heaterDist);
    }

    return radius;
}