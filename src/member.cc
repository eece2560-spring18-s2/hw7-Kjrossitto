#include "member.h"

#include <queue>

#include "database.h"

namespace algdb {

void Member::DumpConnections() {
  std::cout << "(" << member_id << ")";
  for (auto &m : connecting_members) {
    auto conn = m.second;
    std::cout << "->" << conn.dst->member_id << 
      "(" << conn.group->group_id << ")";
  }
  std::cout << "\n";
}

void Member::PathToMemberBFS(uint64_t dst_member_id) {
  // Fill in your code here.
    std::queue<Member*> Q;
    Member *u;
    Member *v;
    Member *source=this;
    source->color=COLOR_GRAY;
    source->key=0;
    source->parent=NULL;
      //empty queue 
      while(!Q.empty()){
        Q.pop();
        }
      Q.push(source);
      //start while loop
      while(!Q.empty()){
        u=Q.front();
        Q.pop();
        //Iterate through U's connecting members
        //for(unsigned int i=0; i<u->connecting_members.size();i++){
        for(auto it=u->connecting_members.begin(); it!=u->connecting_members.end(); it++){
          v=it->second.dst;
          if(v->color==COLOR_WHITE){
           v->color=COLOR_GRAY;
           v->key=u->key+1;
           v->parent=u;
           Q.push(v);
          }
        }
        u->color=COLOR_BLACK;
      }
    }

Member* Member::DLS(Member *node, uint64_t dst_member_id, double key){
  Member *found;
  if(key==0 && node->member_id==dst_member_id){
    return node;
  }
  if(key>0){
    for(auto it=node->connecting_members.begin(); it != node->connecting_members.end();it++){
      it->second.dst->parent=node;
      found=DLS(it->second.dst,dst_member_id,key-1);
      if(found!=NULL){
        return found;
      }
    }
  }
  return NULL;
}
void Member::PathToMemberIDDFS(uint64_t dst_member_id) {
  // Fill in your code here
  Member *source=this;
  for(double key=0; key<999;key++){
    DLS(source,dst_member_id,key);
  }
}
  
void Member::PrintPath(Member* dst) {
  Member *curr = dst;
  while(curr && curr != this) {
    std::cout << curr->member_name << " <- ";
    curr = curr->parent;
  }
  std::cout << this->member_name << "\n";
}

}
