//
// Created by Aaron Berry on 5/24/21.
//

#include "includes/DepthOfMarket.h"

#include <boost/container/flat_map.hpp>
#include <iostream>
#include <map>

int main() {
  DepthOfMarket dop;

  dop.AddLevel(DepthOfMarket::Types::SELL_CODE, 1.2, 100);
  dop.AddLevel(DepthOfMarket::Types::SELL_CODE, 1.12, 10);
  dop.AddLevel(DepthOfMarket::Types::SELL_CODE, 12.2, 1000);
  dop.AddLevel(DepthOfMarket::Types::SELL_CODE, 1.352, 100);
  dop.AddLevel(DepthOfMarket::Types::SELL_CODE, 4.42, 1000);
  dop.AddLevel(DepthOfMarket::Types::SELL_CODE, 0.2, 100);
  dop.AddLevel(DepthOfMarket::Types::BUY_CODE, 1.2, 100);
  dop.AddLevel(DepthOfMarket::Types::BUY_CODE, 1.12, 10);
  dop.AddLevel(DepthOfMarket::Types::BUY_CODE, 12.2, 1000);
  dop.AddLevel(DepthOfMarket::Types::BUY_CODE, 1.352, 100);
  dop.AddLevel(DepthOfMarket::Types::BUY_CODE, 4.42, 1000);
  dop.AddLevel(DepthOfMarket::Types::BUY_CODE, 0.2, 100);

  dop.PrintLevels(DepthOfMarket::Types::BUY_CODE);
  dop.PrintLevels(DepthOfMarket::Types::SELL_CODE);
}