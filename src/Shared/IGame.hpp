#pragma once

namespace Arcade::Shared {
class IGame {
public:
  virtual ~IGame() = default;

  virtual void gameLoop() = 0;
};
} // namespace Arcade::Shared
