#ifndef NONSTDSTRING_H
#define NONSTDSTRING_H

#include <fmt/format.h>

#include <string>
#include <vector>

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

private:
    static nonstdstring vfmt(fmt::string_view format, fmt::format_args args)
    {
        nonstdstring ret;
        fmt::vformat_to(std::back_inserter(ret), format, args);
        return ret;
    }
};

#endif
