add_library(nonstdstring nonstdstring.cpp include/nonstdstring/nonstdstring.h)
target_link_libraries(nonstdstring fmt)
target_include_directories(nonstdstring PUBLIC include)
