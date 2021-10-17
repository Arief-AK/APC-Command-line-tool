//
// Created by Arief on 10/7/2021.
//

#ifndef COMMAND_LINE_TOOL_IARGUMENT_PARSER_H
#define COMMAND_LINE_TOOL_IARGUMENT_PARSER_H

#include <string>
#include <memory>
#include <charconv>
#include "iargument.h"

namespace arguments{
    class iargument_parser{
    public:
        virtual std::unique_ptr<arguments::iargument> parse(std::string id, const char* arg) const = 0;
        virtual ~iargument_parser() = default;
    };
}

#endif //COMMAND_LINE_TOOL_IARGUMENT_PARSER_H
