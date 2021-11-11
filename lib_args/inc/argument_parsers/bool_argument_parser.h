//
// Created by Arief on 11/10/2021.
//

#ifndef COMMAND_LINE_TOOL_BOOL_ARGUMENT_PARSER_H
#define COMMAND_LINE_TOOL_BOOL_ARGUMENT_PARSER_H

#include "../inc/interfaces/iargument_parser.h"
#include "../inc/argument_type/bool_argument.h"
namespace lib {
    class bool_argument_parser : public arguments::iargument_parser {
    public:
        // Override the parse function of the 'iargument_parser'
        std::unique_ptr<arguments::iargument>
        parse(std::string id, const char *string, std::vector<double> vector) const override;
    };
}

#endif //COMMAND_LINE_TOOL_BOOL_ARGUMENT_PARSER_H
