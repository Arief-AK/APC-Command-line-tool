//
// Created by Arief on 10/15/2021.
//

#ifndef COMMAND_LINE_TOOL_OPTION_H
#define COMMAND_LINE_TOOL_OPTION_H

#include <string>
#include <memory>
#include "iargument_parser.h"

namespace options{

    class option{
    public:
        option(std::string short_flag,
               std::string long_flag,
               std::string desc,
               std::unique_ptr<arguments::iargument_parser> parser);

        // Virtual destructor, will be implemented by concrete option classes
        virtual ~option() = default;

        // Get member variables
        const std::string& short_flag() const;
        const std::string& long_flag() const;
        const std::string& desc() const;

        // virtual method for help as different option have different help
        virtual std::string help() const;

        // Virtual method to check if option requires to parser its arguments
        virtual bool parseable(const char* arg) const;

        // Virtual method to inject an argument to parse
        virtual std::unique_ptr<argument> parse(const char* arg) const;

    private:
        std::string m_short;
        std::string m_long;
        std::string m_desc;
        std::unique_ptr<arguments::iargument_parser> m_parser;
    };
}

#endif //COMMAND_LINE_TOOL_OPTION_H
