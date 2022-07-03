#pragma once

namespace greeter
{
class Greeter
{
public:
  virtual ~Greeter() = default;
  virtual void say_hello() const = 0;
};
} // namespace greeter
