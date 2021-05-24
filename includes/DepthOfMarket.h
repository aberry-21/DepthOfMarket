//
// Created by Aaron Berry on 5/24/21.
//

#pragma once

#include <boost/container/flat_map.hpp>

class DepthOfMarket {
 public:
  typedef boost::container::flat_map<float, std::uint32_t > levels;
  typedef levels &reference;

  enum Types {
    SELL_CODE,
    BUY_CODE
  };

  DepthOfMarket() = default;
  DepthOfMarket(DepthOfMarket const& other) = delete;
  DepthOfMarket &operator=(DepthOfMarket const& other) = delete;
  DepthOfMarket (DepthOfMarket&& other) noexcept = delete;
  DepthOfMarket& operator=(DepthOfMarket&& other) noexcept = delete;
  ~DepthOfMarket() = default;
  void AddLevel(std::uint8_t type, float price, std::uint32_t volume);
  void ChangeLevel(std::uint8_t type, float price, std::uint32_t add_volume);
  void EraseLevel(std::uint8_t type, float price);
  void PrintLevels(std::uint8_t type);
 private:
  levels buy_;
  levels sell_;
  [[nodiscard]] reference GetLevelsByType(std::uint8_t type);
};
