#include <iostream>

#include "GreeterImpl.h"
#include "hello_world/Factory.h"

/**
 * Static factory method implementation
 */
namespace hello_world
{
std::unique_ptr<Greeter> create_greeter()
{
  return std::make_unique<GreeterImpl>(std::cout);
}
} // namespace hello_world
