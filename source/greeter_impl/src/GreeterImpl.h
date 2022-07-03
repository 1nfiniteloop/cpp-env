#pragma once

#include <ostream>

#include "greeter/Greeter.h"

namespace greeter
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
} // namespace greeter
