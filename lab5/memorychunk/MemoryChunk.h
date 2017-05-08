//
// Created by adrian on 29.03.17.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H
#include <cstdint>
#include <algorithm>
#include <iostream>
#include <string>
namespace memorychunk{
    class MemoryChunk{
    public:
        MemoryChunk(size_t sz);
        int8_t *MemoryAt(size_t offset) const;
        size_t ChunkSize() const;
        ~MemoryChunk();

    private:
        int8_t *ptr_;

    };
}

#endif //JIMP_EXERCISES_MEMORYCHUNK_H
