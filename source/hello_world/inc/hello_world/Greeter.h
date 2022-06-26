#pragma once

namespace hello_world
{
class Greeter
{
public:
  virtual ~Greeter() = default;
  virtual void say_hello() const = 0;
};
} // namespace hello_world
