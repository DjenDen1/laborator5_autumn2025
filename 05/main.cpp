#include "World.h"
#include "black_box/Application.h"
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    srand(time(NULL));
    if (argc < 1) {
        std::cerr << "Please, call with one argument "
                  << "( example: " << argv[0] << " <path to file smile.txt> )";
        return 1;
    }
    try {
        World w("C:/CPP2025/lab5/05_2/05/data/smile.txt"); // argv[1]
        /**
         * Код ниже запускает выполнение приложения. Для
         * выполнения задания нет необходимости изучать
         * или менять содержимое Application. Для начала
         * лучше сфокусироваться на Ball.hpp, Ball.cpp и
         * World.cpp
         */
        Application app("physics");
        app.run(w);

    } catch (std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        return 2;
    }
    return 0;
}