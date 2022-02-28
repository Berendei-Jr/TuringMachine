// Copyright 2022 Andrey Vedeneev vedvedved2003@gmail.com

#include "Turing.h"

turing::program::program(std::initializer_list<std::string> com) {
    for (auto& it : com)
    {
        std::stringstream stream(it);
        std::string fs, ss;
        char fsy, ssy, dir;
        stream >> fs;
        stream >> fsy;

        char ch;
        stream >> ch;
        if (ch != '-')
        {
            throw std::runtime_error("Wrong command style!\nExample: q0 a - q1 b R");
        }

        stream >> ss;
        stream >> ssy;
        stream >> dir;
        m_commands.push_back( command{fs, ss, fsy, ssy, dir} );
    }
}

turing::machine::machine(const std::string& init) {
    m_tape = "";
    for (int i = 0; i < 500; ++i) {
        m_tape.push_back('/');
    }
    m_tape.append(init);
    for (int i = 0; i < 500; ++i) {
        m_tape.push_back('/');
    }

    m_cur_state = "q0";
    m_cur_index = 500;
    m_attached = false;
    m_program = nullptr;
}

void turing::machine::Attach(turing::program &pr) {
    m_program = &pr;
    m_attached = true;
}

std::string turing::machine::Run() {
    if (!m_attached)
    {
        throw std::runtime_error("You need to attach a program to the machine first!\n");
    }

    bool stop = false;
    while (!stop)
    {
        if ((m_cur_index == m_tape.size() - 1) || (m_cur_index == 0))
            throw std::runtime_error("Tape overflow");
        stop = true;
        for (auto& it : (*m_program).m_commands)
        {
            if (it.first_state == m_cur_state && ((it.first_symbol == m_tape[m_cur_index]) || it.first_symbol == '%') )
            {
                stop = false;
                m_cur_state = it.second_state;
                if (it.second_symbol != '%')
                    m_tape[m_cur_index] = it.second_symbol;
                if (it.direction == 'R') {
                    m_cur_index++;
                } else if (it.direction == 'L') {
                    m_cur_index--;
                }
                break;
            }

        }
    }

    int begin = 0;
    for (int i = 0; i < m_tape.size(); i++)
    {
        if (m_tape[i] != '/')
        {
            begin = i;
            break;
        }
    }

    std::string result;
    for (int i = begin; i < m_tape.size(); i++)
    {
        if (m_tape[i] != '/')
            result.push_back(m_tape[i]);
        else
            break;
    }
    return result;
}
