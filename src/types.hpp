#ifndef __eva_types_H__
#define __eva_types_H__

#include "common.hpp"
#include "allocator.hpp"

namespace eva {
  /**
   * A type in eva is a primitive or composite data type.
   */
  class Type {
  public:
    Type(const interned_string &module,
         const interned_string &name);
    virtual ~Type();

    virtual bool isPrimitive() const;
    virtual bool isComposite() const;

    virtual void display(std::ostream &out, Data d) const =0;

    virtual void deallocate(Data old, const Allocator &alloc) const =0;
    virtual Data clone(Data old, const Allocator &alloc) const =0;

    /** Move data from one region of memory to another.
     */
    virtual bool move(Data from, Data to) const =0;
    virtual bool copy(Data from, Data to) const =0;

    virtual std::size_t fixedSize() const =0;
    virtual std::size_t dynamicSize(Data d) const;

    inline const interned_string module() const { return m_module; }
    inline const interned_string name() const { return m_name; }

  private:
    interned_string m_module, m_name;
  };

  std::ostream &operator<<(std::ostream &out, const Type &t);

}

#endif
