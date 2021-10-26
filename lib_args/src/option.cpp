//
// Created by Arief on 10/20/2021.
//

#include "../inc/option.h"

options::option::option(std::string short_flag, std::string long_flag, std::string desc,
                        bool accept_arguments, std::unique_ptr<arguments::iargument_parser> parser)
                        :m_short(short_flag), m_long(long_flag), m_desc(desc), m_accept_arguments(accept_arguments),
                        m_parser(std::move(parser)) {}

const std::string &options::option::short_flag() const {
    return m_short;
}

const std::string &options::option::long_flag() const {
    return m_long;
}

const std::string &options::option::desc() const {
    return m_desc;
}

std::string options::option::help() const {
    return std::string{"Child classes can implement this function"};
}

bool options::option::can_parse(const char *arg) const {

    // Check if 'arg' matches this option's short or long-flag
    if(arg == m_long || arg == m_short){

        // Return true if matches flag
        return true;
    }
    return false;
}

std::unique_ptr<arguments::iargument> options::option::parse(const char *arg) const {
    // Argument parser is responsible for parsing the arguments of the option
    return m_parser->parse(m_long,arg);
}
