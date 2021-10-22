#include <sstream>
#include <argument_parsers/int_argument_parser.h>
#include "../inc/option.h"
#include "../inc/option_parser.h"

int main(int argc, char *argv[]) {

    std::ostringstream oss{};
    for (int arg_no = 0; arg_no < argc; ++ arg_no){
        oss << argv[arg_no] << ' ';
    }

    // Make an option parser
    lib::option_parser optionParser;

    // Add an option to the parser
    optionParser.add_option(std::make_unique<options::option>("v",
                                                              "verbose",
                                                              "A test flag",
                                                              false,
                                                              std::make_unique<lib::int_argument_parser>()));

    // Print all accepted options from the parser
    optionParser.print_all_options();
    std::cout << "Done!";

    /*add_option({'v', "verbose", "prints verbose diagnostics", false, pt_none});
    add_option({'l', "level", "sets compression level (0.0-1.0)", true, pt_float});
    add_option({'i', "input", "input file name", true, pt_text});
    add_option({'o', "output", "output file name", true, pt_text});
    add_option({'s', "size", "dictionary size in kb (1-1000)", true, pt_int});

    auto arguments = get_parser().parse(oss.str());

    program prog{arguments};

    prog.run();*/

    return 0;
}