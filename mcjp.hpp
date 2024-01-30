#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <variant>

namespace mcjp {

    enum ObjectType {
        SINGLE,
        VECTOR
    };

    struct Object {
        using Data = std::variant<int, double, std::string, Object*, 
                            std::vector<int>, std::vector<std::string>, std::vector<double>>;

        // internals
        ObjectType type;
        std::unordered_map < std::string, Data > contents;
        std::vector<Object*> vecContents;

        // constructor
        Object() : type(SINGLE) {};

        // interface
    };

    std::ostream& operator<<(std::ostream& os, const Object& obj);
    Object load(const std::string& filename);
    Object parse(const std::string& str);

} // namespace mcjp
