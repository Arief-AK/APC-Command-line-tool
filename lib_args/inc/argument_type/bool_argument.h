//
// Created by Arief on 11/10/2021.
//

#ifndef COMMAND_LINE_TOOL_BOOL_ARGUMENT_H
#define COMMAND_LINE_TOOL_BOOL_ARGUMENT_H

#include "interfaces/iargument.h"

namespace lib{
    class bool_argument : public arguments::iargument{
    public:
        bool_argument(std::string id, bool value);
        bool value() const;
        virtual const std::string& id() const override;
        virtual ~bool_argument() override;

    private:

        // Unique pointer of type 'string' to own the 'id' of the argument
        std::unique_ptr<std::string> m_id;
        bool m_value;
    };
}

#endif //COMMAND_LINE_TOOL_BOOL_ARGUMENT_H