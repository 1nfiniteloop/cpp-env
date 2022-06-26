#pragma once

#include <ostream>

#include "hello_world/Greeter.h"

namespace hello_world
{
class GreeterImpl
    : public Greeter
{
private:
  std::ostream& m_out;

public:
  GreeterImpl(std::ostream& out);

  void say_hello() const override;
};
} // namespace hello_world
