#pragma once

#include "GameView.hpp"
#include "ResourceRegistry.hpp"

namespace Arcade::Shared {
class IGame {
public:
  virtual ~IGame() = default;

  virtual void registerResources(ResourceRegistry &registry) = 0;

  virtual GameView &gameLoop() = 0;
};
} // namespace Arcade::Shared
