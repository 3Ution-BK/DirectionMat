#include "CommandLineParser.h"
#include "ProjectConfigures.h"

#include "opencv2/core/cvstd.hpp"
#include "opencv2/core/utility.hpp"

#include <cstdlib>

namespace DirectionMat
{

namespace
{

cv::String keys{"{help h usage ? | | Print this help message and exit}"
                "{@row | 300 | row of the image}"
                "{@column | 400 | column of the image}"
                "{f name filename | image.png | name of the image}"};

} // namespace

class CommandLineParser::Impl
{
public:
    explicit Impl(int argc, const char *const argv[]);

    bool getArguments();

    void printErrorsAndExit() const;
    void printHelpAndExit() const;

    bool hasHelp() const;

    cv::CommandLineParser parser_;

    int column_;
    int row_;
    cv::String name_;
};

CommandLineParser::CommandLineParser(int argc, const char *const argv[])
    : pimpl_{std::make_unique<Impl>(Impl{argc, argv})}
{
}

CommandLineParser::CommandLineParser(const CommandLineParser &other)
    : pimpl_(std::make_unique<Impl>(Impl{*other.pimpl_}))
{
}

CommandLineParser &CommandLineParser::operator=(const CommandLineParser &other)
{
    if (this != &other)
    {
        pimpl_.reset(new Impl{*other.pimpl_});
    }

    return *this;
}

CommandLineParser::CommandLineParser(CommandLineParser &&other) noexcept =
    default;

CommandLineParser &
CommandLineParser::operator=(CommandLineParser &&other) noexcept = default;

CommandLineParser::~CommandLineParser() = default;

int CommandLineParser::column() const { return pimpl_->column_; }

const char *CommandLineParser::name() const { return pimpl_->name_.c_str(); }

int CommandLineParser::row() const { return pimpl_->row_; }

CommandLineParser::Impl::Impl(int argc, const char *const argv[])
    : parser_{argc, argv, keys}
{
    parser_.about(Application::projectInfo());

    if (hasHelp())
    {
        printHelpAndExit();
    }

    if (!getArguments())
    {
        printErrorsAndExit();
    }
}

bool CommandLineParser::Impl::getArguments()
{
    row_ = parser_.get<int>(0);
    column_ = parser_.get<int>(1);
    name_ = parser_.get<cv::String>("name");

    return parser_.check();
}

bool CommandLineParser::Impl::hasHelp() const { return parser_.has("help"); }

void CommandLineParser::Impl::printErrorsAndExit() const
{
    parser_.printErrors();
    exit(EXIT_FAILURE);
}

void CommandLineParser::Impl::printHelpAndExit() const
{
    parser_.printMessage();
    exit(EXIT_SUCCESS);
}

} // namespace DirectionMat
