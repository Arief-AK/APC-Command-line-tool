//
// Created by Arief on 10/15/2021.
//

#include "../inc/argument_type/int_argument.h"

lib::int_argument::int_argument(std::string id, int value)
: m_id{std::make_unique<std::string>(id)},m_value(value){}

lib::int_argument::~int_argument() {
    m_value = 0;
    m_id = nullptr;
}

const std::string &lib::int_argument::id() const {
    return *m_id;
}
