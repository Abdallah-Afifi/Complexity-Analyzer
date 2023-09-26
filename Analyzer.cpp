#include <iostream>
#include <string>
#include <regex>

int countNestedLoops(const std::string &code) {
int nestedLevel = 0;
std::regex loopRegex("(for|while|do\\s*\\{)");

// Compile the regex once to improve performance
std::regex_constants::optimize;

// Use a std::sregex_iterator to iterate over all loop occurrences
std::sregex_iterator loopIt(code.begin(), code.end(), loopRegex);
std::sregex_iterator loopEnd;

// Count the nested loops
while (loopIt != loopEnd) {
nestedLevel++;
++loopIt;
    
}

return nestedLevel;
}

int main() {
int totalNestedLoops = 0;

std::cout << "Enter your C++ code snippets (one per line, type 'exit' to quit):\n";

while (true) {
std::string code;
std::getline(std::cin, code);

if (code == "exit") {
break;
}

int nestedLoops = countNestedLoops(code);
totalNestedLoops += nestedLoops;
}

// Estimate the total time complexity
if (totalNestedLoops == 0) {
std::cout << "Estimated total time complexity: O(1)\n"; // No loops
} else {
std::cout << "Estimated total time complexity: O(n^" << totalNestedLoops << ")\n";
}

return 0;
}
