#include "types.hpp"

namespace eva {

  Type::Type(const interned_string &module,
             const interned_string &name)
    : m_module(module),
      m_name(name) {
  }

  Type::~Type() {
  }

  bool Type::isPrimitive() const {
    return false;
  }

  bool Type::isComposite() const {
    return false;
  }

  std::size_t Type::dynamicSize(Data d) const {
    return 0;
  }

  std::ostream &operator<<(std::ostream &out, const Type &t) {
    return (out << "type " << t.module() << ": " << t.name());
  }

}
