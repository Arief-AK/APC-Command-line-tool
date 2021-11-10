#include <sstream>
#include <argument_parsers/int_argument_parser.h>
#include "argument_parsers/double_argument_parser.h"
#include "argument_parsers/string_argument_parser.h"
#include "argument_parsers/bool_argument_parser.h"
#include "../inc/option.h"
#include "../inc/option_parser.h"

int main(int argc, char *argv[]) {

    // Make an option parser
    lib::option_parser optionParser;

    // Add a flag to the parser
    optionParser.add_option(std::make_unique<options::option>("-v",
                                                              "--verbose",
                                                              "A test flag",
                                                              0,
                                                              std::make_unique<lib::bool_argument_parser>()));

    // Add an int option to the parser
    optionParser.add_option(std::make_unique<options::option>("-l",
                                                              "--level",
                                                              "This option shows the level",
                                                              1,
                                                              std::make_unique<lib::int_argument_parser>()));

    // Add a double option to the parser
    optionParser.add_option(std::make_unique<options::option>("-m",
                                                              "--multiply",
                                                              "This option will multiply the 2 arguments together",
                                                              2,
                                                              std::make_unique<lib::double_argument_parser>()));

    // Add a string option to the parser
    optionParser.add_option(std::make_unique<options::option>("-s",
                                                              "--store",
                                                              "This option will store 2 arguments together",
                                                              1,
                                                              std::make_unique<lib::string_argument_parser>()));

    // Print all accepted options from the parser
    optionParser.print_all_options();

    // Parse all arguments passed from terminal
    auto arguments = optionParser.parse_option(argv, argc);

    // Pretty-output table
    std::cout << "\nList of parsed arguments:\n" << std::endl;

    // Attempt to recognise arguments
    for (const auto& arg: arguments){

        // Get a raw pointer from the unique pointer of the arguments
        arguments::iargument* raw_arg = arg.get();

        // Using 'dynamic cast' try to convert the correct pointer type
        if(auto* int_arg = dynamic_cast<lib::int_argument*>(raw_arg)){
            std::cout <<  int_arg->id() << ":" << int_arg->value() << '\n';
        }else if(auto* double_arg = dynamic_cast<lib::double_argument*>(raw_arg)){
            std::cout <<  double_arg->id() << ":" << double_arg->value() << '\n';
        }else if(auto* string_arg = dynamic_cast<lib::string_argument*>(raw_arg)){
            std::cout <<  string_arg->id() << ":" << string_arg->value() << '\n';
        }else if(auto* flag = dynamic_cast<lib::bool_argument*>(raw_arg)){
            auto value = flag->value()? "True":"False";
            std::cout <<  flag->id() << ":" << value << " (FLAG)" << '\n';
        }
        else{
            std::cout << "\nUnidentified argument for id: " << arg->id();
        }
    }

    std::cout << "\nDone!";
    return 0;
}