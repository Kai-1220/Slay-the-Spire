#include "Game_object/map/Map_generator.hpp"
#include "Util/Logger.hpp"
#include "RUtil/Some_Math.hpp"
#include "Game_object/room/Monster_room.hpp"
namespace Map{
std::vector<std::vector<std::shared_ptr<Map_node>>> Map_generator::Get_Map(int height,int width,int density,const std::shared_ptr<RUtil::Random> &rng){
    std::vector<std::vector<std::shared_ptr<Map_node>>> map(height,std::vector<std::shared_ptr<Map_node>>(width));
    
    int first_node=-1;
    for(int i=0;i<density;i++){//try create density times
        int start_node=rng->NextInt(width);
        if(i==0)first_node=start_node;//set first node
        while(start_node==first_node&&i==1) start_node=rng->NextInt(width);//make sure path at least two
        
        //start creat path from start node
        int now_node_y=0,now_node_x=start_node,
            next_node_y,next_node_x;
        while(now_node_y+1<height){
            if(map[now_node_y][now_node_x]==nullptr)map[now_node_y][now_node_x]=std::make_shared<Map::Map_node>(now_node_x,now_node_y);
            next_node_x=now_node_x+rng->NextInt(now_node_x==0?0:-1,now_node_x==width-1?0:1);
            next_node_y=now_node_y+1;

            //check parent same // write later
            
            //check not cross
            //to  b
            //a  now
            //check a to b edge
            if(now_node_x!=0){
                if(map[now_node_y][now_node_x-1]->CanMoveRight()&&next_node_x==now_node_x-1){
                    next_node_x=now_node_x;
                }
            }
            //b to
            //now a
            if(now_node_x!=width-1){
                if(map[now_node_y][now_node_x+1]->CanMoveLeft()&&next_node_x==now_node_x+1){
                    next_node_x=now_node_x;
                }
            }
            
            //this is so long.... but I think it's ok.
            std::shared_ptr<Map_edge> Next_edge=std::make_shared<Map_edge>(map[now_node_y][now_node_x]->GetX(),map[now_node_y][now_node_x]->GetY(),map[next_node_y][next_node_x]->GetX(),map[next_node_y][next_node_x]->GetY(),
                                                            map[now_node_y][now_node_x]->GetOffsetX(),map[now_node_y][now_node_x]->GetOffsetY(),map[next_node_y][next_node_x]->GetOffsetX(),map[next_node_y][next_node_x]->GetOffsetY(),false);
            switch(next_node_x-now_node_x){
                case 1:
                    if(!map[now_node_y][now_node_x]->CanMoveRight()){
                        map[now_node_y][now_node_x]->SetRight(true);
                        map[now_node_y][now_node_x]->add_edge(Next_edge);
                    }
                    break;
                case 0:
                    if(!map[now_node_y][now_node_x]->CanMoveMiddle()){
                        map[now_node_y][now_node_x]->SetMiddle(true);
                        map[now_node_y][now_node_x]->add_edge(Next_edge);
                    }
                    break;
                case -1:
                    if(!map[now_node_y][now_node_x]->CanMoveLeft()){
                        map[now_node_y][now_node_x]->SetLeft(true);
                        map[now_node_y][now_node_x]->add_edge(Next_edge);
                    }
                    break;
                default:
                    LOG_ERROR("The logic is dead, when generate Map path");
                    break;
            }
            now_node_y=next_node_y;
            now_node_x=next_node_x;
        }
        if(!map[now_node_y][now_node_x]->CanToBoss()){
            map[now_node_y][now_node_x]->SetToBoss(true);
            map[now_node_y][now_node_x]->add_edge(std::make_shared<Map_edge>(map[now_node_y][now_node_x]->GetX(),map[now_node_y][now_node_x]->GetY(), 3, now_node_y+2, map[now_node_y][now_node_x]->GetOffsetX(),map[now_node_y][now_node_x]->GetOffsetY(),0.0F,0.0F,true));//あたまおかしくなってる
        }
    }
    
    AssignRoom(map);
    return map;
}
void Map_generator::AssignRoom(const std::vector<std::vector<std::shared_ptr<Map_node>>>&map){
    float nor_monster=s_monster_chance;
    RUtil::Math::Normalize(nor_monster);
    int available_room=0;
    for(const auto &it1:map) for(const auto &it2:it1) if(it2!=nullptr) available_room++;
    //room multiply some other chance, and 残ったのはモンスターのへやだ
    int remain_room=available_room;
    //...
    int monster_room=remain_room;
    //shuffle
    //...
    for(const auto &it1:map) for(const auto &it2:it1)if(it2!=nullptr) it2->SetRoom(std::make_shared<Room::Monster_room>());
}
void Map_generator::SetChance(float value,Room::Room_type type){
    switch(type){
        case Room::Room_type::Monster:
            s_monster_chance=value;
            break;
        default:
            LOG_ERROR("Map_generator:Type doesn't exist.");
            break;
    }
}
float Map_generator::s_monster_chance=1.0F;
}