#pragma once

#include "Drawable.hpp"
#include <memory>
#include <vector>

namespace Arcade::Shared::Scene {
class GameScene {
public:
  void clearDrawables();
  void addDrawable(std::unique_ptr<IDrawable> drawable);
  const std::vector<std::unique_ptr<IDrawable>> &getDrawables() const;

private:
  std::vector<std::unique_ptr<IDrawable>> m_drawables;
};
} // namespace Arcade::Shared::Scene
