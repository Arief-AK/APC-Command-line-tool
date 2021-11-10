//
// Created by Arief on 11/10/2021.
//

#ifndef COMMAND_LINE_TOOL_OPTION_PARSER_BUILDER_H
#define COMMAND_LINE_TOOL_OPTION_PARSER_BUILDER_H

#include "../inc/interfaces/ioption_parser_builder.h"
#include "../inc/option_parser.h"

namespace lib{
    class option_parser_builder : public builders::ioption_parser_builder{
    public:

        option_parser_builder();

        ioption_parser_builder& reset() override;
        ioption_parser_builder& with_option(std::unique_ptr<options::option> new_option) override;
        ioption_parser_builder& with_int_option(std::unique_ptr<options::option> new_option) override;
        ioption_parser_builder& with_dbl_option(std::unique_ptr<options::option> new_option) override;
        ioption_parser_builder& with_text_option(std::unique_ptr<options::option> new_option) override;
        std::unique_ptr<lib::option_parser> make() override;
        ~option_parser_builder() override;

    private:

        // A unique pointer to store the actual option parser
        std::unique_ptr<lib::option_parser> m_option_parser;
    };
}

#endif //COMMAND_LINE_TOOL_OPTION_PARSER_BUILDER_H
