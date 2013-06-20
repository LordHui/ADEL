#ifndef MEMORYPOOL_H
#define MEMORYPOOL_H

#include <boost/pool/singleton_pool.hpp>
struct PoolTag {};
#define ChunkSize 24
typedef boost::singleton_pool<PoolTag, ChunkSize> pool;

#endif MEMORYPOOL_H

//