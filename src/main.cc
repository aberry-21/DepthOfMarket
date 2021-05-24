//
// Created by Aaron Berry on 5/24/21.
//

#include <random>
#include <iostream>
#include <map>
#include "includes/DepthOfMarket.h"

using namespace std;
using namespace std::chrono;

class LogDuration {
 public:
  explicit LogDuration(const string& msg = "")
      : message(msg + ": ")
      , start(steady_clock::now())
  {
  }

  ~LogDuration() {
    auto finish = steady_clock::now();
    auto dur = finish - start;
    cerr << message
         << duration_cast<milliseconds>(dur).count()
         << " ms" << endl;
  }
 private:
  string message;
  steady_clock::time_point start;
};

#define UNIQ_ID_IMPL(lineno) _a_local_var_##lineno
#define UNIQ_ID(lineno) UNIQ_ID_IMPL(lineno)

#define LOG_DURATION(message) \
  LogDuration UNIQ_ID(__LINE__){message};

constexpr int FLOAT_MIN = 0;
constexpr int FLOAT_MAX = 100;

// Example
int main() {
  DepthOfMarket dop;
  std::random_device rd;
  std::default_random_engine eng(rd());

  std::vector<std::tuple<int, float, int>> rand_value;
  rand_value.reserve(10000);
  for (int n = 0; n < 10000; ++n) {
    std::uniform_int_distribution<int> type_range(0, 1);
    int type = type_range(eng);
    std::uniform_int_distribution<int> type_volume(50, 10000);
    int volume = type_volume(eng);
    std::uniform_real_distribution<float> distr(FLOAT_MIN, FLOAT_MAX);
    rand_value.emplace_back(std::tuple<int, float, int>(type, (distr(eng) * 1000.0) / 1000.0, volume));
  }
  std::map<float, std::uint32_t> rand_map;
  LOG_DURATION("test");
  for (int i = 0; i < 10000; ++i) {
    rand_map.emplace(std::get<1>(rand_value[i]), std::get<2>(rand_value[i]));
    dop.AddLevel(std::get<0>(rand_value[i]), std::get<1>(rand_value[i]), std::get<2>(rand_value[i]));
  }


  // add
  dop.AddLevel(DepthOfMarket::Types::SELL_CODE, 1.2, 100);
  dop.AddLevel(DepthOfMarket::Types::SELL_CODE, 1.12, 10);
  dop.AddLevel(DepthOfMarket::Types::SELL_CODE, 1.0, 10);
  dop.AddLevel(DepthOfMarket::Types::BUY_CODE, 1.0, 150);
  dop.AddLevel(DepthOfMarket::Types::BUY_CODE, 1.23, 150);
  dop.AddLevel(DepthOfMarket::Types::BUY_CODE, 2.12, 10);

  // change
  dop.ChangeLevel(DepthOfMarket::Types::SELL_CODE, 1.2, 155);
  dop.ChangeLevel(DepthOfMarket::Types::BUY_CODE, 1.23, 1);

  // erase
  dop.EraseLevel(DepthOfMarket::Types::SELL_CODE, 1.0);
  dop.EraseLevel(DepthOfMarket::Types::BUY_CODE, 1.0);

   print
  dop.PrintLevels(DepthOfMarket::Types::BUY_CODE);
  dop.PrintLevels(DepthOfMarket::Types::SELL_CODE);
  return EXIT_SUCCESS;
}
