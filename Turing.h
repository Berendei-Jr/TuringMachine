// Created by hellcat on 2/23/22.

#ifndef TURING_H
#define TURING_H

#include <iostream>
#include <string>
#include <sstream>
#include <initializer_list>
#include <vector>

namespace turing {

    struct command {
        std::string first_state;
        std::string second_state;
        char first_symbol;
        char second_symbol;
        char direction;
    };

    struct program {
        program() = delete;
        program(std::initializer_list<std::string> com);

        std::vector<command> m_commands;
    };

    class machine {
    public:
        machine() = delete;
        explicit machine(const std::string& init);
        void Attach(program& pr);
        std::string Run();

    private:
        std::string m_tape;
        std::string m_cur_state;
        int m_cur_index;
        program* m_program;
        bool m_attached;
    };
}

#endif //TURING_H
