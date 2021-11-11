//
// Created by Arief on 11/11/2021.
//

#ifndef COMMAND_LINE_TOOL_ITEXT_WRITER_H
#define COMMAND_LINE_TOOL_ITEXT_WRITER_H

#include <iostream>
#include "../inc/argument_type/int_argument.h"
#include "../inc/argument_type/bool_argument.h"
#include "../inc/argument_type/double_argument.h"
#include "../inc/argument_type/string_argument.h"

namespace writers{
    class itext_writer{
    public:
        virtual itext_writer& operator<<(lib::int_argument *arg) = 0;
        virtual itext_writer& operator<<(lib::double_argument *arg) = 0;
        virtual itext_writer& operator<<(lib::string_argument *arg) = 0;
        virtual itext_writer& operator<<(lib::bool_argument *arg) = 0;
        virtual ~itext_writer() = default;
    };
}

#endif //COMMAND_LINE_TOOL_ITEXT_WRITER_H
