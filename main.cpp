#include <iostream>

#include "board.h"

int main()
{
    std::cout << "Hello, world!\n";

    MysticSquareBoard board;
    std::cout << "Size of the board: " << board.GetSize() << std::endl;
}
