/*******************************************************************************
 *  @file      main.c
 *  @brief     main file of project
 *  @author    Young Sideways
 *  @date      23.05.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#include "core.h"

#include "macro/reverse.h"
#include "macro/arg.h"

int main(int argc, char** argv) {
    UNUSED(argc);
    UNUSED(argv);

    int arr[] = { VA_REVERSE(1) };

    return 0;
}
