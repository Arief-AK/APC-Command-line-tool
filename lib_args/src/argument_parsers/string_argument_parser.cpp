//
// Created by Arief on 10/24/2021.
//

#include "../inc/argument_parsers/string_argument_parser.h"

std::unique_ptr<arguments::iargument> lib::string_argument_parser::parse(std::string id, const char *string) const {

    // TODO: Check functionality
    int n;
    std::string_view sv(string);
    auto [ptr, ec] = std::from_chars(sv.data(),sv.data() + sv.size(),n);
    if(ec == std::errc()){
        return std::make_unique<string_argument>(std::move(id),string);
    }
    return nullptr;
}
