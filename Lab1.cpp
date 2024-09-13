#include <iostream>
#include <map>
#include <string>

class Solution {
public:
    std::map<int, std::string> fly() {
        std::string command;
        std::map<int, std::string> res;

        while (std::getline(std::cin, command)) {
            if (command.find("FLY") != std::string::npos) {
                int ptr_0 = command.find("FLY") + 4;
                int ptr_1 = ptr_0;
                while (ptr_1 < command.size() && command[ptr_1] != ' ') {
                    ptr_1++;
                }
                int key = std::stoi(command.substr(ptr_0, ptr_1 - ptr_0));
                res[key] = "";
            } else if (command.find("GROUND") != std::string::npos) {
                int ptr_0 = command.find("GROUND") + 7;
                int ptr_1 = ptr_0;
                while (ptr_1 < command.size() && command[ptr_1] != ' ') {
                    ptr_1++;
                }
                int key = std::stoi(command.substr(ptr_0, ptr_1 - ptr_0));
                res.erase(key);
            } else if (command.find("SEAT") != std::string::npos) {
                int ptr_0 = command.find("SEAT") + 5;
                int ptr_1 = ptr_0;
                while (ptr_1 < command.size() && command[ptr_1] != ' ') {
                    ptr_1++;
                }
                int key = std::stoi(command.substr(ptr_0, ptr_1 - ptr_0));
                std::string value = command.substr(ptr_1, command.size() - ptr_1);
                res[key] = value;
            } else if (command.find("CANCEL") != std::string::npos) {
                int ptr_0 = command.find("CANCEL") + 7;
                int ptr_1 = ptr_0;
                while (ptr_1 < command.size() && command[ptr_1] != ' ') {
                    ptr_1++;
                }
                int key = std::stoi(command.substr(ptr_0, ptr_1 - ptr_0));
                std::string name = command.substr(ptr_1, command.size() - ptr_1);
                size_t pos = res[key].find(name);
                if (pos != std::string::npos) {
                    res[key].erase(pos, name.length());
                }
            } else if (command.find("PRINT") != std::string::npos) {
                int ptr_0 = command.find("PRINT") + 6;
                int ptr_1 = ptr_0;
                while (ptr_1 < command.size() && command[ptr_1] != ' ') {
                    ptr_1++;
                }
                int key = std::stoi(command.substr(ptr_0, ptr_1 - ptr_0));
                std::cout << res[key] << std::endl;
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    s.fly();
    return 0;
}
