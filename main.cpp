#include <iostream>
#include <vector>   
#include <fstream>
#include <sstream>
#include "sorts.h"
#include <chrono>
#include <unordered_set>
#include <filesystem>
namespace fs = std::filesystem;

int main () {


    std::string path = "random";
    std::unordered_set<std::string> paths;
    for (const auto & entry : fs::directory_iterator(path)) {
        fs::path path = entry.path();
        std::string path_string{ path.u8string()};
        paths.insert(path_string);
    }



    
    for (auto file : paths) {
        std::ifstream in;
        in.open(file, std::ifstream::in);
        if(!in.is_open())
        {
            std::cerr << "Error opening file" << std::endl;
            return 0;
        }
        std::cout << file << "\n";
        std::vector<int> ord;
        int s;

        //similar to  while(getline(in,s,'\n'))
        while(in >> s)
        {
            ord.push_back(s);
        }

        auto start = std::chrono::high_resolution_clock::now();

        sorts::mergesort(ord,0,ord.size()-1);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        std::cout << elapsed.count() << '\n';

    }
}