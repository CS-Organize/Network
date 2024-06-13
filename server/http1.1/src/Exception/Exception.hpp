#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>

class InvalidRequestException : public std::exception
{
public:
    const char* what() const _NOEXCEPT
    {
        return "Invalid Request";
    }
};

#endif
