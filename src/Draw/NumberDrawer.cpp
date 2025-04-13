#include <vector>
#include <memory>

#include "Draw/NumberDrawer.hpp"
#include "Draw/ReText.hpp"
#include "Draw/Image_Region.hpp"
#include "Draw/Draw_2D.hpp"
#include "WindowSize.hpp"

namespace Draw{
    NumberDrawer::NumberDrawer(int fontsize):fontsize(fontsize){
        TTF_Font* m_Font=TTF_OpenFont(Setting::LANGUAGE_POS,fontsize);
        TTF_SizeUTF8(m_Font,"0",&unit_w,&unit_h);
        TTF_CloseFont(m_Font);
    }
    void NumberDrawer::render(const std::shared_ptr<Draw_2D> &r2,const std::string &num_str,const float center_x,const float center_y,const float scale)const{
        auto& nums=GetNums();
        const int len=static_cast<int>(num_str.size());
        float now_x=float(-len*unit_w)/2.0F;
        for(const auto&it:num_str){
            if('0'<=it&&it<='9'){
                r2->draw(nums[it^48], center_x+now_x, center_y-(float)unit_h/2.0F, (float)unit_w, (float)unit_h, 0.0F, center_x, center_y, scale*Setting::SCALE, scale*Setting::SCALE);
            }else if(it=='/'){
                r2->draw(nums[10], center_x+now_x, center_y-(float)unit_h/2.0F, (float)unit_w, (float)unit_h, 0.0F, center_x, center_y, scale*Setting::SCALE, scale*Setting::SCALE);
            }else{
                LOG_ERROR("NumberDrawer can't draw '{}'",it);
            }
            now_x+=unit_w;
        }
    }
    const std::vector<std::shared_ptr<Image_Region>> &NumberDrawer::GetNums(){
        static const std::vector<std::shared_ptr<Image_Region>> nums=[](){
            std::vector<std::shared_ptr<Image_Region>> re;
            constexpr auto data="01234\n56789/";
            std::shared_ptr<ReText> nums_text=std::make_shared<ReText>(Setting::LANGUAGE_POS,Setting::BIGGIST_SIZE,data);
            TTF_Font* m_Font=TTF_OpenFont(Setting::LANGUAGE_POS,Setting::BIGGIST_SIZE);
            int n_w,n_h,t_w=0;
            for(int i=0;i<5;i++){
                const char str[2]={data[i],'\0'};
                TTF_SizeUTF8(m_Font,str,&n_w,&n_h);
                re.emplace_back(std::make_shared<Draw::Image_Region>(nums_text,t_w,0,n_w,n_h));
                t_w+=n_w;
            }
            t_w=0;
            for(int i=6;i<12;i++){
                const char str[2]={data[i],'\0'};
                TTF_SizeUTF8(m_Font,str,&n_w,&n_h);
                re.emplace_back(std::make_shared<Draw::Image_Region>(nums_text,t_w,n_h,n_w,n_h));
                t_w+=n_w;
            }
            TTF_CloseFont(m_Font);
            return re;
        }();
        return nums;
    }
}