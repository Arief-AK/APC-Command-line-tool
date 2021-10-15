//
// Created by Arief on 10/15/2021.
//

#ifndef COMMAND_LINE_TOOL_ARGUMENT_H
#define COMMAND_LINE_TOOL_ARGUMENT_H

#include <string>

namespace lib{

    class argument{
    public:
        argument(std::string id);
        const std::string& id() const;
        virtual ~argument() = default;

    private:
        std::string m_id;
    };
}

#endif //COMMAND_LINE_TOOL_ARGUMENT_H
