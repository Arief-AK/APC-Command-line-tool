//
// Created by Arief on 10/18/2021.
//

#ifndef COMMAND_LINE_TOOL_OPTION_PARSER_H
#define COMMAND_LINE_TOOL_OPTION_PARSER_H

#include <vector>
#include <memory>

#include "../inc/option.h"
#include "../inc/interfaces/iargument.h"

namespace lib{
    class option_parser{
    public:
        // Function to add an option to the 'option_parser'
        void add_option(std::unique_ptr<options::option> new_option);

        // Function that returns a vector of parsed arguments
        std::vector<std::unique_ptr<arguments::iargument>> parse_option(char *args[], int nargs) const;
    private:
        // A vector that stores injected options
        std::vector<std::unique_ptr<options::option>> m_options;
    };
}

#endif //COMMAND_LINE_TOOL_OPTION_PARSER_H
