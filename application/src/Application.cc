#include <boost/program_options.hpp>
#include <iostream>

#include "BuildInfo.h"
#include "hello_world/Factory.h"
#include "hello_world/Greeter.h"

namespace
{
struct Arguments
{
  int count{};
  char const** argv{};
};

class Application final
{
private:
  const Arguments _args{};

public:
  Application(Arguments args)
      : _args{std::move(args)} {}
  ~Application() = default;

  Application(const Application& cls) = delete;            // Copy-constructor
  Application& operator=(const Application& cls) = delete; // Copy-assignment constructor
  Application(Application&& cls) = delete;                 // Move-constructor
  Application& operator=(Application&& cls) = delete;      // Move-assignment constructor

  void Run() const
  {
    namespace options = boost::program_options;
    options::options_description desc{"C++ Hello World"};
    desc.add_options()
        ("help", "Show this help")
        ("version", "Show version and other build parameters");
    options::variables_map mapping{};
    options::store(options::parse_command_line(_args.count, _args.argv, desc), mapping);
    options::notify(mapping);

    if (_args.count == 1)
    {
      SayHello();
    }
    else if (mapping.count("version"))
    {
      PrintVersion();
    }
    else
    {
      std::cout << desc << std::endl;
    }
  }

private:
  void SayHello() const
  {
    auto greeter = hello_world::CreateGreeter();
    greeter->SayHello();
  }

  void PrintVersion() const
  {
    std::cout << "Version: "
              << application::BUILD_VERSION << std::endl
              << "Commit hash: "
              << application::COMMIT_HASH << std::endl
              << "Built: "
              << application::BUILD_TIMESTAMP << std::endl;
  }
};
} // namespace

int main(int argc, char const** argv)
{
  const Application app{{argc, argv}};
  try
  {
    app.Run();
  }
  catch (const boost::program_options::unknown_option& err)
  {
    std::cerr << err.what() << std::endl;
  }
  return {};
}
