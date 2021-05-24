//
// Created by Aaron Berry on 5/24/21.
//

#include <iostream>
#include "includes/DepthOfMarket.h"

//                                 Private

DepthOfMarket::reference DepthOfMarket::GetLevelsByType(std::uint8_t type) {
  switch (type) {
    case DepthOfMarket::Types::SELL_CODE: return sell_;
    case DepthOfMarket::Types::BUY_CODE: return buy_;
    default: throw std::runtime_error("Error type");
  }
}

//                                 Public

void DepthOfMarket::AddLevel(std::uint8_t type,
                             float price,
                             std::uint32_t volume) {
  auto &target = GetLevelsByType(type);
  if (target.contains(price)) {
    throw std::runtime_error("Error: value already exit");
  }
  target.emplace(price, volume);
}

void DepthOfMarket::ChangeLevel(std::uint8_t type,
                                float price,
                                std::uint32_t new_volume) {
  auto &target = GetLevelsByType(type);
  if (!target.contains(price)) {
    throw std::runtime_error("Error: value no exit");
  }
  target.at(price) = new_volume;
}

void DepthOfMarket::EraseLevel(std::uint8_t type, float price) {
  auto &target = GetLevelsByType(type);
  target.erase(price);
}

void DepthOfMarket::PrintLevels(std::uint8_t type) {
  auto &target = GetLevelsByType(type);
  auto print = [](auto& iter) {
    std::cout.width(15);
    std::cout << iter.first << std::internal;
    std::cout.width(15);
    std::cout << iter.second << std::endl;
  };
  if (type == DepthOfMarket::Types::SELL_CODE) {
    for (const auto &item : target) {
      std::cout << "SELL" << std::internal;
      print(item);
    }
  } else {
    auto current = target.crbegin();
    for (;current < target.crend(); ++current){
      std::cout << "BUY " << std::internal;
      print(*current);
    }
  }
}
