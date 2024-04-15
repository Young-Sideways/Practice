/*******************************************************************************
 *  @file      general.h
 *  @brief     general structures and control functions for collections
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright � young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef _COLLECTION_GENERAL_H_
#define _COLLECTION_GENERAL_H_

#pragma once

#pragma region --- INCLUDES ---

#include "../core/core.h"

#pragma endregion

#pragma region --- TYPEDEFS ---

/**
 *  @typedef internal_memory_access_t
 *  @brief   function prototype typedef for unifying access to container memory
 */
typedef void (*internal_memory_access_t)(_IN struct collection_header* collection, _INOUT _NULLABLE void**, _INOUT _NULLABLE int*);

/**
 *  @struct collection_header
 *  @brief  main data structure for all collections
 */
struct collection_header {
    size_t capacity    ;
    size_t size        ;
    size_t element_size;

    void* _comp  ;
    void* _search;
    void* _swap  ;
    void* _sort  ;

    internal_memory_access_t next         ;
    internal_memory_access_t prev         ;
    internal_memory_access_t data_block   ;
    internal_memory_access_t random_access;
};

#pragma endregion

#pragma region --- MACRO ---

/**
 *  @def   GROWTH_FACTOR
 *  @brief memory consumption growth factor for collections ( new size = ~x2 )
 *  @param n - current size
 */
#define GROWTH_FACTOR(n) (n ? (n << 1) : 0x1U)
/**
*  @def   COLLECTION_SIZE_MIN
*  @brief Minimum size for all containers
*/
#define COLLECTION_SIZE_MIN (0x0U)
/**
*  @def   COLLECTION_SIZE_MAX
*  @brief Maximum size for all containers
*/
#define COLLECTION_SIZE_MAX ((uint32_t)INT32_MAX)

/**
*  @def   COLLECTION_INVALID_INDEX
*  @brief Value of invalid index for all containers
*/
#define COLLECTION_INVALID_INDEX (INT32_C(-1))

/**
 *  @def   COLLECTION_HEADER
 *  @brief inplace default collection header struct
 */
#define COLLECTION_HEADER() struct collection_header;

/**
 *  @def   COLLECTION_INVALID_HEADER
 *  @brief invalid value for default collection header
 */
#define COLLECTION_INVALID_HEADER() (struct collection_header){ \
    .capacity       = 0,                                        \
    .size           = 0,                                        \
    .element_size   = 0,                                        \
    ._comp          = NULL,                                     \
    ._search        = NULL,                                     \
    ._swap          = NULL,                                     \
    ._sort          = NULL,                                     \
    .next           = NULL,                                     \
    .prev           = NULL,                                     \
    .data_block     = NULL,                                     \
    .random_access  = NULL                                      \
}

#pragma endregion

#pragma region --- CONSTRUCTORS / DESTRUCTORS ---

struct collection_header header_allocator(
    _IN _NULLABLE const size_t                   capacity     ,
    _IN           const size_t                   element_size ,
    _IN _NULLABLE const void*                    _comp        ,
    _IN _NULLABLE const void*                    _search      ,
    _IN _NULLABLE const void*                    _swap        ,
    _IN _NULLABLE const void*                    _sort        ,
    _IN           const internal_memory_access_t next         ,
    _IN           const internal_memory_access_t prev         ,
    _IN _NULLABLE const internal_memory_access_t data_block   ,
    _IN           const internal_memory_access_t random_access);

#pragma endregion

#pragma region --- PUBLIC ---

#define GENERAL_CHANGE_COMP(collection, value)   ((struct collection_header*)(&collection))->_comp   = value
#define GENERAL_CHANGE_SEARCH(collection, value) ((struct collection_header*)(&collection))->_search = value
#define GENERAL_CHANGE_SWAP(collection, value)   ((struct collection_header*)(&collection))->_swap   = value
#define GENERAL_CHANGE_SORT(collection, value)   ((struct collection_header*)(&collection))->_sort   = value

#pragma endregion

#pragma region --- STATIC ASSERTION BLOCK ---

#define TYPE_SIZE_ASSERT(expression) static_assert(expression, "Collection core error: default type pointers have different sizes")
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(char*)              );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(short*)             );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(int*)               );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(long*)              );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(long long*)         );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(signed char*)       );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(signed short*)      );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(signed int*)        );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(signed long*)       );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(signed long long*)  );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(unsigned char*)     );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(unsigned short*)    );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(unsigned int*)      );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(unsigned long*)     );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(unsigned long long*));
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(float*)             );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(double*)            );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(long double*)       );

static_assert(sizeof(int32_t) == sizeof(uint32_t), "Collection core error: fixed size for signed and unsigned 32 bit integers are different");
#undef TYPE_SIZE_ASSERT

#pragma endregion

#endif // !_COLLECTION_GENERAL_H_
