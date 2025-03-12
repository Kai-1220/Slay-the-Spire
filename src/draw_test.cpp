#include "pch.hpp"
#include <fstream>
#include "draw_test.hpp"
void testfun(std::vector<std::shared_ptr<Draw::ReText>> &rr){
    std::ifstream file(RESOURCE_DIR"/zht/cards.json");
    char buffer[3000];
    while(!file.eof()){
        file.getline(buffer,sizeof(buffer));
        std::string temp(buffer);
        rr.push_back(std::make_shared<Draw::ReText>(RESOURCE_DIR"/font/zht/NotoSansCJKtc-Bold.otf",64,temp));
    }
    file.close();
}