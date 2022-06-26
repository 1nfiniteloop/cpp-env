#include <iostream>

#include "hello_world/Greeter.h"
#include "GreeterImpl.h"


namespace hello_world
{
GreeterImpl::GreeterImpl(std::ostream& out)
    : _out{out}
{

}

void GreeterImpl::SayHello() const
{
  _out << "Hello, world!" << std::endl;
}
} // namespace hello_world
