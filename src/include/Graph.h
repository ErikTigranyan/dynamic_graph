#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> Matrix;

class Graph{
  private:
    Matrix g;
    std::vector<bool> active_crossroads;
    std::size_t size;

  public:
    bool active;

    Graph(std::size_t size_): g(size_), size(size_), active_crossroads(size_, true), active(1){
      for(int i = 0; i < size_; i++){
        g[i].resize(size_);
      }
    }

    Graph(const Graph& other);
    void add_crossroad(int v);
    void remove_crossroad(int v);
    void add_street(int u, int v, std::size_t length);
    void remove_street(int u, int v);

    Matrix get() {return g;}
    // operator*
    std::vector<int>& operator[] (std::size_t i){
      return g[i];
    }
    void self_print();
    void initialize();
};