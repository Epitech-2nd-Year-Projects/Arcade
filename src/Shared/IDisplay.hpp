#pragma once

#include "GameView.hpp"

namespace Arcade::Shared {
class IDisplay {
public:
  virtual ~IDisplay() = default;

  virtual void display(GameView &gameView) = 0;
};
} // namespace Arcade::Shared
