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

builders::ioption_parser_builder &lib::option_parser_builder::with_option(std::unique_ptr<options::option> new_option) {
    if(m_option_parser){
        m_option_parser->add_option(std::move(new_option));
    }
    return *this;
}

builders::ioption_parser_builder &
lib::option_parser_builder::with_int_option(std::unique_ptr<options::option> new_option) {
    if(m_option_parser){
        m_option_parser->add_option(std::move(new_option));
    }
    return *this;
}

builders::ioption_parser_builder &
lib::option_parser_builder::with_dbl_option(std::unique_ptr<options::option> new_option) {
    if(m_option_parser){
        m_option_parser->add_option(std::move(new_option));
    }
    return *this;
}

builders::ioption_parser_builder &
lib::option_parser_builder::with_text_option(std::unique_ptr<options::option> new_option) {
    if(m_option_parser){
        m_option_parser->add_option(std::move(new_option));
    }
    return *this;
}

std::unique_ptr<lib::option_parser> lib::option_parser_builder::make() {
    return std::move(m_option_parser);
}

lib::option_parser_builder::~option_parser_builder() = default;
