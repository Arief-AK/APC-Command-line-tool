//
// Created by Arief on 10/17/2021.
//

#ifndef COMMAND_LINE_TOOL_STRING_ARGUMENT_H
#define COMMAND_LINE_TOOL_STRING_ARGUMENT_H

#include "interfaces/iargument.h"

namespace lib{
class string_argument : public arguments::iargument{
    public:
        string_argument(std::string id, std::string value);

        // TODO: Remove this temporary function
        std::string value();

        virtual const std::string& id() const override;
        virtual ~string_argument() override;

    private:

        // Unique pointer of type 'string' to own the 'id' of the argument
        std::unique_ptr<std::string> m_id;
        std::string m_value;
    };
}

#endif //COMMAND_LINE_TOOL_STRING_ARGUMENT_H
