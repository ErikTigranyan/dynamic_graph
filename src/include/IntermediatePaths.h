#include <unordered_map>
#include <vector>

class IntermediatePaths{
  private:
    std::unordered_map<std::pair<int, int> , std::vector<int> > paths;
  public:

    void add_path(std::pair<int, int> , std::vector<int>);

};