#include <iostream>

#include "GreeterImpl.h"
#include "greeter/Greeter.h"

namespace greeter
{
GreeterImpl::GreeterImpl(std::ostream& out)
    : m_out{out}
{
}

void GreeterImpl::say_hello() const
{
  m_out << "Hello, world!" << std::endl;
}
} // namespace greeter
