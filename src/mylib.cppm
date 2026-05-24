export module mcpplibs.mylib;

import std;

namespace mcpplibs::mylib {

export [[nodiscard]] std::string hello_mcpplibs() {
    return "hello mcpplibs";
}

} // namespace mcpplibs::mylib
