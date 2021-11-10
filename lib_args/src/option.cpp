//
// Created by Arief on 10/20/2021.
//

#include <stdexcept>
#include "../inc/option.h"

options::option::option(std::string short_flag, std::string long_flag, std::string desc,
                        int number_of_arguments,
                        std::unique_ptr<arguments::iargument_parser> parser)
        :m_short(short_flag), m_long(long_flag), m_desc(desc),
         m_num_arguments(number_of_arguments),
         m_parser(std::move(parser)){}

options::option::option(std::string short_flag, std::string long_flag, std::string desc,
                        int number_of_arguments,
                        std::unique_ptr<arguments::iargument_parser> parser,
                        std::initializer_list<int> range)
                        :m_short(short_flag), m_long(long_flag), m_desc(desc),
                        m_num_arguments(number_of_arguments),
                        m_parser(std::move(parser))
{
    m_range.insert(m_range.end(),range.begin(),range.end());
}

options::option::option(std::string short_flag, std::string long_flag, std::string desc,
                        int number_of_arguments,
                        std::unique_ptr<arguments::iargument_parser> parser,
                        std::initializer_list<double> range)
        :m_short(short_flag), m_long(long_flag), m_desc(desc),
         m_num_arguments(number_of_arguments),
         m_parser(std::move(parser))
{
    m_range.insert(m_range.end(),range.begin(),range.end());
}

const std::string &options::option::short_flag() const {
    return m_short;
}

const std::string &options::option::long_flag() const {
    return m_long;
}

int options::option::num_arguments() const {
    return m_num_arguments;
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
        return true;
    }
    return false;
}

std::pair<char**,std::vector<std::unique_ptr<arguments::iargument>>> options::option::parse(char* args[], int nargs) const {
    std::vector<std::unique_ptr<arguments::iargument>> parsed_arguments;

    // 'nargs' must be equal to this option's accepted amount of arguments (m_num_arguments)
    if(nargs < m_num_arguments){
        return {args,std::move(parsed_arguments)};
    }
    // Check if this option is a flag or command in regard to accepted amount of arguments
    else if(m_num_arguments == 0){

        parsed_arguments.push_back(m_parser->parse(m_long,*args));
        return {args,std::move(parsed_arguments)};
    }
    else{
        args++;

        for (int i = 0; i < m_num_arguments; ++i){
            // Argument parser is responsible for parsing the arguments of the option
            parsed_arguments.push_back(m_parser->parse(m_long,*args));
            args++;
        }

        return {args,std::move(parsed_arguments)};
    }
}
