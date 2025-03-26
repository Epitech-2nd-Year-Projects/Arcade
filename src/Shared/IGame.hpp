#pragma once

#include "GameView.hpp"

namespace Arcade::Shared {
class IGame {
public:
  virtual ~IGame() = default;

  virtual GameView &gameLoop() = 0;
};
} // namespace Arcade::Shared
