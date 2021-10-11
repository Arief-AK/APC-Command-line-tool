//
// Created by Arief on 10/7/2021.
//

#ifndef COMMAND_LINE_TOOL_IOPTION_PARSER_H
#define COMMAND_LINE_TOOL_IOPTION_PARSER_H

#include <string>

namespace options{
    class ioption_parser{
    public:

        enum class parameter_type{
            pt_none,
            pt_int,
            pt_float,
            pt_text
        };

        // Virtual function to make an option
        virtual ioption_parser& make_option(char short_flag, std::string long_flag, std::string description, parameter_type type) = 0;

        // Virtual destructor
        virtual ~ioption_parser() = default;

        // TODO: What needs to be returned from here...
        // Function to parse
        virtual void parse() = 0;
    };
}

#endif //COMMAND_LINE_TOOL_IOPTION_PARSER_H
