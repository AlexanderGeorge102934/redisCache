#include "redisCache.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>

std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }
    return tokens;
}

int main() {
    redisCache<int, std::string> cache(100);  // Cache capacity set to 100

    std::cout << "Redis-like Cache CLI (Type 'EXIT' to quit)\n";
    std::cout << "Commands:\n";
    std::cout << "  SET <key> <value>\n";
    std::cout << "  GET <key>\n";
    std::cout << "  EXPIRE <key> <seconds>\n\n";

    std::string command;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, command);
        std::vector<std::string> parts = split(command, ' ');

        if (parts.empty()) continue;

        try {
            if (parts[0] == "EXIT") {
                break;
            } else if (parts[0] == "SET" && parts.size() >= 3) {
                int key = std::stoi(parts[1]);
                std::string value;
                for (size_t i = 2; i < parts.size(); ++i) {
                    if (i > 2) value += " ";
                    value += parts[i];
                }
                cache.put(key, value);
                std::cout << "OK\n";
            } else if (parts[0] == "GET" && parts.size() >= 2) {
                int key = std::stoi(parts[1]);
                auto value = cache.get(key);
                std::cout << (value.has_value() ? "\"" + value.value() + "\"" : "(nil)") << std::endl;
            } else if (parts[0] == "EXPIRE" && parts.size() >= 3) {
                int key = std::stoi(parts[1]);
                time_t ttl = std::stoi(parts[2]);
                time_t expiration = std::time(nullptr) + ttl;
                cache.expire(expiration, key);
                std::cout << "(Set expiration for key " << key << ")\n";
            } else {
                std::cout << "Invalid command\n";
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}
