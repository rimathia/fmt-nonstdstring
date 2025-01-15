#include <nonstdstring/nonstdstring.h>

#include <iostream>

enum class Importance
{
    low,
    medium
};

template <>
struct fmt::formatter<Importance> : formatter<string_view>
{
    // parse is inherited from formatter<string_view>.

    auto format(Importance i, format_context &ctx) const
        -> format_context::iterator
    {
        string_view name = "unknown";
        switch (i)
        {
        case Importance::low:
            name = "low";
            break;
        case Importance::medium:
            name = "medium";
            break;
        }
        return formatter<string_view>::format(name, ctx);
    }
};

int main()
{
    nonstdstring s;
    s.push_back('a');
    s.push_back('a');
    std::cout << std::string(s) << "\n";

    std::cout << std::string(nonstdstring::fmt("{}", 13)) << "\n";
    std::cout << std::string(nonstdstring::fmt("{:.4f}", 1.0 / 3.0)) << "\n";
    std::cout << std::string(nonstdstring::fmt("{}, {}", 13, Importance::low)) << "\n";
}
