#pragma once
#include <iostream>
#include <vector>


#define INF 9e8

typedef std::vector<std::vector<int>> Matrix;

class Graph{
  private:
    Matrix g;
    std::vector<bool> active_crossroads;

  public:
    std::size_t size;
    bool active;

    Graph() {}
    Graph(std::size_t size_): g(size_), size(size_), active_crossroads(size_, true), active(1){
      for(int i = 0; i < size_; i++){
        g[i].resize(size_);
        for(int j=0;j<size_;j++) {
          g[i][j] = INF;
        }
      }
    }

    Graph(const Graph& other);
    void add_crossroad(int v);
    void remove_crossroad(int v);
    void add_street(int u, int v, std::size_t length);
    void remove_street(int u, int v);

    Matrix get() {return g;}
    // operator*
    // std::size_t size(){ return g.size(); }
    std::vector<int>& operator[] (std::size_t i){
      return g[i];
    }

    void self_print();
    void initialize(); 
};