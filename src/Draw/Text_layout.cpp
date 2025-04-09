#include "Draw/Text_layout.hpp"
#include "Util/Logger.hpp"
#include "RUtil/Atlas_Reader.hpp"
#include "WindowSize.hpp"
#include "RUtil/Some_Math.hpp"
namespace Draw
{
    Text_layout::Text_layout(const std::string &text_string){
        if(orb_red==nullptr){
            this->init_nums();
            this->init_orbs();
        }
        //#y:yellow #g:green #r:red #b:blue #p:purple #n:new line
        //!D!:damage !B!:block !M!:vars
        //[R]:orb_red [G]:orb_green [B]:orb_blue [W]:orb_purple [C]:orb_card 
        //[P]:orb_potion [T]:orb_relic [S]:orb_special
        std::vector<std::string> strs;
        split_text(strs,text_string);
        //get total str
        std::string total_str="";
        for(const std::string &it:strs){
            if(it[0]!='!'&&it[0]!='['){
                if(it[0]=='#'){
                    if(it[1]=='n')total_str+='\n';
                    total_str+=it.substr(2);
                }else total_str+=it;
            }
        }
        m_fontsize=BIGGIST_SIZE;//default biggist_size
        std::shared_ptr<Draw::ReText> t_retext=std::make_shared<Draw::ReText>(s_lan_pos,BIGGIST_SIZE,total_str);
        set_texture_pos(t_retext,strs);
        middle_mode=true;//it will be changed to false later
        set_left();//default left
        this->scale_all_pos(Setting::SCALE);
    }
    std::string Text_layout::s_next_lan_pos;
    Text_layout::language Text_layout::s_language=Text_layout::language::zht;
    Text_layout::font_weight Text_layout::s_font_weight=Text_layout::font_weight::regular;
    std::shared_ptr<Draw::Image_Region> Text_layout::nums[10]={nullptr};
    std::shared_ptr<Draw::Atlas_Region> Text_layout::orb_red=nullptr,Text_layout::orb_blue=nullptr,
                                        Text_layout::orb_green=nullptr,Text_layout::orb_purple=nullptr,
                                        Text_layout::orb_card=nullptr,Text_layout::orb_potion=nullptr,
                                        Text_layout::orb_relic=nullptr,Text_layout::orb_special=nullptr;
    void Text_layout::SetNextLanguage(language lan){
        s_language=lan;
        next_pos_update();
    }
    void Text_layout::SetNextFontWeight(font_weight fw){
        s_font_weight=fw;
        next_pos_update();
    }
    void Text_layout::next_pos_update(){
        switch (s_language)
        {
        case language::eng:
            s_next_lan_pos=RESOURCE_DIR"/font/";
            break;
        case language::jpn:
            s_next_lan_pos=RESOURCE_DIR"/font/jpn/NotoSansCJKjp-";
            break;
        case language::zht:
            s_next_lan_pos=RESOURCE_DIR"/font/zht/NotoSansCJKtc-";
            break;
        default:
            LOG_ERROR("language ERROR");
            s_next_lan_pos=RESOURCE_DIR"/font/zht/NotoSansCJKtc-";
            break;
        }
        if(s_language==language::eng){
            switch (s_font_weight)
            {
            case font_weight::bold:
                s_next_lan_pos+="Kreon-Bold.ttf";
                break;
            case font_weight::medium:
                s_next_lan_pos+="ZillaSlab-RegularItalic.otf";
                break;
            case font_weight::regular:
                s_next_lan_pos+="Kreon-Regular.ttf";
                break;
            default:
                LOG_ERROR("Font_weight ERROR");
                s_next_lan_pos+="Kreon-Regular.ttf";
                break;
            }
        }else{
            switch (s_font_weight)
            {
            case font_weight::bold:
                s_next_lan_pos+="Bold.otf";
                break;
            case font_weight::medium:
                s_next_lan_pos+="Medium.otf";
                break;
            case font_weight::regular:
                s_next_lan_pos+="Regular.otf";
                break;
            default:
                LOG_ERROR("Font_weight ERROR");
                s_next_lan_pos+="Regular.otf";
                break;
            }
        }
    }
    void Text_layout::init_orbs(){
        RUtil::Atlas_Reader orb_atlas(RESOURCE_DIR"/Image/orbs/orb.atlas");
        orb_red=orb_atlas.Find_Atlas_Region("red");
        orb_blue=orb_atlas.Find_Atlas_Region("blue");
        orb_card=orb_atlas.Find_Atlas_Region("card");
        orb_green=orb_atlas.Find_Atlas_Region("green");
        orb_potion=orb_atlas.Find_Atlas_Region("potion");
        orb_purple=orb_atlas.Find_Atlas_Region("purple");
        orb_relic=orb_atlas.Find_Atlas_Region("relic");
        orb_special=orb_atlas.Find_Atlas_Region("special");
    }
    void Text_layout::init_nums(){
        std::string data="01234\n56789";
        std::shared_ptr<Draw::ReText> nums_text=std::make_shared<Draw::ReText>(s_lan_pos,BIGGIST_SIZE,data.c_str());
        TTF_Font* m_Font=TTF_OpenFont(s_lan_pos, BIGGIST_SIZE);
        int n_w,n_h,t_w=0;
        for(int i=0;i<5;i++){
            TTF_SizeUTF8(m_Font,data.substr(i,1).c_str(),&n_w,&n_h);
            nums[i]=std::make_shared<Draw::Image_Region>(nums_text,t_w,0,n_w,n_h);
            t_w+=n_w;
        }
        t_w=0;
        for(int i=5;i<10;i++){
            TTF_SizeUTF8(m_Font,data.substr(i+1,1).c_str(),&n_w,&n_h);
            nums[i]=std::make_shared<Draw::Image_Region>(nums_text,t_w,n_h,n_w,n_h);
            t_w+=n_w;
        }
        TTF_CloseFont(m_Font);
    }
    void Text_layout::split_text(std::vector<std::string> &strs,const std::string &text_string){
        int sub_st=0,sub_len=0;
        bool color_flag=false,color_end_flag=false,split_flag=false,
             vars_n_orb_flag=false,tail=false;
        //split text
        int str_pos=2;//quick two step
        const int str_len=text_string.length();
        for(const char &c:text_string){
            if(color_flag){
                color_flag=false;
                color_end_flag=true;
            }else if(vars_n_orb_flag){//save [] in strs
                if(c==']'||c=='!'){
                    split_flag=true;
                    vars_n_orb_flag=false;
                    tail=true;
                }
            }else if(c=='#'&&str_pos-1<str_len&&text_string[str_pos]>'9'&&text_string[str_pos]<'0'){
                color_flag=true;
                split_flag=true;
            }else if(str_pos<str_len&&((c=='!'&&text_string[str_pos]=='!')||(c=='['&&text_string[str_pos]==']'))){
                split_flag=true;
                vars_n_orb_flag=true;
            }else if(c==' '&&color_end_flag==true){
                color_end_flag=false;
                split_flag=true;
                tail=true;
            }
            if(split_flag){
                split_flag=false;
                if(sub_len>0){
                    if(tail) sub_len++;
                    strs.emplace_back(text_string.substr(sub_st,sub_len));
                    sub_st+=sub_len;
                    sub_len=0;
                    if(tail) {sub_len--;tail=false;}
                }
            }
            sub_len++;
            str_pos++;
        }
        if(sub_len>0)
            strs.emplace_back(text_string.substr(sub_st,sub_len));
    }
    void Text_layout::set_texture_pos(const std::shared_ptr<Draw::ReText> &t_retext,const std::vector<std::string> &strs){
        width=height=0.0F;
        //goal:set the correct pos in texture & set where vars is.
        //and set w,h
        TTF_Font* m_Font=TTF_OpenFont(s_lan_pos, BIGGIST_SIZE);
        int now_x=0,now_y=0,n_w=0,n_h=0;
        for(const std::string &it:strs){
            this->m_regs_info.emplace_back();
            if(it[0]=='['){
                switch (it[1])
                {
                case 'R':
                    this->regs.emplace_back(this->orb_red);
                    break;
                case 'G':
                    this->regs.emplace_back(this->orb_green);
                    break;
                case 'B':
                    this->regs.emplace_back(this->orb_blue);
                    break;
                case 'W':
                    this->regs.emplace_back(this->orb_purple);
                    break;
                case 'C':
                    this->regs.emplace_back(this->orb_card);
                    break;
                case 'P':
                    this->regs.emplace_back(this->orb_potion);
                    break;
                case 'T':
                    this->regs.emplace_back(this->orb_relic);
                    break;
                case 'S':
                    this->regs.emplace_back(this->orb_special);
                    break;
                default:
                    LOG_ERROR("The orb ID:\"{}\" dosen't exist.",it[1]);
                    break;
                }
                this->m_regs_info.back().w=-1.0F;
            }else if(it[0]=='!'){
                //vars || damage || block
                //space + random width + space
                m_regs_info.back().is_var=true;
                m_regs_info.back().w=-1.0F;
                switch (it[1])
                {
                case 'D':
                    this->damage_pos=(int)m_regs_info.size()-1;
                    break;
                case 'B':
                    this->block_pos=(int)m_regs_info.size()-1;
                    break;
                case 'M':
                    this->pos_and_vars.emplace_back((int)m_regs_info.size()-1,0);
                    break;
                default:
                    LOG_ERROR("The var ID:\"{}\" dosen't exist.",it[1]);
                    break;
                }
            }else{
                if(it[0]=='#'){
                switch (it[1])
                {
                case 'y':
                    m_regs_info.back().c=Setting::GOLD_COLOR;
                    break;
                case 'g':
                    m_regs_info.back().c=Text_layout::GREEN_TEXT_COLOR;
                    break;
                case 'r':
                    m_regs_info.back().c=Text_layout::RED_TEXT_COLOR;
                    break;
                case 'b':
                    m_regs_info.back().c=Text_layout::BLUE_TEXT_COLOR;
                    break;
                case 'p':
                    m_regs_info.back().c=Text_layout::PURPLE_COLOR;
                    break;
                case 'n'://new line, not color
                    now_y+=n_h;
                    now_x=0;
                    break;
                default:
                    LOG_ERROR("The color ID:\"{}\" dosen't exist.",it[1]);
                    m_regs_info.back().c=Text_layout::WHITE;
                    break;
                }
                TTF_SizeUTF8(m_Font,it.substr(2).c_str(),&n_w,&n_h);
                }else{
                    TTF_SizeUTF8(m_Font,it.c_str(),&n_w,&n_h);
                }    
                this->m_regs_info.back().w=(float)n_w;
                this->m_regs_info.back().h=(float)n_h;
                this->regs.emplace_back(std::make_shared<Draw::Image_Region>(t_retext,now_x,now_y,n_w,n_h));
                now_x+=n_w;
            }
            this->m_regs_info.back().y=(float)(-now_y);
        }
        TTF_CloseFont(m_Font);
        height=(float)(now_y+n_h);//set height
        
        //文字以外の部分の高さと幅を設定する
        const float num_h=(float)nums[0]->GetRegionHeight(),
                    num_w=(float)nums[0]->GetRegionWidth(),
                    half_height=height/2.0F;
        for(auto &it:this->m_regs_info){
            it.y-=n_h;
            it.y+=half_height;//fix y to center
            if(it.w==-1){
                if(it.is_var){
                    it.w=(float)n_h/num_h*num_w;
                    it.h=n_h;
                }else{
                    it.w=n_h;
                    it.h=n_h;
                }
            }
        }
        fix_width();
    }
    void Text_layout::fix_width(){
        float temp_width=0.0F,//for store longest width
              temp_now_y=0.0F;
        for(const auto &it:this->m_regs_info){
            if(temp_now_y>it.y){
                temp_now_y=it.y;
                if(temp_width>width)width=temp_width;
                temp_width=0.0F;
            }
            temp_width+=it.w;
        }
        if(temp_width>width)width=temp_width;
    }
    void Text_layout::set_middle(){
        if(!middle_mode){
            //middle mode: x&y are center
            float n_y=0,st_x,total_w;
            int t_len=(int)m_regs_info.size(),l_st=0,l_len=0;
            for(int i=0;i<=t_len;i++){
                if(i==t_len||n_y>m_regs_info[i].y){//may cause new line bug ga,tabunn daijyoubu darou.
                    if(i<t_len) n_y=m_regs_info[i].y;
                    total_w=0;
                    for(int j=0;j<l_len;j++)
                        total_w+=m_regs_info[j+l_st].w;
                    st_x=-total_w/2.0F;
                    for(int j=0;j<l_len;j++){
                        m_regs_info[j+l_st].x=st_x;
                        st_x+=m_regs_info[j+l_st].w;
                    }
                    l_st+=l_len;
                    l_len=0;
                }
                l_len++;
            }
            middle_mode=true;
        }
    }
    void Text_layout::set_left(){
        if(middle_mode){
            //x are left
            //set x
            //y w h c is_var ok
            float n_x=0,n_y=0;
            for(auto &it:this->m_regs_info){
                if(n_y>it.y){//may cause new line bug ga,tabunn daijyoubu darou.
                    n_x=0;
                    n_y=it.y;
                }
                it.x=n_x;
                n_x+=it.w;
            }
            middle_mode=false;
            //fix x to center
            const float half_w=width/2.0F;
            for(auto &it:this->m_regs_info){
                it.x-=half_w;
            }
        }
    }
    void Text_layout::set_fontsize(int fontsize){
        //It just scales the size, but it won't truly change to the fontsize.
        //It might look a bit strange, but I think it is fine.
        if(m_fontsize!=fontsize){
            m_fontsize=fontsize;
            TTF_Font* m_Font=TTF_OpenFont(s_lan_pos, m_fontsize);
            int font_w,font_h;
            TTF_SizeUTF8(m_Font,"A",&font_w,&font_h);
            TTF_CloseFont(m_Font);
            const float font_scale=(float)font_h/this->m_regs_info[0].h;
            this->scale_all_pos(font_scale);
        }
    }
    void Text_layout::set_damage(int value){
        set_things(damage_pos,value,damage);
        damage=value;
    }
    void Text_layout::set_block(int value){
        set_things(block_pos,value,block);
        block=value;
    }
    void Text_layout::set_vars(int value,int pos){
        if(pos>=0&&pos<(int)this->pos_and_vars.size()){
            set_things(pos_and_vars[pos].first,value,pos_and_vars[pos].second);
            pos_and_vars[pos].second=value;
        }
    }
    void Text_layout::set_things(int info_pos,int value,int old_value){
        if(value>=0){
            if(info_pos>=0&&info_pos<(int)m_regs_info.size()){
                int n_l=RUtil::Math::GetIntLength(value),o_l=RUtil::Math::GetIntLength(old_value);
                float n_w=m_regs_info[info_pos].w*((float)n_l/(float)o_l);
                adjust_pos(info_pos,n_w-m_regs_info[info_pos].w);
                m_regs_info[info_pos].w=n_w;
                fix_width();
            }else
                LOG_ERROR("Info_pos are outside the range.");
        }else
            LOG_ERROR("value can't be negative");
    }
    void Text_layout::adjust_pos(int info_pos,float dis){
        const float n_y=this->m_regs_info[info_pos].y;
        if(this->middle_mode){
            dis/=2.0F;
            for(int i=info_pos+1;i<(int)m_regs_info.size()&&n_y<=m_regs_info[i].y;i++)//y check
                m_regs_info[i].x+=dis;
            for(int i=info_pos;i>=0&&n_y<=m_regs_info[i].y;i--)//y check
                m_regs_info[i].x-=dis;
        }else{
            for(int i=info_pos+1;i<(int)m_regs_info.size()&&n_y<=m_regs_info[i].y;i++)//y check
                m_regs_info[i].x+=dis;
        }
    }
    void Text_layout::scale_all_pos(const float scale){
        if(scale!=1.0F){
            //The center is (0,0), so just simply multiply x&y by the scale.
            for(auto&it:this->m_regs_info){
                it.x*=scale;
                it.y*=scale;
                it.w*=scale;
                it.h*=scale;
            }
            width*=scale;
            height*=scale;
        }
    }
    void Text_layout::render(const std::shared_ptr<Draw::Draw_2D> &r2,const float center_x,const float center_y,const float a)const{
        for(int i=0,j=0;i<(int)m_regs_info.size();i++){
            r2->SetColor(m_regs_info[i].c,a);
            if(m_regs_info[i].is_var){
                int need_draw_num=-1;
                if(damage_pos==i)need_draw_num=damage;
                else if(block_pos==i)need_draw_num=block;
                else{
                    for(const auto &var_it:pos_and_vars){
                        if(var_it.first==i){
                            need_draw_num=var_it.second;
                            break;
                        }
                    }
                }
                if(need_draw_num==-1) LOG_ERROR("ERROR when try to draw dynamic number on text");
                else{
                    const int num_len=RUtil::Math::GetIntLength(need_draw_num);
                    const float unit_w=m_regs_info[i].w/(float)num_len;
                    for(int drawing_pos=1;drawing_pos<=num_len;drawing_pos++){
                        r2->draw(nums[need_draw_num%10], m_regs_info[i].x + center_x + unit_w*(num_len-drawing_pos), m_regs_info[i].y+center_y, unit_w, m_regs_info[i].h);
                        need_draw_num/=10;
                    }
                }
            }else{
                r2->draw(this->regs[j++],m_regs_info[i].x+center_x,m_regs_info[i].y+center_y,m_regs_info[i].w,m_regs_info[i].h);
            }
        }
    }
    void Text_layout::render_without_format_word(const std::shared_ptr<Draw::Draw_2D> &r2,const float center_x,const float center_y,const float angle,const float scale,const float origin_x,const float origin_y)const{
        const int info_len=(int)m_regs_info.size();
        for(int i=0;i<info_len;i++){
            r2->draw(this->regs[i], m_regs_info[i].x*scale + center_x, m_regs_info[i].y*scale + center_y, m_regs_info[i].w*scale, m_regs_info[i].h*scale, angle, this->width*scale/2.0F+origin_x, this->height*scale/2.0F+origin_y);
        }
    }
    void Text_layout::render_without_format_word_top_left(const std::shared_ptr<Draw::Draw_2D> &r2,const float x,const float y)const{
        const int info_len=(int)m_regs_info.size();
        for(int i=0;i<info_len;i++){
            r2->draw(this->regs[i], m_regs_info[i].x + x + m_regs_info[i].w/2.0F, m_regs_info[i].y + y - m_regs_info[i].h/2.0F, m_regs_info[i].w, m_regs_info[i].h);
        }
    }
} // namespace Draw
