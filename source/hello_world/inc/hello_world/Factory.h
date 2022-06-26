#pragma once

#include <memory>

#include "Greeter.h"

/**
 * Static factory method
 */
namespace hello_world
{
std::unique_ptr<Greeter> create_greeter();
} // namespace hello_world
