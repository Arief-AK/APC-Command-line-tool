//
// Created by Arief on 10/17/2021.
//

#ifndef COMMAND_LINE_TOOL_STRING_ARGUMENT_H
#define COMMAND_LINE_TOOL_STRING_ARGUMENT_H

#include "interfaces/iargument.h"

namespace lib{
class string_argument : public arguments::iargument{
    public:
        string_argument(std::string id, strd::string value);
        std::string value();

    private:

        // Unique pointer of type 'string' to own the 'id' of the argument
        std::unique_ptr<std::string id> m_id;
        std::string m_value;
    };
}

#endif //COMMAND_LINE_TOOL_STRING_ARGUMENT_H
