//
// Created by Arief on 10/15/2021.
//

#ifndef COMMAND_LINE_TOOL_IARGUMENT_H
#define COMMAND_LINE_TOOL_IARGUMENT_H

#include <string>
#include <memory>
#include <vector>

namespace arguments{
    class iargument{
    public:
        virtual const std::string& id() const = 0;
        virtual ~iargument() = default;
    };
}

#endif //COMMAND_LINE_TOOL_IARGUMENT_H
