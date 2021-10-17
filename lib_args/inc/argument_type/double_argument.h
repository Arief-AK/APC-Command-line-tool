//
// Created by Arief on 10/15/2021.
//

#ifndef COMMAND_LINE_TOOL_FLAG_OPTION_H
#define COMMAND_LINE_TOOL_FLAG_OPTION_H

#include "interfaces/iargument.h"

namespace lib{
    class double_argument : public arguments::iargument{
    public:
        double_argument(std::string id, double value);
        virtual const std::string& id() const override;
        ~double_argument();

    private:
        // Unique pointer of type 'string' to own the 'id' of the argument
        std::unique_ptr<std::string> m_id;
        double m_value;
    };
}

#endif //COMMAND_LINE_TOOL_FLAG_OPTION_H
