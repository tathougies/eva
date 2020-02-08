#include "allocator.hpp"

namespace eva {
  Allocator::~Allocator() {
  }

  CxxAllocator::~CxxAllocator() {
  }

  Data CxxAllocator::allocate(std::size_t sz, std::size_t alignment) {
    return (void *) new char[sz];
  }

  void CxxAllocator::deallocate(Data d, std::size_t sz) {
    delete[] d;
  }
}
