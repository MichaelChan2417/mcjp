#include "mcjp.hpp"

namespace mcjp {
    void filter(const std::string& str, std::string& res);

    Object parse(const std::string& str) {
        std::string res;
        filter(str, res);
        std::cout << "after filter:\n" << res << std::endl;
        return Object{};
    }

    Object parse(const std::ifstream& in) {
        // we read in to a string, then we do the parse
        std::stringstream buffer;
        buffer << in.rdbuf();
        std::string res = buffer.str();

        std::cout << "Before filter\n" << res << std::endl;
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
            if (!in_string && (ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r')) {
                res += ch;
            }
        }
    }

} // namespace mcjp
