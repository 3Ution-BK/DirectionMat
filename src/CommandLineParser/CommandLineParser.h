#ifndef DIRECTIONMAT_COMMANDLINEPARSER_COMMANDLINEPARSER_H_
#define DIRECTIONMAT_COMMANDLINEPARSER_COMMANDLINEPARSER_H_

#include <memory>

namespace DirectionMat
{

class CommandLineParser
{
public:
    explicit CommandLineParser(int argc, const char *const argv[]);
    CommandLineParser(const CommandLineParser &other);
    CommandLineParser &operator=(const CommandLineParser &other);
    CommandLineParser(CommandLineParser &&other) noexcept;
    CommandLineParser &operator=(CommandLineParser &&other) noexcept;
    ~CommandLineParser();

    int column() const;
    const char *name() const;
    int row() const;

private:
    class Impl;
    std::unique_ptr<Impl> pimpl_;
};

} // namespace DirectionMat

#endif // DIRECTIONMAT_COMMANDLINEPARSER_COMMANDLINEPARSER_H_
