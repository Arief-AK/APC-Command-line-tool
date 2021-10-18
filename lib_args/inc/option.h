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
               std::unique_ptr<arguments::iargument_parser> parser)
               :m_short(short_flag), m_long(long_flag), m_desc(desc), m_parser(std::move(parser)) {}

        // Get member variable short_flag
        const std::string& short_flag() const {
            return m_short;
        }
        // Get member variable long_flag
        const std::string& long_flag() const {
            return m_long;
        }

        // Get member variable description
        const std::string& desc() const {
            return m_desc;
        }

        // virtual method for help as different option have different help
        virtual std::string help() const;

        // Virtual method to check if option requires to parser its arguments
        virtual bool parseable(const char* arg) const;

        // Virtual method to inject an argument to parse
        virtual std::unique_ptr<arguments::iargument> parse(const char* arg) const{
            return m_parser->parse(m_long,arg);
        }

        // Virtual destructor, will be implemented by concrete option classes
        virtual ~option() = default;

    private:
        std::string m_short;
        std::string m_long;
        std::string m_desc;
        std::unique_ptr<arguments::iargument_parser> m_parser;
    };
}

#endif //COMMAND_LINE_TOOL_OPTION_H
