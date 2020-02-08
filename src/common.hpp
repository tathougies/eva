#ifndef __eva_common_H__
#define __eva_common_H__

#include <string>

#include <boost/flyweight.hpp>

namespace eva {
  typedef boost::flyweight<std::string> interned_string;
  typedef void *Data;

  typedef std::array<std::uint8_t, 64> Hash512;
  typedef Hash512 StreamId;
}

#endif
