//
// Created by Arief on 10/21/2021.
//

#include "../inc/option_parser.h"

lib::option_parser::option_parser() :m_options{}{}

void lib::option_parser::add_option(std::unique_ptr<options::option> new_option) {
    // Add option to vector in 'option_parser'
    m_options.push_back(std::move(new_option));
}

void lib::option_parser::print_all_options() {

    std::cout << "\nList of accepted options:\n" << std::endl;

    for (auto& option: m_options) {
        std::cout << option->desc() << '\n';
    }
}

int lib::option_parser::get_arg_limit(char *args[],std::string long_flag) const {

    auto arg_counter {0};
    auto searching {true};

    while(searching){
        //args++;
        arg_counter++;

        if(args == nullptr){
            searching = false;
        }

        for (auto& this_option:m_options){
            if(this_option->can_parse(*args) && this_option->long_flag() != long_flag){
                searching = false;
            }
        }

        args++;
    }

    return arg_counter;
}

std::vector<std::unique_ptr<arguments::iargument>> lib::option_parser::parse_option(char *args[], int nargs) const {

    std::vector <std::unique_ptr<arguments::iargument>> parsed;

    // Set the 'end' pointer to the last character address
    const auto end = args + nargs;

    do {

        auto start_args = args;

        // TODO: Check if this is --help command
        // TODO: If help then
        // print_all_options();

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
