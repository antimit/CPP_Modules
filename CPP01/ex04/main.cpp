#include <iostream>
#include <fstream>
#include <string>

typedef std::string str;

static void replace_all(str &line, const str &s1, const str &s2) {
    if (s1.empty())
    {
        std::cout << "Warning: s1 is empty, no replacements made.\n";
        return; // Guarded in main too; here it's a no-op for safety.
    }
        

    std::string::size_type pos = 0;
    while ((pos = line.find(s1, pos)) != std::string::npos) {
        line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
        pos += s2.length(); // advance past the inserted text
        std::cout << "Replaced occurrence at position: " << pos <<"    line is" << line<< std::endl; // Debug output
    }
}

int main(int ac, char **av) {
    if (ac != 4) {
        std::cerr << "Usage: ./replace <file> <s1> <s2>\n";
        return 1;
    }

    const str in_file = av[1];
    const str s1      = av[2];
    const str s2      = av[3];

    if (s1.empty()) {
        std::cerr << "Error: s1 must not be empty.\n";
        return 1;
    }

    const str out_file = in_file + ".replace";

    std::ifstream input(in_file.c_str(), std::ios::in);
    if (!input) {
        std::cerr << "Error: cannot open input file: " << in_file << "\n";
        return 1;
    }

    std::ofstream output(out_file.c_str(), std::ios::out | std::ios::trunc);
    if (!output) {
        std::cerr << "Error: cannot open output file: " << out_file << "\n";
        return 1;
    }

    str line;
    while (std::getline(input, line)) {
        replace_all(line, s1, s2);
        std::cout << "Processed line: " << line << std::endl; // Debug output
        std::cout<< "Replacing \"" << s1 << "\" with \"" << s2 << "\"\n"; // Debug output
        output << line;
        if (!input.eof())
            output << '\n';
        if (!output) {
            std::cerr << "Error: write failed for: " << out_file << "\n";
            return 1;
        }
    }

    if (input.bad()) {
        std::cerr << "Error: read failed for: " << in_file << "\n";
        return 1;
    }

    return 0;
}
