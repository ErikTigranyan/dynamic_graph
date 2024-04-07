#include <unordered_map>
#include <vector>
#include <utility>
#include <optional>

class IntermediatePaths{
  private:
  // Define a custom hash function for pairs
  struct pair_hash {
      template <class T1, class T2>
      std::size_t operator() (const std::pair<T1, T2>& pair) const {
          auto hash1 = std::hash<T1>{}(pair.first);
          auto hash2 = std::hash<T2>{}(pair.second);
          return hash1 ^ hash2; 
      }
  };
  public:
    std::unordered_map<std::pair<int, int>, std::vector<int>, pair_hash> paths;

    void add_path(std::pair<int, int>, std::vector<int>);
    std::optional<std::vector<int>>  get_path(int u, int v);
};