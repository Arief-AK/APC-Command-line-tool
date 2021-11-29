//
// Created by Arief on 11/11/2021.
//

#include "../inc/writers/console_writer.h"

lib::console_writer::console_writer()= default;

lib::console_writer &lib::console_writer::operator<<(int value) {
    std::cout << value;
    return *this;
}

lib::console_writer &lib::console_writer::operator<<(double value) {
    std::cout << value;
    return *this;
}

lib::console_writer &lib::console_writer::operator<<(const char* literal) {
    std::cout << literal;
    return *this;
}

lib::console_writer &lib::console_writer::operator<<(std::string arg) {
    std::cout << arg;
    return *this;
}

lib::console_writer &lib::console_writer::operator<<(lib::int_argument *arg) {
    std::cout << arg->id() << ":" << arg->value() << '\n';
    return *this;
}

lib::console_writer &lib::console_writer::operator<<(lib::double_argument *arg) {
    std::cout << arg->id() << ":" << arg->value() << '\n';
    return *this;
}

lib::console_writer &lib::console_writer::operator<<(lib::string_argument *arg) {
    std::cout << arg->id() << ":" << arg->value() << '\n';
    return *this;
}

lib::console_writer &lib::console_writer::operator<<(lib::bool_argument *arg) {
    auto value = arg->value() ? "True" : "False";
    std::cout << arg->id() << ":" << value << '\n';
    return *this;
}
