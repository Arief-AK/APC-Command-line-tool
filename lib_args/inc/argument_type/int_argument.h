//
// Created by Arief on 10/15/2021.
//

#ifndef COMMAND_LINE_TOOL_INT_ARGUMENT_H
#define COMMAND_LINE_TOOL_INT_ARGUMENT_H

#include "interfaces/iargument.h"

namespace lib{
class int_argument : public arguments::iargument{
    public:
        int_argument(std::string id, int value);
        int value() const;
        virtual const std::string& id() const override;
        virtual ~int_argument() override;

    private:

        // Unique pointer of type 'string' to own the 'id' of the argument
        std::unique_ptr<std::string> m_id;
        int m_value;
    };
}

#endif //COMMAND_LINE_TOOL_INT_ARGUMENT_H
