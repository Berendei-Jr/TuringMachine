// Copyright 2022 Andrey Vedeneev vedvedved2003@gmail.com

// Symbol "/" means EMPTY symbol
// Symbol "%" means ANY symbol

#include "Turing.h"

int main() {
    turing::program PR = {
            "q0 / - q1 / ST",
            "q0 % - q0 b R"
    };

    turing::machine M("abcdef");
    M.Attach(PR);
    std::cout << M.Run();

    return 0;
}
