#include<iostream>
#include<algorithm>
int x,y,w,h;
int main(){
std::cin>>x>>y>>w>>h;
std::cout<<std::min({x,w-x,y,h-y});
}
