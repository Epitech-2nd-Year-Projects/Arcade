#pragma once

#include "IGameView.hpp"
namespace Arcade::Shared {
class IGame {
public:
  virtual ~IGame() = default;

  virtual IGameView &gameLoop() = 0;
};
} // namespace Arcade::Shared
