//
// Created by Arief on 11/11/2021.
//

#ifndef COMMAND_LINE_TOOL_ILOGGER_H
#define COMMAND_LINE_TOOL_ILOGGER_H

#include <iostream>
#include <string>
#include "../inc/option_parser.h"
#include "../inc/interfaces/iargument.h"

namespace loggers{
    class ilogger{
    public:
        virtual void print(std::string help_messages,std::vector<std::unique_ptr<arguments::iargument>> arguments) const = 0;
        virtual ~ilogger() = default;
    };
}

#endif //COMMAND_LINE_TOOL_ILOGGER_H
