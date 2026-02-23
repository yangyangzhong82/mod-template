#pragma once

#include "ll/api/io/LogLevel.h"
#include <string>

namespace my_mod {

struct Config {
    int              version                  = 1;
    ll::io::LogLevel logLevel                 = ll::io::LogLevel::Info;
    std::string      language                 = "en_US";
    bool             exampleJoinMessageEnable = false;
    bool             exampleJoinLogEnable     = false;
};

} // namespace my_mod
