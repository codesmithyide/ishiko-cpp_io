/*
    Copyright (c) 2020-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/io/blob/main/LICENSE.txt
*/

#include "IOErrorCategory.hpp"

using namespace Ishiko;

const IOErrorCategory& IOErrorCategory::Get() noexcept
{
    static IOErrorCategory theCategory;
    return theCategory;
}

const char* IOErrorCategory::name() const noexcept
{
    return "Ishiko::IOErrorCategory";
}

void Ishiko::Fail(Error& error, IOErrorCategory::EErrorValues value) noexcept
{
    error.fail(value, IOErrorCategory::Get());
}

void Ishiko::Fail(Error& error, IOErrorCategory::EErrorValues value, const std::string& message, const char* file,
    int line) noexcept
{
    error.fail(value, IOErrorCategory::Get(), message, file, line);
}