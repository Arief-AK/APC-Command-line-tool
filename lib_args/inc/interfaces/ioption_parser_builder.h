//
// Created by Arief on 11/10/2021.
//

#ifndef COMMAND_LINE_TOOL_IOPTION_BUILDER_H
#define COMMAND_LINE_TOOL_IOPTION_BUILDER_H

#include <memory>
#include "../inc/option.h"
#include "../inc/option_parser.h"

namespace builders{
    class ioption_parser_builder{
    public:
        virtual ioption_parser_builder& reset() = 0;
        virtual ioption_parser_builder& with_option(std::unique_ptr<options::option> new_option) = 0;
        virtual ioption_parser_builder& with_int_option(std::unique_ptr<options::option> new_option) = 0;
        virtual ioption_parser_builder& with_dbl_option(std::unique_ptr<options::option> new_option) = 0;
        virtual ioption_parser_builder& with_text_option(std::unique_ptr<options::option> new_option) = 0;
        virtual std::unique_ptr<lib::option_parser> make() = 0;
        virtual ~ioption_parser_builder() = default;
    };
}

#endif //COMMAND_LINE_TOOL_IOPTION_BUILDER_H
