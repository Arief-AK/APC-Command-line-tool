//
// Created by Arief on 10/15/2021.
//

#ifndef COMMAND_LINE_TOOL_INT_ARGUMENT_PARSER_H
#define COMMAND_LINE_TOOL_INT_ARGUMENT_PARSER_H

#include "../interfaces/iargument_parser.h"
#include "../inc/argument_type/int_argument.h"

namespace lib{
    class int_argument_parser : public arguments::iargument_parser{
    public:
        // Override the parse function of the 'iargument_parser'
        std::unique_ptr<arguments::iargument> parse(std::string id, const char* string) const override;
    };
}

#endif //COMMAND_LINE_TOOL_INT_ARGUMENT_PARSER_H
