//
// Created by Arief on 10/11/2021.
//

#include "full_argument_parser.h"

lib::full_argument_parser::full_argument_parser() :m_option_parsers{} {}

void lib::full_argument_parser::add_option(std::string option_name, std::unique_ptr<options::ioption_parser> option_parser){
m_option_parsers.emplace(option_name,std::move(option_parser));
}

void lib::full_argument_parser::remove_option(std::string name) {
    m_option_parsers.erase(name);
}
