//
// Created by Arief on 10/24/2021.
//

#ifndef COMMAND_LINE_TOOL_STRING_ARGUMENT_PARSER_H
#define COMMAND_LINE_TOOL_STRING_ARGUMENT_PARSER_H

#include "../interfaces/iargument_parser.h"
#include "../inc/argument_type/string_argument.h"

namespace lib{
    class string_argument_parser : public arguments::iargument_parser{
    public:
        std::unique_ptr<arguments::iargument> parse(std::string id, const char* string) const override;
    };
}

#endif //COMMAND_LINE_TOOL_STRING_ARGUMENT_PARSER_H