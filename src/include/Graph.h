#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> Matrix;

class Graph{
  private:
    Matrix g;
    std::size_t size;
    bool active;

  public:
    Graph(std::size_t size_): g(size_), size(size_), active(1){
      for(int i = 0; i < size_; i++){
        g[i].resize(size_);
      }
    }

    Matrix get() {return g;}
    // operator*
    //operator[]  
};