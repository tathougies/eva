#ifndef __eva_primitive_H__
#define __eva_primitive_H__

namespace eva {
  template<const char *module, const char *nm, typename T>
  class Primitive : public Type {
  public:
    Primitive()
      : Type(module, nm) {
    }

    virtual ~Primitive() {
    }

    virtual bool isPrimitive() const {
      return true;
    }

    virtual void display(std::ostream &out, Data d) const {
      out << "(" << *this << ") " << *((T*) d);
    }

    static Data allocate(const Allocator &alloc, T value) {
      T *p(alloca.allocate_fixed<T>());
      *p = value;
      return p;
    }

    virtual void deallocate(Data old, const Allocator &alloc) const {
      alloc.deallocate_fixed<T>(old);
    }

    virtual void clone(Data old, const Allocator &alloc) const {
      T *ptr(alloc.allocate_fixed<T>());
      *ptr = *(T *)old;
    }

    virtual bool move(Data from, Data to) const {
      return copy(from, to);
    }

    virtual bool copy(Data from, Data to) const {
      *(T *)to = *(T *)from;
      return true;
    }

    virtual std::size_t fixedSize() const {
      return sizeof(T);
    }
  };

  namespace types {
    typedef Primitive<"eva.base", "int64", std::int64_t> Int64;
    typedef Primitive<"eva.base", "int32", std::int32_t> Int32;
    typedef Primitive<"eva.base", "int16", std::int16_t> Int16;
    typedef Primitive<"eva.base", "int8",  std::int8_t>  Int8;

    typedef Primitive<"eva.base", "uint64", std::uint64_t> UInt64;
    typedef Primitive<"eva.base", "uint32", std::uint32_t> UInt32;
    typedef Primitive<"eva.base", "uint16", std::uint16_t> UInt16;
    typedef Primitive<"eva.base", "uint8",  std::uint8_t>  UInt8;

    typedef Primitive<"eva.base", "double", double> Double;
  }
}

#endif
