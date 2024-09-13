#include <iostream>
#include <map>
#include <string>
#include <set>
#include <sstream>
#include <vector>
#include <fstream>
#include <filesystem>

class Solution {
public:
    void fly() {
        std::string command;
        std::map<int, std::set<std::string>> res;

        while (std::getline(std::cin, command)) {
            if (command.empty()) {
                break;
            }

            std::istringstream iss(command);
            std::string word;
            std::vector<std::string> words;

            while (iss >> word) {
                words.push_back(word);
            }

            if (words[0] == "FLY") {
                flyCommand(res, words);

            } else if (words[0] == "GROUND") {
                groundCommand(res, words);

            } else if (words[0] == "SEAT") {
                seatCommand(res, words);

            } else if (words[0] == "CANCEL") {
                cancelCommand(res, words);

            } else if (words[0] == "PRINT") {
                printCommand(res, words);

            } else if (words[0] == "FILE") {
                processFile(res, words);

            } else {
                std::cerr << "Error: Unrecognized command \"" << words[0] << "\"." << std::endl;
            }
        }
    }

private:
    void flyCommand(std::map<int, std::set<std::string>>& res, const std::vector<std::string>& words) {
        int key = std::stoi(words[1]);
        res[key] = std::set<std::string>();
    }

    void groundCommand(std::map<int, std::set<std::string>>& res, const std::vector<std::string>& words) {
        int key = std::stoi(words[1]);
        if (res.find(key) != res.end()) {
            res.erase(key);
        } else {
            std::cerr << "Error: Flight " << key << " does not exist." << std::endl;
        }
    }

    void seatCommand(std::map<int, std::set<std::string>>& res, const std::vector<std::string>& words) {
        int key = std::stoi(words[1]);
        std::string value = words[2] + " " + words[3];
        if (res.find(key) != res.end()) {
            res[key].insert(value);
        } else {
            std::cerr << "Error: Flight " << key << " does not exist." << std::endl;
        }
    }

    void cancelCommand(std::map<int, std::set<std::string>>& res, const std::vector<std::string>& words) {
        int key = std::stoi(words[1]);
        std::string name = words[2] + " " + words[3];
        if (res.find(key) != res.end()) {
            if (res[key].find(name) != res[key].end()) {
                res[key].erase(name);
            } else {
                std::cerr << "Error: Passenger " << name << " does not have a seat on flight " << key << "." << std::endl;
            }
        } else {
            std::cerr << "Error: Flight " << key << " does not exist." << std::endl;
        }
    }

    void printCommand(const std::map<int, std::set<std::string>>& res, const std::vector<std::string>& words) {
        int key = std::stoi(words[1]);
        if (res.find(key) != res.end()) {
            std::string filename = "list_passengers_flight_" + std::to_string(key) + ".txt";
            int version = 1;
            while (std::filesystem::exists(filename)) {
                filename = "list_passengers_flight_" + std::to_string(key) + "(" + std::to_string(version) + ").txt";
                version++;
            }

            std::ofstream outFile(filename);
            std::cout << "Flight " << key << ":" << std::endl;

            for (const auto& name : res.at(key)) {
                outFile << name << std::endl;
                std::cout << name << std::endl;
            }
            std::cout << std::endl;
            outFile.close();
        } else {
            std::cerr << "Error: Flight " << key << " does not exist." << std::endl;
        }
    }

    void processFile(std::map<int, std::set<std::string>>& res, const std::vector<std::string>& words) {
        std::ifstream inFile(words[1]);
        std::string line;

        while (std::getline(inFile, line)) {
            std::istringstream iss(line);
            std::string word;
            std::vector<std::string> words;

            while (iss >> word) {
                words.push_back(word);
            }

            if (words[0] == "FLY") {
                flyCommand(res, words);

            } else if (words[0] == "GROUND") {
                groundCommand(res, words);

            } else if (words[0] == "SEAT") {
                seatCommand(res, words);

            } else if (words[0] == "CANCEL") {
                cancelCommand(res, words);
                
            } else if (words[0] == "PRINT") {
                printCommand(res, words);
            }
        }
        inFile.close();
    }
};

int main() {
    Solution s;
    s.fly();
    return 0;
}
