//
// Created by Arief on 10/24/2021.
//

#include "../inc/argument_type/string_argument.h"

lib::string_argument::string_argument(std::string id, std::string value)
:m_id(std::make_unique<std::string>(id)), m_value(value){}

std::string lib::string_argument::value() {
    return m_value;
}

const std::string &lib::string_argument::id() const {
    return *m_id;
}

lib::string_argument::~string_argument() = default;
