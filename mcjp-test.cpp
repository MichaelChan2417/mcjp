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

    // test 3 --------- load test
    // mcjp::Result obj = mcjp::load("test.json");
    // mcjp::Object* oj1 = std::get<std::vector<mcjp::Object*>>(obj)[0];
    // mcjp::Object* oj2 = std::get<std::vector<mcjp::Object*>>(obj)[1];
    // for (auto p : oj1->contents) {
    //     std::cout << p.first << std::endl;
    //     if (p.first == "child") {
    //         std::cout << *std::get<mcjp::Object*>(p.second) << std::endl;
    //     }
    // }
    // std::cout << "\n" << *oj1 << std::endl;
    // std::cout << "\n" << *oj2 << std::endl;
    // oj1->cleanup();
    // oj2->cleanup();

    // test 4 --------- real test
    // mcjp::Result obj = mcjp::load("format.json");
    // auto vecs = std::get<std::vector<mcjp::Object*>>(obj);
    // for (auto oj : vecs) {
    //     std::cout << *oj << "\n" << std::endl;
    // }

    // for (auto oj : vecs) {
    //     oj->cleanup();
    // }

    return 0;
}
