#include "mcjp.hpp"

int main() {
    // test 1 ---------- basic << test
    // mcjp::Object obj1, obj2;
    // obj1.contents["next"] = &obj2;
    // std::vector<int> dt{ 1,2,3,4,5 };
    // obj2.contents["prev"] = dt;
    // std::cout << obj1 << std::endl;

    // test 2 --------- vector separation
    // std::string json;
    // std::ifstream in("test.json", std::ios::binary);
    // std::stringstream buffer;
    // buffer << in.rdbuf();
    // std::string org = buffer.str();
    // mcjp::filter(org, json);
    // std::cout << "Prev:\n" << json << std::endl;
    // mcjp::buildVector(json, 0, json.size() - 1);
    // std::cout << json.substr(1, 32 - 1 + 1) << std::endl;
    // std::cout << json.substr(34, 50 - 34 + 1) << std::endl;

    
    mcjp::Result obj = mcjp::load("test.json");

    return 0;
}
