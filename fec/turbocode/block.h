#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <utils.h>
#include <iostream>
#include <bitset>
#include <cstdlib>

class Block : public std::vector<Bit>
{
public:
    Block(const std::vector<Bit>& other);
    Block(uint32_t size = 0);

    void addNoise(double bitSwapRate);

    static inline int hdistance(const Block& a, const Block& b, uint32_t size, uint32_t aStart = 0, uint32_t bStart = 0)
    {
        int count = 0;
        for (uint32_t i = 0; i < size; ++i) {
            if (a[aStart + i] != b[bStart + i])
                count++;
        }
        return count;
    }
};

#endif // BLOCK_H
