//
// Created by Arief on 11/11/2021.
//

#ifndef COMMAND_LINE_TOOL_CONSOLE_LOGGER_H
#define COMMAND_LINE_TOOL_CONSOLE_LOGGER_H

#include "../inc/interfaces/ilogger.h"
#include "../inc/interfaces/itext_writer.h"
namespace lib {
    class console_logger : public loggers::ilogger {
    public:
        console_logger();
        console_logger(std::unique_ptr<writers::itext_writer> writer);
        virtual void print(std::string help_messages,std::vector<std::unique_ptr<arguments::iargument>> arguments) const override;
        ~console_logger() override = default;

    private:
        std::unique_ptr<writers::itext_writer> m_writer;
    };
}

#endif //COMMAND_LINE_TOOL_CONSOLE_LOGGER_H
