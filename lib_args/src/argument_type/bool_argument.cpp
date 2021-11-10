//
// Created by Arief on 11/10/2021.
//

#include "../inc/argument_type/bool_argument.h"

lib::bool_argument::bool_argument(std::string id, bool value)
:m_id{std::make_unique<std::string>(id)},m_value(value){}

bool lib::bool_argument::value() const {
    return m_value;
}

const std::string &lib::bool_argument::id() const {
    return *m_id;
}

lib::bool_argument::~bool_argument() = default;
