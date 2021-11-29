//
// Created by Arief on 11/11/2021.
//

#include "../inc/loggers/console_logger.h"

lib::console_logger::console_logger():m_writer(nullptr) {}

lib::console_logger::console_logger(std::unique_ptr<writers::itext_writer> writer)
:m_writer(std::move(writer)){}

void lib::console_logger::print(std::string help_messages,std::vector<std::unique_ptr<arguments::iargument>> arguments) const {

    // Firstly, print help message if requested
    std::cout << help_messages;

    // Pretty-output table
    std::cout << "\nList of parsed arguments:\n" << std::endl;

    // Attempt to recognise arguments
    for (const auto &arg: arguments) {

        // Get a raw pointer from the unique pointer of the arguments
        arguments::iargument *raw_arg = arg.get();

        // Using 'dynamic cast' try to convert the correct pointer type
        if (auto *int_arg = dynamic_cast<lib::int_argument *>(raw_arg)) {
            *m_writer << int_arg;
        } else if (auto *double_arg = dynamic_cast<lib::double_argument *>(raw_arg)) {
            *m_writer << double_arg;
        } else if (auto *string_arg = dynamic_cast<lib::string_argument *>(raw_arg)) {
            *m_writer << string_arg;
        } else if (auto *flag = dynamic_cast<lib::bool_argument *>(raw_arg)) {
            *m_writer << flag;
        } else {
            throw std::logic_error("ID is not identified. Please check arguments.");
        }
    }
}
