#include <gtest/gtest.h>

#include "greeter/Greeter.h"

#include <sstream>

#include "GreeterImpl.h"

using namespace greeter;

TEST(HelloWorldTest, MessageContent)
{
  std::ostringstream out{};
  GreeterImpl greeter{out};
  greeter.say_hello();
  ASSERT_EQ("Hello, world!\n", out.str());
}
