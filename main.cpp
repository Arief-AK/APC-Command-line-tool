#include <sstream>
#include <argument_parsers/int_argument_parser.h>
#include <writers/console_writer.h>
#include "argument_parsers/double_argument_parser.h"
#include "argument_parsers/string_argument_parser.h"
#include "argument_parsers/bool_argument_parser.h"
#include "../inc/option_parser_builder.h"
#include "../inc/loggers/console_logger.h"

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
    auto console_output = lib::console_logger(std::make_unique<lib::console_writer>());
    console_output.print(std::move(arguments));
    std::cout << "\nDone!";

    return 0;
}