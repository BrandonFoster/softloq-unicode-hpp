#ifndef SOFTLOQ_UNICODE_MACROS_HPP
#define SOFTLOQ_UNICODE_MACROS_HPP

/**
 * @author Brandon Foster
 * @file macros.hpp
 * @version 1.0.0
 * @brief Unicode Macros.
 */

/** @brief Maximum Unicode value. Any value greater is invalid Unicode. */
#define SOFTLOQ_UNICODE_LIMIT 0x10FFFF

// Static/Shared Build Macros

#if defined(_MSC_VER)
#define SOFTLOQ_UNICODE_EXPORT __declspec(dllexport)
#define SOFTLOQ_UNICODE_IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
#define SOFTLOQ_UNICODE_EXPORT __attribute__((visibility("default")))
#define SOFTLOQ_UNICODE_IMPORT
#endif

// For Standalone Builds

#if defined(SOFTLOQ_UNICODE_NO_API)
#define SOFTLOQ_UNICODE_API
#elif defined(SOFTLOQ_UNICODE_BUILD_API)
#define SOFTLOQ_UNICODE_API SOFTLOQ_UNICODE_EXPORT
#elif defined(SOFTLOQ_UNICODE_USE_API)
#define SOFTLOQ_UNICODE_API SOFTLOQ_UNICODE_IMPORT
#endif

// For Monolithic Builds

#ifndef SOFTLOQ_UNICODE_API
#if defined(SOFTLOQ_NO_API)
#define SOFTLOQ_UNICODE_API
#elif defined(SOFTLOQ_BUILD_API)
#define SOFTLOQ_UNICODE_API SOFTLOQ_UNICODE_EXPORT
#elif defined(SOFTLOQ_USE_API)
#define SOFTLOQ_UNICODE_API SOFTLOQ_UNICODE_IMPORT
#endif
#endif

// Static Build By Default

#ifndef SOFTLOQ_UNICODE_API
/** @brief Static/Shared Build Macro. */
#define SOFTLOQ_UNICODE_API
#endif

#endif