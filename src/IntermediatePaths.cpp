#include "include/IntermediatePaths.h"
#include <stdexcept>
#include <iostream>


void IntermediatePaths::add_path(std::pair<int, int> vertexes, std::vector<int> route){
  paths[vertexes] = route;
}

std::optional<std::vector<int>> IntermediatePaths::get_path(int u, int v){
  try{
    return paths.at(std::make_pair(u, v));
  }catch(const std::out_of_range& e) {
    std::cout << "WARNING: no path is saved for " << u << ", " << v << std::endl;
    return std::nullopt;
  }
}