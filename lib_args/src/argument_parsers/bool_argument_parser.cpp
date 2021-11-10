//
// Created by Arief on 11/10/2021.
//

#include "../inc/argument_parsers/bool_argument_parser.h"

std::unique_ptr<arguments::iargument> lib::bool_argument_parser::parse(std::string id, const char *string) const {
    if(string){
        return std::make_unique<lib::bool_argument>(std::move(id), true);
    }
    return nullptr;
}
