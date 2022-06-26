#include <iostream>

#include "hello_world/Factory.h"
#include "GreeterImpl.h"

/**
 * Static factory method implementation
 */
namespace hello_world
{
std::unique_ptr<Greeter> CreateGreeter()
{
  return std::make_unique<GreeterImpl>(std::cout);
}
} // namespace hello_world
