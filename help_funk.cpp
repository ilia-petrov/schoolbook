#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>

static void tn(int x)
{
    if (x)
    {
        std::cout << '\t' << x;
    }
    std::cout << '\n';
}