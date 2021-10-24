//
// Created by Arief on 10/15/2021.
//

#ifndef COMMAND_LINE_TOOL_OPTION_H
#define COMMAND_LINE_TOOL_OPTION_H

#include <string>
#include <memory>
#include "interfaces/iargument_parser.h"

namespace options{

    class option{
    public:

        option(std::string short_flag,
               std::string long_flag,
               std::string desc,
               bool accept_arguments,
               std::unique_ptr<arguments::iargument_parser> parser);

        // Get member variable short_flag
        const std::string& short_flag() const;

        // Get member variable long_flag
        const std::string& long_flag() const;

        // Get member variable description
        const std::string& desc() const;

        // Virtual method that displays information of the 'flag' or 'command'
        virtual std::string help() const;

        // Virtual method that checks if the option is a 'flag' or 'command'
        virtual bool can_parse(const char* arg) const;

        // Virtual method that returns parsed argument(s)
        virtual std::unique_ptr<arguments::iargument> parse(const char* arg) const;

        // Virtual destructor, implemented by the parent class
        virtual ~option() = default;

    private:
        std::string m_short;
        std::string m_long;
        std::string m_desc;
        bool m_accept_arguments;
        std::unique_ptr<arguments::iargument_parser> m_parser;
    };
}

#endif //COMMAND_LINE_TOOL_OPTION_H
