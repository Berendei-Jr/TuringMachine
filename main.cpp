//



#include "Turing.h"

int main() {
    turing::program PR = {
            "q0 * - q1 1 L",
            "q1 / - q2 1 L",
            "q2 / - q3 1 L",
            "q3 / - q4 * ST"
    };

    turing::machine M("*11*");
    M.Attach(PR);
    std::cout << M.Run();

    return 0;
}
