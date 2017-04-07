#pragma once

#include <random>
#include <utility>

/*
 * MysticSquareBoard represents a square board with tiles numbered from
 * 1 to (N^2 - 1), and a single missing tile (mystic square). Any tile
 * surrounding the mystic square can be shifted into its location, essentially
 * performing a swap of locations.
 *
 * The Mystic Square puzzle is considered solved when the numbered tiles
 * read sequentially from left-to-right and top-to-bottom, starting at 1.
 *
 * A solved board:
 *
 *   +---+---+---+
 *   | 1 | 2 | 3 |
 *   +---+---+---+
 *   | 4 | 5 | 6 |
 *   +---+---+---+
 *   | 7 | 8 |   |
 *   +---+---+---+
 *
 * This class hides the implementation details of the operations you'd
 * expect in a physical board. Perhaps also in playing with a friend,
 * so you get a fairly random shuffle.
 *
 * This class is not threadsafe.
 */
class MysticSquareBoard
{
public:
    typedef std::pair<size_t, size_t> Location;

public:
    explicit MysticSquareBoard(size_t size)
        : m_size(size)
        , m_mysticSquareLoc(0, 0)
        , m_prng(std::random_device()())
        , m_uniformDistribution(0, 3)
    {
    }

    // C++11 feature: Constructor delegation.
    MysticSquareBoard() : MysticSquareBoard(3) {}

    // InitBoard allocates memory for the board, initializes
    // the values, and shuffles the tiles into a soluble state.
    void InitBoard();

    // Shuffle randomizes the board to a soluble new position.
    void Shuffle();

    // IsSolved checks solution conditions. If true, then numbered
    // tiles read sequentially from left-to-right and top-to-bottom,
    // starting at 1, and the mystic square is in the last position.
    bool IsSolved();

    // Slide moves the tile at the specified location into the
    // position occupied by the mystic square. Will return false
    // if this tile is not adjacent to the mystic square.
    bool Slide(Location tile);
    bool Slide(size_t tileX, size_t tileY);

    // GetSize returns the edge length of the board.
    size_t GetSize() { return m_size; }

    // GetMysticSquareLocation returns the current location of
    // the mystic square (the one empty tile on the board).
    Location GetMysticSquareLocation() { return m_mysticSquareLoc; }

private:
    // private methods

private:
    // Edge length of the square board.
    size_t m_size;

    // Coordinates of the current location of the mystic square.
    std::pair<size_t, size_t> m_mysticSquareLoc;

    // Number of moves to make when shuffling.
    static const size_t NUM_SHUFFLE_MOVES = 1000;
    // Random number generator (mersenne_twister_engine).
    std::mt19937 m_prng;
    // Uniform distribution from which we pull numbers.
    std::uniform_int_distribution<size_t> m_uniformDistribution;
};
