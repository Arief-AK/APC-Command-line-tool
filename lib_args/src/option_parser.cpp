//
// Created by Arief on 10/21/2021.
//

#include "../inc/option_parser.h"

lib::option_parser::option_parser()
:m_help_set{false},m_help_message{},m_options{}{}

void lib::option_parser::add_option(std::unique_ptr<options::option> new_option) {
    // Add option to vector in 'option_parser'
    m_options.push_back(std::move(new_option));
}

void lib::option_parser::print_all_options(const char *args) {
    if((std::string)args == "-h" || (std::string)args == "--help"){
        if(!m_help_set){
            m_help_set = true;
            m_help_message += "##########################################################################\n";
            m_help_message += "ARGUMENT FORMAT:\n\n";
            m_help_message += "./command_line_tool [option/flags]\n\n";
            m_help_message += "OPTION DESCRIPTIONS:\n\n";
            m_help_message += "--help This is an option to display all descriptions of options\n";
            for (auto &opt:m_options) {
                m_help_message += opt->long_flag()+" "+opt->desc()+'\n';
            }
            m_help_message += "\n##########################################################################\n";
        }
    }
}

std::vector<std::unique_ptr<arguments::iargument>> lib::option_parser::parse_option(char *args[], int nargs) {

    std::vector <std::unique_ptr<arguments::iargument>> parsed;

    // Set the 'end' pointer to the last character address
    const auto end = args + nargs;

    do {

        auto start_args = args;

        // Check if this is --help command
        print_all_options(*args);

        for (const auto &this_option: m_options) {

            // Check if this option is required to be parsed
            if (this_option->can_parse(*args)) {

                auto pair = this_option->parse(args, nargs);

                if (!pair.second.empty()) {

                    // Store the results if parsing was successful
                    for(auto& parsed_argument : pair.second){
                        parsed.push_back(std::move(parsed_argument));
                    }

                    // Calculate the amount of elements parsed
                    auto consumed_elements = args - pair.first;

                    // Set the correct number of arguments for next iteration
                    args = pair.first;
                    nargs -= static_cast<int>(consumed_elements);
                    break;
                }
            }
        }

        if(start_args == args){
            ++args;
            --nargs;
        }

    }while (args != end);
    return parsed;
}

std::string lib::option_parser::help_requested() {
    return m_help_message;
}
