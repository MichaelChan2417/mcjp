#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

namespace mcjp {

    enum ObjectType {
        SINGLE,
        VECTOR
    };

    struct Object {
        // internals
        ObjectType type;
        std::unordered_map < std::string, Object* > contents;
        std::vector<Object*> vecContents;

        // constructor
        Object() : type(SINGLE) {}

        // interface
        Object load(const std::string& filename);
        Object parse(const std::string& str);
    };


} // namespace mcjp
