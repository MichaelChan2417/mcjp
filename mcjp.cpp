#include "mcjp.hpp"

namespace mcjp {
    void filter(const std::string& str, std::string& res);

    Object buildVector(const std::string& str, int startIdx, int endIdx) {
        Object res;
        res.type = VECTOR;
        // we need to find the boundary of 
        return res;
    }

    Object buildObject(const std::string& str, int startIdx, int endIdx) {
        Object res;
        res.type = SINGLE;
        return res; 
    }

    Object parse(const std::string& str) {
        std::string res;
        // filter out unnecessary spaces
        filter(str, res);

        // we need to check if it's a vector or a single object
        if (res[0] == '[') {
            return buildVector(res, 0, res.size() - 1);
        } else {
            return buildObject(res, 0, res.size() - 1);
        }
    }

    Object parse(const std::ifstream& in) {
        // we read in to a string, then we do the parse
        std::stringstream buffer;
        buffer << in.rdbuf();
        std::string res = buffer.str();
        return parse(res);
    }
    
    Object load(const std::string& filename) {
        std::ifstream in(filename, std::ios::binary);
        return parse(in);
    }
    
    void filter(const std::string& str, std::string& res) {
        bool in_string = false;

        for (char ch : str) {
            if (ch == '"' || ch == '\'') {
                in_string = !in_string;
            }

            if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
                if (in_string) {
                    res += ch;
                }
            }
            else {
                res += ch;
            }
        }
    }

    std::ostream& operator<<(std::ostream& os, const Object::Data& data) {
        std::visit([&os](const auto& value) {
            if constexpr (std::is_same_v<Object*, std::decay_t<decltype(value)>>) {
                os << *value;
            } else {
                os << value;
            }
        }, data);
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const Object& obj) {
        if (obj.type == SINGLE) {
            os << "{";
            for (auto p : obj.contents) {
                os << p.first << ": " << p.second << ", ";
            }
            os << "}";
        } else {
            os << "[";
            for (auto p : obj.vecContents) {
                os << *p << ", ";
            }
            os << "]";
        }
        return os;
    }

} // namespace mcjp
