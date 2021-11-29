//
// Created by Arief on 11/10/2021.
//

#include "../inc/option_parser_builder.h"

lib::option_parser_builder::option_parser_builder() :m_option_parser(nullptr){
    reset();
}

builders::ioption_parser_builder &lib::option_parser_builder::reset() {
    m_option_parser = std::make_unique<lib::option_parser>();
    return *this;
}

builders::ioption_parser_builder &
lib::option_parser_builder::with_option(std::string short_flag, std::string long_flag, std::string desc) {
    if(m_option_parser){
        m_option_parser->add_option(std::make_unique<options::option>(short_flag,long_flag,desc,0,std::make_unique<lib::bool_argument_parser>()));
    }
    return *this;
}

builders::ioption_parser_builder &
lib::option_parser_builder::with_int_option(std::string short_flag, std::string long_flag, std::string desc,
                                            int number_of_arguments) {
    if(m_option_parser){
        m_option_parser->add_option(std::make_unique<options::option>(short_flag,long_flag,desc,number_of_arguments,std::make_unique<lib::int_argument_parser>()));
    }
    return *this;
}

builders::ioption_parser_builder &
lib::option_parser_builder::with_int_option(std::string short_flag, std::string long_flag, std::string desc,
                                            int number_of_arguments, int min, int max) {
    if(m_option_parser){
        m_option_parser->add_option(std::make_unique<options::option>(short_flag,long_flag,desc,number_of_arguments,std::make_unique<lib::int_argument_parser>(),min,max));
    }
    return *this;
}

builders::ioption_parser_builder &
lib::option_parser_builder::with_dbl_option(std::string short_flag, std::string long_flag, std::string desc,
                                            int number_of_arguments) {
    if(m_option_parser){
        m_option_parser->add_option(std::make_unique<options::option>(short_flag,long_flag,desc,number_of_arguments,std::make_unique<lib::double_argument_parser>()));
    }
    return *this;
}

builders::ioption_parser_builder &
lib::option_parser_builder::with_dbl_option(std::string short_flag, std::string long_flag, std::string desc,
                                            int number_of_arguments, double min, double max) {
    if(m_option_parser){
        m_option_parser->add_option(std::make_unique<options::option>(short_flag,long_flag,desc,number_of_arguments,std::make_unique<lib::double_argument_parser>(),min,max));
    }
    return *this;
}

builders::ioption_parser_builder &
lib::option_parser_builder::with_text_option(std::string short_flag, std::string long_flag, std::string desc,
                                             int number_of_arguments) {
    if(m_option_parser){
        m_option_parser->add_option(std::make_unique<options::option>(short_flag,long_flag,desc,number_of_arguments,std::make_unique<lib::string_argument_parser>()));
    }
    return *this;
}

std::unique_ptr<lib::option_parser> lib::option_parser_builder::make() {
    return std::move(m_option_parser);
}

lib::option_parser_builder::~option_parser_builder() = default;
