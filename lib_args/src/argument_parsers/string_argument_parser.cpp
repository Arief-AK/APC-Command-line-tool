//
// Created by Arief on 10/24/2021.
//

#include "../inc/argument_parsers/string_argument_parser.h"

std::unique_ptr<arguments::iargument>
lib::string_argument_parser::parse(std::string id, const char *string, const std::vector<double> vector) const {

    // TODO: Set vector with default limiters
    if(string && !vector.empty()){
        return std::make_unique<string_argument>(std::move(id),string);
    }
    return nullptr;
}
