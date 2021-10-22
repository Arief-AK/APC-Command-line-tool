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

bool options::option::parseable(const char *arg) const {
    // TODO: Implement if option is parse-able

    // Check if option requires arguments
    if (m_accept_arguments){

        // Go through the arguments
        if(arg){
            return true;
        }
    }
    return false;
}

std::unique_ptr<arguments::iargument> options::option::parse(const char *arg) const {
    return m_parser->parse(m_long,arg);
}
