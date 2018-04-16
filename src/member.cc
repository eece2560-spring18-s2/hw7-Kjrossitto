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
    // std::unique_ptr<Member> source(new Member());
    // std::unique_ptr<Member> u(new Member());
    Member *source;
    Member *u;
    for(Group *g : groups){
    unsigned int g_size;
    g_size=g->members.size();
    for(unsigned int i=0;i<g_size;i++){
        g->members[i]->color=COLOR_WHITE;
        g->members[i]->key=99999;
        g->members[i]->parent=NULL;
        if(g->members[i]->member_id==dst_member_id){
          g->members[i]->color=COLOR_GRAY;
          g->members[i]->key=0;
          g->members[i]->parent=NULL;
          source= g->members[i]; //store pointer to source
        }
      }
      //empty queue 
      while(!Q.empty()){
        Q.pop();
        }
      Q.push(source);
      while(!Q.empty()){
        u=Q.back();
        Q.pop();
        for(unsigned int i=0; i<u->connecting_members.size();i++){
          if(u->connecting_members[i].dst->color==COLOR_WHITE){
            u->connecting_members[i].dst->color=COLOR_GRAY;
            u->connecting_members[i].dst->key=u->key;
            u->connecting_members[i].dst->parent=u;
            Q.push(u->connecting_members[i].dst);
          }
        }
        u->color=COLOR_BLACK;
      }
    }
  }


void Member::PathToMemberIDDFS(uint64_t dst_member_id) {
  // Fill in your code here
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
