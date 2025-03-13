#include "RUtil/Atlas_Reader.hpp"
#include<fstream>
#include "Util/Logger.hpp"
#include "RUtil/Some_Math.hpp"
#include "RUtil/Image_book.hpp"
namespace RUtil{
    Atlas_Reader::Atlas_Reader(const std::string &atlas_path){
        std::ifstream inputFile(atlas_path);
        if(!inputFile){
            LOG_ERROR("The atlas_path doesn't exist");
        }else{
            const std::string atlas_dir=atlas_path.substr(0,atlas_path.rfind('/')==std::string::npos?0:atlas_path.rfind('/')+1);
            std::string line;
            bool is_texture=true,change_path=true;
            std::string texture_path="";
            std::shared_ptr<Draw::ReTexture> texture=nullptr;
            std::string region_name="";
            bool region_rotate=false;
            int region_x=0,region_y=0,size_x=0,size_y=0,orig_x=0,orig_y=0,offset_x=0,offset_y=0;
            while (std::getline(inputFile, line)) {
                if(line.empty()){
                    if(!is_texture){
                        this->reg_map[region_name]=std::make_shared<Draw::Atlas_Region>(region_name,region_x,region_y,texture,offset_x,offset_y,size_x,size_y,orig_x,orig_y,region_rotate);
                    }
                    is_texture=true;
                }else if(is_texture){
                    //ignore size,format,filter,repeat
                    if(line.compare(0,4,"size")==0||line.compare(0,6,"format")==0||line.compare(0,6,"filter")==0||line.compare(0,6,"repeat")==0){
                        change_path=false;
                    }else{
                        if(change_path){
                            texture_path=atlas_dir+line;
                            texture=RUtil::Image_book::GetTexture(texture_path);
                        }else{
                            change_path=true;
                            is_texture=false;
                            region_name=line;
                        }
                    }
                }else{
                    //ignore "index"
                    if(line.compare(2,6,"rotate")==0){
                        region_rotate=line.find("false")==std::string::npos;
                    }else if(line.compare(2,2,"xy")==0){
                        //: ,
                        region_x=RUtil::Math::StrToInt(line.substr(0,line.find(',')));
                        region_y=RUtil::Math::StrToInt(line.substr(line.find(',')+1));
                    }else if(line.compare(2,4,"size")==0){
                        size_x=RUtil::Math::StrToInt(line.substr(0,line.find(',')));
                        size_y=RUtil::Math::StrToInt(line.substr(line.find(',')+1));
                    }else if(line.compare(2,4,"orig")==0){
                        orig_x=RUtil::Math::StrToInt(line.substr(0,line.find(',')));
                        orig_y=RUtil::Math::StrToInt(line.substr(line.find(',')+1));
                    }else if(line.compare(2,6,"offset")==0){
                        offset_x=RUtil::Math::StrToInt(line.substr(0,line.find(',')));
                        offset_y=RUtil::Math::StrToInt(line.substr(line.find(',')+1));
                    }
                }
            }
            inputFile.close();
        }
    }
    std::shared_ptr<Draw::Atlas_Region> Atlas_Reader::Find_Atlas_Region(const std::string& region_name){
        auto result = reg_map.find(region_name);
        if (result != reg_map.end()) {
            return result->second;
        }
        LOG_ERROR("ERROR happens when loading atlas region.");
        return nullptr;
    }
}