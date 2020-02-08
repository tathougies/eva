#ifndef __eva_allocator_H__
#define __eva_allocator_H__

#include "common.hpp"

namespace eva {
  class Allocator {
  public:
    virtual ~Allocator();

    template<typename T, typename ...Args>
    Data operator(Args... args) {
      return T::allocate(*this, args...)
    }

    template<typename T>
    T *allocate_fixed(int n = 1, std::size_t alignment = 0) {
      return allocate(sizeof(T) * n, alignment);
    }

    template<typename T>
    void deallocate_fixed(Data d, int n = 1) {
      return deallocate(d, sizeof(T) * n);
    }

    virtual Data allocate(std::size_t sz, std::size_t alignment = 0) =0;
    virtual void deallocate(Data d, std::size_t sz) =0;
  };

  class CxxAllocator {
  public:
    virtual ~CxxAllocator();

    virtual Data allocate(std::size_t sz, std::size_t alignment = 0) = 0;
    virtual void deallocate(Data d, std::size_t sz) =0;
  };
}

#endif
