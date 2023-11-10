#include <iostream>

int find_substring_light_rabin_karp(std::string line, std::string part_of_line){
    int hash_part_of_line = 0;
    for(int i = 0; i < part_of_line.length(); i++){//посчитали хэш, что ищем
        hash_part_of_line += static_cast<int>(part_of_line[i]);
    }

    int hash_line = 0;
    bool flag = false;

    for(int k = 0; k < line.length(); k++){
        hash_line += static_cast<int>(line[k]);
        if(k >= part_of_line.length()){
            hash_line -= static_cast<int>(line[k - part_of_line.length()]);
        }

        if(hash_part_of_line == hash_line){//если хэш равен проверяем побуквенно
            for(int l = 0; l < part_of_line.length(); l++){
                if(line[k - (part_of_line.length() - 1) + l] == part_of_line[l]){
                    flag = true;
                }else{
                    flag = false;
                    break;
                }
            }
        }
        if(flag) return k - (part_of_line.length() - 1);
    }
    return -1;
}

int main() {

    std::string line, part_of_line;
    int total;

    std::cout << "Введите строку, в которой будет осуществляться поиск: ";
    std::cin >> line;

    while (part_of_line != "exit") {
        std::cout << "Введите подстроку, которую нужно найти: ";
        std::cin >> part_of_line;
        total = find_substring_light_rabin_karp(line, part_of_line);

        if(total == -1){
            std::cout << "Подстрока " << part_of_line <<  " не найдена\n";
        }else{
            std::cout << "Подстрока " << part_of_line << " найдена по индексу " << total << "\n";
        }
    }
    return 0;
}
