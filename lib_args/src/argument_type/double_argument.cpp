//
// Created by Arief on 10/17/2021.
//

#include "../inc/argument_type/double_argument.h"

lib::double_argument::double_argument(std::string id, double value)
:m_id(std::make_unique<std::string>(id)),m_value(value){}

const std::string &lib::double_argument::id() const {
    return *m_id;
}

lib::double_argument::~double_argument() {
    m_value = 0.0;
    m_id = nullptr;
}
