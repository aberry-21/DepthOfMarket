//
// Created by Aaron Berry on 5/24/21.
//

#include <random>
#include <iostream>
#include <map>
#include <thread>
#include "includes/DepthOfMarket.h"
#include "includes/LogDuration.h"

constexpr std::uint32_t FLOAT_MIN = 0;
constexpr std::uint32_t FLOAT_MAX = 100;

static std::shared_ptr<std::vector<std::tuple<std::uint32_t, float, std::uint32_t>>> CreateRandValue(std::uint32_t size) {
  std::random_device rd;
  std::default_random_engine eng(rd());
  std::map<float, std::tuple<std::uint32_t, std::uint32_t>> rand_value;
  for (std::uint32_t n = 0; n < size; ++n) {
    std::uniform_int_distribution<std::uint32_t> type_range(0, 1);
    std::uint32_t type = type_range(eng);
    std::uniform_int_distribution<std::uint32_t> type_volume(50, 10000);
    std::uint32_t volume = type_volume(eng);
    std::uniform_real_distribution<float> distr(FLOAT_MIN, FLOAT_MAX);
    rand_value.emplace((distr(eng) * 1000.0) / 1000.0, std::tuple<std::uint32_t, std::uint32_t>(type, volume));
  }
  std::vector<std::tuple<std::uint32_t, float, std::uint32_t>> v_rand_value;
  v_rand_value.reserve(rand_value.size());
  auto iter = rand_value.begin();
  for (; iter != rand_value.cend(); ++iter) {
    v_rand_value.emplace_back(std::make_tuple(std::get<0>(iter->second), iter->first, std::get<1>(iter->second)));
  }
  return std::make_shared<std::vector<std::tuple<std::uint32_t, float, std::uint32_t>>>(v_rand_value);
}

static void TestSpeed(std::uint32_t size) {
  DepthOfMarket dop;
  std::random_device rd;
  std::default_random_engine eng(rd());
  std::cout << "TEST WITH " << size << " value" << std::endl;
  auto rand_vector = CreateRandValue(size);
  std::uniform_int_distribution<std::uint32_t> type_range(0, rand_vector->size()/10);
  {
    LOG_DURATION("Testing add");
    for (size_t i = 0; i < rand_vector->size(); ++i) {
      dop.AddLevel(std::get<0>((*rand_vector)[i]),
                   std::get<1>((*rand_vector)[i]),
                   std::get<2>((*rand_vector)[i]));
    }
  }
  {
    LOG_DURATION("Testing change");
    for (size_t i = 0; i < rand_vector->size()/10; ++i) {
      std::uint32_t type = type_range(eng);
      dop.ChangeLevel(std::get<0>((*rand_vector)[type]),
                   std::get<1>((*rand_vector)[type]),
                   std::get<2>((*rand_vector)[i]));
    }
  }
  {
    LOG_DURATION("Testing erase");
    for (size_t i = 0; i < rand_vector->size() / 100; ++i) {
      std::uint32_t type = type_range(eng);
      dop.EraseLevel(std::get<0>((*rand_vector)[type]),
                     std::get<1>((*rand_vector)[type]));
    }
  }
  std::this_thread::sleep_for(1000ms);
}

// Example
int main() {
  DepthOfMarket dop;

  // add
  dop.AddLevel(DepthOfMarket::Types::SELL_CODE, 0.1, 10);
  dop.AddLevel(DepthOfMarket::Types::SELL_CODE, 1.0, 10);
  dop.AddLevel(DepthOfMarket::Types::SELL_CODE, 1.12, 10);
  dop.AddLevel(DepthOfMarket::Types::SELL_CODE, 1.2, 100);
  dop.AddLevel(DepthOfMarket::Types::BUY_CODE, 1.23, 150);
  dop.AddLevel(DepthOfMarket::Types::BUY_CODE, 2.12, 10);
  dop.AddLevel(DepthOfMarket::Types::BUY_CODE, 1.0, 150);
  dop.AddLevel(DepthOfMarket::Types::BUY_CODE, 0.1, 1110);

  // change
  dop.ChangeLevel(DepthOfMarket::Types::SELL_CODE, 1.2, 155);
  dop.ChangeLevel(DepthOfMarket::Types::BUY_CODE, 1.23, 1);

  // erase
  dop.EraseLevel(DepthOfMarket::Types::SELL_CODE, 1.0);
  dop.EraseLevel(DepthOfMarket::Types::BUY_CODE, 1.0);

  // print
  dop.PrintLevels(DepthOfMarket::Types::BUY_CODE);
  dop.PrintLevels(DepthOfMarket::Types::SELL_CODE);

  // Speed test
  std::this_thread::sleep_for(1000ms);
  std::cout << std::endl;
  TestSpeed(100);
  std::cout << std::endl;
  TestSpeed(1000);
  std::cout << std::endl;
  TestSpeed(10000);
  std::cout << std::endl;
  TestSpeed(100000);
  std::cout << std::endl;
  return EXIT_SUCCESS;
}
