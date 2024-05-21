/*******************************************************************************
 *  @file      random.h
 *  @brief     random algorithm
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright � young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef _RANDOM_H_
#define _RANDOM_H_

#pragma once

#pragma region --- INCLUDE ---

#include "../core/core.h"

#pragma endregion

#pragma region --- TYPEDEF ---

/**
 *  @typedef random_t
 *  @param[in] min,max - Generated values range
 */
typedef int (random_t)(int min, int max);
/**
 *  @typedef random_pt
 *  @brief   pointer type to \ref random_t function
 */
typedef random_t* random_pt;

#pragma endregion

#pragma region --- FUNCTION ---

/// @brief Initilizes a RNG generator with current time stamp
void random_init();

random_t random;

/**
 * @brief fill int array with \p generator
 * @param[in,out] array     - Pointer to int array
 * @param[in]     size      - Size of \p array
 * @param[in]     generator - Pointer to RNG generator
 * @param[in]     min,max   - Generated values range
 */
void random_fill(int* array, size_t size, random_pt generator, int min, int max);

#pragma endregion

#endif // !_RANDOM_H_
