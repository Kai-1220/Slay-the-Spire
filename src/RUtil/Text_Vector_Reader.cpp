#include "RUtil/Text_Vector_Reader.hpp"
#include "Util/Logger.hpp"
#include<fstream>
namespace RUtil{
std::shared_ptr<std::vector<Draw::Text_layout>> Text_Vector_Reader::GetTextVector(const Text_ID id){
    if(BOX.empty()) init_BOX();
    if(BOX[static_cast<int>(id)]->empty()) LOG_WARN("This id:{} you request in TextVector is empty.",static_cast<int>(id));
    return BOX[static_cast<int>(id)];
}
void Text_Vector_Reader::init_BOX(){
    //load ui
    GetJsonFileText(RESOURCE_DIR"/language/zht/ui.json");
}
void Text_Vector_Reader::GetJsonFileText(const std::string &path){
    std::ifstream inputFile(path);
    if(!inputFile){
        LOG_ERROR("The ERROR happends when loading path:{} Vector strings.",path);
    }else{
        std::string line;
        bool vec_started=false;
        
        while(std::getline(inputFile,line)){
            const auto l_pos=line.find('"');
            if(10<line.length() && l_pos!=line.npos && line.compare(l_pos,6,"\"TEXT\"")==0){
                vec_started=true;
                BOX.emplace_back(std::make_shared<std::vector<Draw::Text_layout>>());
            }else if(4<line.length()&&line[4]==']')
                vec_started=false;
            else if(vec_started){
                const auto r_pos=line.rfind('"');
                if(l_pos>=r_pos) LOG_ERROR("TEXT contain:'{}' WRONG in path:{}",line,path);
                const auto sub_str=line.substr(l_pos+1,r_pos-l_pos-1);
                BOX.back()->emplace_back(sub_str.empty()?" ":sub_str);//make sure not empty;
            }
        }
        inputFile.close();
    }
}
std::vector<std::shared_ptr<std::vector<Draw::Text_layout>>> Text_Vector_Reader::BOX;
}