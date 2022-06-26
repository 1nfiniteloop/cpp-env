#include <iostream>

#include "GreeterImpl.h"
#include "hello_world/Greeter.h"

namespace hello_world
{
GreeterImpl::GreeterImpl(std::ostream& out)
    : m_out{out}
{
}

void GreeterImpl::say_hello() const
{
  m_out << "Hello, world!" << std::endl;
}
} // namespace hello_world
