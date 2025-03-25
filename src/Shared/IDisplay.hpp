#pragma once

#include "IGameView.hpp"

namespace Arcade::Shared {
class IDisplay {
public:
  virtual ~IDisplay() = default;

  virtual void display(IGameView &gameView) = 0;
};
} // namespace Arcade::Shared
