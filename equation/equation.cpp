#include <iostream>
#include <fstream>
#include <vector>
#include "Header.h"

int main()
{
    std::vector<double> koef;
    read(koef);
    double discr = discriminant(koef);
    search(discr, koef);
    return 0;
}