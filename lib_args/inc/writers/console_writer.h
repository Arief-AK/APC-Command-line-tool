//
// Created by Arief on 11/11/2021.
//

#ifndef COMMAND_LINE_TOOL_CONSOLE_WRITER_H
#define COMMAND_LINE_TOOL_CONSOLE_WRITER_H

#include "../inc/interfaces/itext_writer.h"

namespace lib{
    class console_writer : public writers::itext_writer{
    public:

        console_writer();

        console_writer& operator<<(int value);
        console_writer& operator<<(double value);
        console_writer& operator<<(const char* literal);
        console_writer& operator<<(std::string string);

        console_writer& operator<<(lib::int_argument *arg) override;
        console_writer& operator<<(lib::double_argument *arg) override;
        console_writer& operator<<(lib::string_argument *arg) override;
        console_writer& operator<<(lib::bool_argument *arg) override;
};
}

#endif //COMMAND_LINE_TOOL_CONSOLE_WRITER_H
