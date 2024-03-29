/*******************************************************************************
 *  @file      random.c
 *  @brief     random algorithm
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright � young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#include "random.h"

#pragma region --- INCLUDES ---

#include <time.h>
#include <stdlib.h>

#pragma endregion

#pragma region --- FUNCTIONS ---

void random_init() { srand(time(NULL)); }

inline int _random() { return (int32_t)(((uint32_t)rand() << 30) | ((uint32_t)rand() << 15) | (uint32_t)rand()); }

int random(int from, int to) {
    assert(from <= to);
    return (int32_t)((int64_t)_random() % ((int64_t)to - (int64_t)from) + (int64_t)from);
}

void random_fill(int* array, size_t size, random_pt generator, int min, int max) {
    if (!generator)
        generator = &random;
    for (int i = 0; i < size; ++i)
        array[i] = generator(min, max);
}

#pragma endregion
