#ifndef SOFTLOQ_UNICODE_ERROR_HPP
#define SOFTLOQ_UNICODE_ERROR_HPP

/**
 * @author Brandon Foster
 * @file error.hpp
 * @version 1.0.1
 * @brief Holds an error that occurs in a Unicode function.
 */

#include "softloq-unicode/macros.hpp"
#include <string>

namespace Softloq::Unicode
{
    /** @brief Unicode error handle. */
    struct SOFTLOQ_UNICODE_API Error
    {
        /** @brief The error message. */
        std::string message;
    };
}

#endif