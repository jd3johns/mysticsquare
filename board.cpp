#include "board.h"

#include <random>

void MysticSquareBoard::InitBoard()
{
    // allocate memory for board
    // init values
    Shuffle();
}

void MysticSquareBoard::Shuffle()
{
    size_t direction = 0;
    for (size_t move = 0; move < NUM_SHUFFLE_MOVES; ++move)
    {
        // Generate a random direction (up, right, down, or left).
        direction = m_uniformDistribution(m_prng);
    }
}

bool MysticSquareBoard::IsSolved()
{
    return false;
}

bool MysticSquareBoard::Slide(MysticSquareBoard::Location tile)
{
    return false;
}

bool MysticSquareBoard::Slide(size_t tileX, size_t tileY)
{
    return false;
}

