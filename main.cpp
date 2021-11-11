#include <sstream>
#include <argument_parsers/int_argument_parser.h>
#include "argument_parsers/double_argument_parser.h"
#include "argument_parsers/string_argument_parser.h"
#include "argument_parsers/bool_argument_parser.h"
#include "../inc/option_parser_builder.h"

int main(int argc, char *argv[]) {

    // Create a builder
    auto op = lib::option_parser_builder()
            .with_option(std::make_unique<options::option>("-v", "--verbose", "A test flag", 0,std::make_unique<lib::bool_argument_parser>()))
            .with_int_option(std::make_unique<options::option>("-l", "--level", "This option shows the level", 1,std::make_unique<lib::int_argument_parser>(),1,10))
            .with_dbl_option(std::make_unique<options::option>("-m", "--multiply","This option will multiply the 2 arguments together", 2,std::make_unique<lib::double_argument_parser>(),10.0,20.0))
            .with_text_option(std::make_unique<options::option>("-s", "--store", "This option will store 2 arguments together", 1,std::make_unique<lib::string_argument_parser>()))
            .make();

    // Parse all arguments passed from terminal
    auto arguments = op->parse_option(argv, argc);

    // Pretty-output table
    std::cout << "\nList of parsed arguments:\n" << std::endl;

    // Attempt to recognise arguments
    for (const auto &arg: arguments) {

        // Get a raw pointer from the unique pointer of the arguments
        arguments::iargument *raw_arg = arg.get();

        // Using 'dynamic cast' try to convert the correct pointer type
        if (auto *int_arg = dynamic_cast<lib::int_argument *>(raw_arg)) {
            std::cout << int_arg->id() << ":" << int_arg->value() << '\n';
        } else if (auto *double_arg = dynamic_cast<lib::double_argument *>(raw_arg)) {
            std::cout << double_arg->id() << ":" << double_arg->value() << '\n';
        } else if (auto *string_arg = dynamic_cast<lib::string_argument *>(raw_arg)) {
            std::cout << string_arg->id() << ":" << string_arg->value() << '\n';
        } else if (auto *flag = dynamic_cast<lib::bool_argument *>(raw_arg)) {
            auto value = flag->value() ? "True" : "False";
            std::cout << flag->id() << ":" << value << " (FLAG)" << '\n';
        } else {
            std::cout << "\nUnidentified argument for id: " << arg->id();
        }
    }

    std::cout << "\nDone!";
    return 0;
}