#pragma once

#include "iterator.h"

#include "array.h"
#include "vector.h"
/*
#include "list.h"
#include "hashtable.h"
#include "binary_tree.h"
#include "dstring.h"
*/

#ifdef _USE_GENERIC_COLLECTIONS_

#define find(container, value) _Generic( (container), \
    array_t* : arr_find(container, value),            \
    vector_t* : vec_find(container, value),           \
    default : NULL                                    \
)

#endif // !_USE_GENERIC_COLLECTIONS_