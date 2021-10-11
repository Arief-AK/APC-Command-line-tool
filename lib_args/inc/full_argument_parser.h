//
// Created by Arief on 10/11/2021.
//

#ifndef COMMAND_LINE_TOOL_FULL_ARGUMENT_PARSER_H
#define COMMAND_LINE_TOOL_FULL_ARGUMENT_PARSER_H

#include <memory>
#include <unordered_map>
#include "flag_option.h"
#include "ioption_parser.h"

namespace lib{
    class full_argument_parser{
    public:
        // TODO: Create a full argument parser to be called by program
        full_argument_parser();

        // TODO: Add a parser to the 'accepted' option parsers
        void add_option(std::string option_name, std::unique_ptr<options::ioption_parser> option_parser);

        // TODO: Remove a parser from the 'accepted' parsers container
        void remove_option(std::string name);

        // TODO: Parse the initial arguments passed in by command line
        void parser_initial_arguments();

        // TODO: Go through 'accepted' parsers and match. Reference by 'parameter_type'

        // TODO: Let respective option parser handle parsing

    private:
        // TODO: Store 'accepted' (ioption_parser) option parsers in a container (map/dictionary)
        std::unordered_map<std::string, std::unique_ptr<options::ioption_parser>> m_option_parsers;
    };
}

#endif //COMMAND_LINE_TOOL_FULL_ARGUMENT_PARSER_H
