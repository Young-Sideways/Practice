/*******************************************************************************
 *  @file      search.h
 *  @brief     search algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright � Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#ifndef _SEARCH_H_
#define _SEARCH_H_

#pragma once

#pragma region --- INCLUDES ---

#include "../core/core.h"
#include "comparator.h"

#pragma endregion

#pragma region --- TYPEDEFS ---

typedef void* (search_t)(_IN void*, _IN _NULLABLE size_t, _IN size_t, _IN void*, _IN _NULLABLE comparator_pt);
typedef search_t* search_pt;

#pragma endregion

#pragma region --- FUNCTIONS ---

search_t linear_search;
search_t binary_search;

#pragma endregion

#pragma region --- ITERATOR ADAPTER ---
#ifdef _ITERATOR_H_

#include <stdbool.h>

//iterator_t find(const void* container,const void* value);
//bool contains(const void* container, const void* value);

#endif
#pragma endregion

#endif // !_SEARCH_H_