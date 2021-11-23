//
// Created by Arief on 11/10/2021.
//

#ifndef COMMAND_LINE_TOOL_OPTION_PARSER_BUILDER_H
#define COMMAND_LINE_TOOL_OPTION_PARSER_BUILDER_H

#include <argument_parsers/int_argument_parser.h>
#include "argument_parsers/double_argument_parser.h"
#include "argument_parsers/string_argument_parser.h"
#include "argument_parsers/bool_argument_parser.h"

#include "../inc/interfaces/ioption_parser_builder.h"
#include "../inc/option_parser.h"

namespace lib{
    class option_parser_builder : public builders::ioption_parser_builder{
    public:

        option_parser_builder();

        ioption_parser_builder& reset() override;
        ioption_parser_builder& with_option(std::string short_flag,
                                                    std::string long_flag,
                                                    std::string desc,
                                                    int number_of_arguments) override;

        ioption_parser_builder& with_int_option(std::string short_flag,
                                                std::string long_flag,
                                                std::string desc,
                                                int number_of_arguments) override;

        ioption_parser_builder& with_int_option(std::string short_flag,
                                                std::string long_flag,
                                                std::string desc,
                                                int number_of_arguments,
                                                int min, int max) override;

        ioption_parser_builder& with_dbl_option(std::string short_flag,
                                                std::string long_flag,
                                                std::string desc,
                                                int number_of_arguments) override;

        ioption_parser_builder& with_dbl_option(std::string short_flag,
                                                std::string long_flag,
                                                std::string desc,
                                                int number_of_arguments,
                                                double min, double max) override;

        ioption_parser_builder& with_text_option(std::string short_flag,
                                                 std::string long_flag,
                                                 std::string desc,
                                                 int number_of_arguments) override;

        std::unique_ptr<lib::option_parser> make() override;
        ~option_parser_builder() override;

    private:

        // A unique pointer to store the actual option parser
        std::unique_ptr<lib::option_parser> m_option_parser;
    };
}

#endif //COMMAND_LINE_TOOL_OPTION_PARSER_BUILDER_H
