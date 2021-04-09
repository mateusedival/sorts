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


    std::string paths_names[4] = {"random","sorted","reversed","partial"};

    for(auto path : paths_names){
        std::unordered_set<std::string> file_names;
        for (const auto & entry : fs::directory_iterator(path)) {
            fs::path path = entry.path();
            std::string path_string{ path.u8string()};
            file_names.insert(path_string);
        }

        for (auto file : file_names) {
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

            double mean_merge = 0.0f, mean_heap = 0.0f, mean_quick = 0.0f;
            for(int i = 0; i < 10; i++ )
            {
                std::vector<int> ord1(ord), ord2(ord), ord3(ord);

                auto start = std::chrono::high_resolution_clock::now();

                sorts::merge_sort(ord1,0,ord1.size()-1);

                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> elapsed = end - start;
                mean_merge += elapsed.count();

                start = std::chrono::high_resolution_clock::now();

                sorts::heap_sort(ord2,ord2.size());

                end = std::chrono::high_resolution_clock::now();
                elapsed = end - start;
                mean_heap += elapsed.count();


                start = std::chrono::high_resolution_clock::now();

                sorts::quick_sort(ord3,0,ord3.size()-1);

                end = std::chrono::high_resolution_clock::now();
                elapsed = end - start;
                mean_quick += elapsed.count();
            }

            std::cout << mean_merge/10.0 << '\n';

            std::cout << mean_heap/10.0 << '\n';

            std::cout << mean_quick/10.0 << '\n';
        }

    }
}