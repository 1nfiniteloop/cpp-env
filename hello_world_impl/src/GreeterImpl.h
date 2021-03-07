#pragma once

#include <ostream>

#include "hello_world/Greeter.h"


namespace hello_world
{
class GreeterImpl
    : public Greeter
{
private:
  std::ostream& _out;

public:
  GreeterImpl(std::ostream& out);

  void SayHello() const override;
};
} // namespace hello_world
