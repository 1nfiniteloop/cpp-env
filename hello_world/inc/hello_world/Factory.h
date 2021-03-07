#pragma once

#include <memory>

#include "Greeter.h"

/**
 * Static factory method
 */
namespace hello_world
{
std::unique_ptr<Greeter> CreateGreeter();
} // namespace hello_world
