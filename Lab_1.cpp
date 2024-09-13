#include <iostream>
#include <map>
#include <string>
#include <set>
#include <sstream>
#include <vector>

class Solution {
public:
    void fly() {
        std::string command;
        std::map<int, std::set<std::string>> res;

        while (std::getline(std::cin, command)) {

            std::istringstream iss(command);
            std::string word;
            std::vector<std::string> words;

            while (iss >> word) {
                words.push_back(word);
            }

            if (words[0] == "FLY") {
                int key = std::stoi(words[1]);
                res[key] = std::set<std::string>();

            } else if (words[0] == "GROUND") {
                int key = std::stoi(words[1]);
                res.erase(key);

            } else if (words[0] == "SEAT") {
                int key = std::stoi(words[1]);
                std::string value = words[2];
                res[key].insert(value);

            } else if (words[0] == "CANCEL") {
                int key = std::stoi(words[1]);
                std::string name = words[2];
                res[key].erase(name);

            } else if (words[0] == "PRINT") {
                int key = std::stoi(words[1]);

                for (const auto& name : res[key]) {
                    std::cout << name << " ";
                }
                std::cout << std::endl;
            }
        }
    }
};

int main() {
    Solution s;
    s.fly();
    return 0;
}
