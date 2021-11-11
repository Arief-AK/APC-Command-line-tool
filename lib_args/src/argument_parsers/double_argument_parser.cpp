//
// Created by Arief on 10/17/2021.
//

#include "../inc/argument_parsers/double_argument_parser.h"

std::unique_ptr<arguments::iargument>
lib::double_argument_parser::parse(std::string id, const char *string, const std::vector<double> vector) const
{
    int n;
    std::string_view sv(string);
    auto [ptr, ec] = std::from_chars(sv.data(),sv.data() + sv.size(),n);
    if(ec == std::errc()){

        auto argument = std::make_unique<double_argument>(std::move(id),n);
        auto arg_val = argument->value();

        if(arg_val > vector[0] && arg_val < vector[1]){
            return argument;
        }
        else{
            throw std::logic_error("Argument is not within range limiters");
        }
    }
    return nullptr;
}