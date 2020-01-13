// Copyright 2020 Ara Ovsepyan ara07.99@icloud.com

#include <hashMake.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/log/utility/setup.hpp>
#include <thread>
#include <vector>


int main(int argc, char* argv[])
{
    srand(time(nullptr));
    boost::log::add_file_log("Result.log");
    boost::log::add_console_log(std::cout);
    size_t countOfThreads = 0;
    if (argc < 2) {
        countOfThreads = std::thread::hardware_concurrency();
    } else {
        countOfThreads = boost::lexical_cast<size_t>(argv[1]);
    }

    std::vector<std::thread> threads;
    threads.reserve(countOfThreads);

    for (size_t i = 0; i < countOfThreads; ++i) {
        threads.emplace_back(Hash::hashMake);
    }

    for (std::thread& i : threads) {
        i.join();
    }

    return 0;
}
