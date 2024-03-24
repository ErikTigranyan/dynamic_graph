#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> Matrix;

class Graph{
  private:
    Matrix g;
    std::vector<bool> crossroad_active;
    std::size_t size;

  public:
    bool active;

    Graph(std::size_t size_): g(size_), size(size_), crossroad_active(size_, true), active(1){
      for(int i = 0; i < size_; i++){
        g[i].resize(size_);
      }
    }


    Graph(const Graph& other);
    Matrix get() {return g;}
    // operator*
    std::vector<int> operator[] (std::size_t i){
      return g[i];
    }
};