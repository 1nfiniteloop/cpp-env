#pragma once

#include <memory>

#include "Greeter.h"

/**
 * Static factory method
 */
namespace greeter
{
std::unique_ptr<Greeter> create_greeter();
} // namespace greeter
