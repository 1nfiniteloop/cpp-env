#include <gtest/gtest.h>

#include "hello_world/Greeter.h"

#include <sstream>

#include "GreeterImpl.h"

using namespace hello_world;

TEST(HelloWorldTest, MessageContent)
{
  std::ostringstream out{};
  GreeterImpl greeter{out};
  greeter.SayHello();
  ASSERT_EQ("Hello, world!\n", out.str());
}
