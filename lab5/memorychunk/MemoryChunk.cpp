//
// Created by adrian on 29.03.17.
//

#include "MemoryChunk.h"
#include <cstdint>
#include <algorithm>
#include <iostream>
#include <string>

namespace memorychunk {
    MemoryChunk::MemoryChunk(size_t sz) {
        ptr_ = new int8_t[sz];
    }

    size_t MemoryChunk::ChunkSize() const {
        int i=0;
        while (&(ptr_)[i]!= nullptr){
            i++;
        }
        return i;


    }
    int8_t *MemoryChunk::MemoryAt(size_t offset) const{
        return &(ptr_)[offset];
    }
    MemoryChunk::~MemoryChunk() {
        delete [] ptr_;
    }

}

