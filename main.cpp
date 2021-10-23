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

    // Parse all arguments passed from terminal
    auto arguments = optionParser.parse_option(argv, argc);

    // Attempt to recognise arguments
    for (const auto& arg: arguments){

        // Get a raw pointer from the unique pointer of the arguments
        arguments::iargument* raw_arg = arg.get();

        // Using 'dynamic cast' try to convert the correct pointer type
        if(auto* int_arg = dynamic_cast<lib::int_argument*>(raw_arg)){
            std::cout <<  int_arg->id() << ":" << int_arg->value();
        }
        else{
            std::cout << "\nUnidentified argument for id: " << arg->id();
        }
    }

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