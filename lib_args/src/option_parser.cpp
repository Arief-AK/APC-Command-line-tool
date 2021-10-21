//
// Created by Arief on 10/21/2021.
//

#include "../inc/option_parser.h"

void lib::option_parser::add_option(std::unique_ptr<options::option> new_option) {
    // Add option to vector in 'option_parser'
    m_options.push_back(std::move(new_option));
}

std::vector<std::unique_ptr<arguments::iargument>> lib::option_parser::parse_option(char **args, int nargs) const
{
    // Temporary vector to store parsed arguments
    std::vector<std::unique_ptr<arguments::iargument>> parsed;

    for (int i = 0; i < nargs; ++i){
        for (const auto& this_option : m_options){
            // Check if this option is required to be parsed
            if(this_option->parseable(args[i])){

                ++i;

                // Let it parse the arguments
                if(auto value = this_option->parse(args[i])){
                    // Store the results if parsing was successful
                    parsed.push_back(std::move(value));
                }

            }
        }
    }
    return parsed;
}
