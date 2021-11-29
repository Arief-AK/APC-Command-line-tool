#include <sstream>
#include <writers/console_writer.h>
#include "../inc/option_parser_builder.h"

int main(int argc, char *argv[]) {

    // Create a builder
    auto op = lib::option_parser_builder()
            .with_option("v", "verbose", "A test flag")
            .with_int_option("l", "level", "This option shows the level", 1,1,10)
            .with_dbl_option("m", "multiply","This option will multiply the 2 arguments together", 2,10.0,20.0)
            .with_text_option("s", "store", "This option will store 2 arguments together", 1)
            .make();

    // Parse all arguments passed from terminal
    auto arguments = op->parse_option(argv, argc);

    // Create an output
    auto console_output = lib::console_logger(std::make_unique<lib::console_writer>());
    console_output.print(op->get_help(),std::move(arguments));

    return 0;
}