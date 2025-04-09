#include "RUtil/Text_Vector_Reader.hpp"
#include "Util/Logger.hpp"
#include<fstream>
namespace RUtil{
const std::vector<std::shared_ptr<Draw::Text_layout>> &Text_Vector_Reader::GetTextVector(const Text_ID id){
    static const std::vector<std::vector<std::shared_ptr<Draw::Text_layout>>> BOX=[](){
        std::vector<std::vector<std::shared_ptr<Draw::Text_layout>>> temp;
        //load ui
        GetJsonFileText(RESOURCE_DIR"/language/eng/ui.json",temp);
        return temp;
    }();
    return BOX[static_cast<int>(id)];
}
void Text_Vector_Reader::GetJsonFileText(const std::string &path,std::vector<std::vector<std::shared_ptr<Draw::Text_layout>>>&vec){
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
                vec.emplace_back();
            }else if(4<line.length()&&line[4]==']')
                vec_started=false;
            else if(vec_started){
                const auto r_pos=line.rfind('"');
                if(l_pos>=r_pos) LOG_ERROR("TEXT contain:'{}' WRONG in path:{}",line,path);
                const auto sub_str=line.substr(l_pos+1,r_pos-l_pos-1);
                vec.back().emplace_back(sub_str.empty()?nullptr:std::make_shared<Draw::Text_layout>(sub_str));//make sure not empty;
            }
        }
        inputFile.close();
    }
}
}