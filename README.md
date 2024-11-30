[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
### Version 1.0.3
# About
Softloq Software C++ headers for Unicode functions.



# Usage Example
## Codepoint to UTF-8 String
### Appending a single byte codepoint to a UTF-8 string.
```cpp
#include <softloq-unicode/unicode.hpp>

int main()
{
    char32_t codepoint = 'A';
    std::string utf8;

    Softloq::Unicode::convertCodepointToUTF8(codepoint, utf8);

    std::cout << utf8 << "\n"; // "A"
}
```

### Appending a two byte codepoint to a UTF-8 string.
```cpp
#include <softloq-unicode/unicode.hpp>

int main()
{
    char32_t codepoint =  0xA9; // Copyright Symbol
    std::string utf8;

    Softloq::Unicode::convertCodepointToUTF8(codepoint, utf8);

    std::cout << utf8 << "\n"; // "©" if unicode supported in console.
}
```

### Appending a three byte codepoint to a UTF-8 string.
```cpp
#include <softloq-unicode/unicode.hpp>

int main()
{
    char32_t codepoint =  0x2211; // Capital Sigma Symbol
    std::string utf8;

    Softloq::Unicode::convertCodepointToUTF8(codepoint, utf8);

    std::cout << utf8 << "\n"; // "∑" if unicode supported in console.
}
```

### Appending a four byte codepoint to a UTF-8 string.
```cpp
#include <softloq-unicode/unicode.hpp>

int main()
{
    char32_t codepoint =  0x1F610; // Neutral Face Emoji Symbol
    std::string utf8;

    Softloq::Unicode::convertCodepointToUTF8(codepoint, utf8);

    std::cout << utf8 << "\n"; // "😐" if unicode supported in console.
}
```

## UTF-8 String to Codepoint
### UTF-8 string to a single byte codepoint.
```cpp
#include <softloq-unicode/unicode.hpp>

int main()
{
    std::string utf8 = "A";
    char32_t codepoint;
    size_t byte_count;

    Softloq::Unicode::convertUTF8ToCodepoint(utf8, codepoint, byte_count);

    std::cout << "0x" << std::hex << static_cast<int>(codepoint) << "\n"; // 0x41
    std::cout << byte_count << "\n"; // 1
}
```

### UTF-8 string to a two byte codepoint.
```cpp
#include <softloq-unicode/unicode.hpp>

int main()
{
    std::string utf8 = "©"; // Copyright Symbol
    char32_t codepoint;
    size_t byte_count;

    Softloq::Unicode::convertUTF8ToCodepoint(utf8, codepoint, byte_count);

    std::cout << "0x" << std::hex << static_cast<int>(codepoint) << "\n"; // 0xA9
    std::cout << byte_count << "\n"; // 2
}
```

### UTF-8 string to a three byte codepoint.
```cpp
#include <softloq-unicode/unicode.hpp>

int main()
{
    std::string utf8 = "∑"; // Capital Sigma Symbol
    char32_t codepoint;
    size_t byte_count;

    Softloq::Unicode::convertUTF8ToCodepoint(utf8, codepoint, byte_count);
    std::cout << "0x" << std::hex << static_cast<int>(codepoint) << "\n"; // 0x2211
    std::cout << byte_count << "\n"; // 3
}
```

### UTF-8 string to a four byte codepoint.
```cpp
#include <softloq-unicode/unicode.hpp>

int main()
{
    std::string utf8 = "😐"; // Neutral Face Emoji
    char32_t codepoint;
    size_t byte_count;

    Softloq::Unicode::convertUTF8ToCodepoint(utf8, codepoint, byte_count);
    std::cout << "0x" << std::hex << static_cast<int>(codepoint) << "\n"; // 0x1610
    std::cout << byte_count << "\n"; // 4
}
```

# CMake Build
## Options
* BUILD_SHARED_LIBS [ON/OFF]:

    Controls building source as shared or static library files.
    
    Default: OFF.
* SOFTLOQ_UNICODE_BUILD_TESTING [ON/OFF]:

    Controls building unit-testing.
    
    Default: OFF.

## Shared Library
When using the shared library, add compiler definition: SOFTLOQ_UNICODE_USE_API or SOFTLOQ_USE_API.

SOFTLOQ_USE_API is recommended when using multiple shared Softloq libraries.

Handled when added via CMake target_link_libraries().

# Running Tests
## Targets
### softloq-unicode-test
Runs unit-tests on softloq-unicode/unicode.hpp and softloq-unicode/macros.hpp header files.

Source Files:
- tests/unicode_test.cpp
- tests/unicode_macros.cpp
## Building
Set the CMake option SOFTLOQ_UNICODE_BUILD_TESTING to ON.

The targets will be built to their respective output folder.
