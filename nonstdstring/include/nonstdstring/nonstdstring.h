#ifndef NONSTDSTRING_H
#define NONSTDSTRING_H

#include <fmt/format.h>
#include <fmt/printf.h>

#include <string>
#include <vector>

// follows vformat_to, probably has to be duplicated for wchar_t
template <typename OutputIt,
          FMT_ENABLE_IF(fmt::detail::is_output_iterator<OutputIt, char>::value)>
auto vsprintf_to(OutputIt out, fmt::string_view fmt,
                 fmt::basic_format_args<fmt::basic_printf_context<char>> args) -> OutputIt
{
    auto &&buf = fmt::detail::get_buffer<char>(out);
    fmt::detail::vprintf(buf, fmt, args);
    return fmt::detail::get_iterator(buf, out);
}

class nonstdstring : public std::vector<char>
{
public:
    nonstdstring() = default;
    nonstdstring(const char *first, const char *last)
        : std::vector<char>(first, last) {}
    nonstdstring(const char *first, std::size_t n)
        : std::vector<char>(first, first + n) {}

    explicit operator std::string() const { return std::string(begin(), end()); }

    template <typename... Args>
    static nonstdstring fmt(fmt::format_string<Args...> format, Args &&...args)
    {
        return vfmt(format, fmt::make_format_args(args...));
    }

    template <typename... Args>
    static nonstdstring sprintf(fmt::string_view format, Args &&...args)
    {
        nonstdstring ret;
        vsprintf_to(std::back_inserter(ret), format, fmt::make_printf_args(args...));
        return ret;
    }

private:
    static nonstdstring vfmt(fmt::string_view format, fmt::format_args args)
    {
        nonstdstring ret;
        fmt::vformat_to(std::back_inserter(ret), format, args);
        return ret;
    }
};

#endif
