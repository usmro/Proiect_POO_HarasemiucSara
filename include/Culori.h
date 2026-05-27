#ifndef CULORI_H
#define CULORI_H

#include <string>

// Coduri ANSI pentru culori in terminal
// Functioneaza pe Linux/Mac nativ si pe Windows 10+ daca activam suportul

namespace Culori {
    const std::string RESET   = "\033[0m";
    const std::string BOLD    = "\033[1m";

    const std::string ROSU    = "\033[31m";
    const std::string VERDE   = "\033[32m";
    const std::string GALBEN  = "\033[33m";
    const std::string ALBASTRU= "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN    = "\033[36m";

    const std::string ROSU_D    = "\033[91m";
    const std::string VERDE_D   = "\033[92m";
    const std::string GALBEN_D  = "\033[93m";
    const std::string ALBASTRU_D= "\033[94m";
    const std::string CYAN_D    = "\033[96m";

    const std::string FUNDAL_ROSU   = "\033[41m";
    const std::string FUNDAL_VERDE  = "\033[42m";
}

#endif
