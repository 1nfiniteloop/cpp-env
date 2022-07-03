#include <iostream>

#include "GreeterImpl.h"
#include "greeter/Factory.h"

/**
 * Static factory method implementation
 */
namespace greeter
{
std::unique_ptr<Greeter> create_greeter()
{
  return std::make_unique<GreeterImpl>(std::cout);
}
} // namespace greeter
