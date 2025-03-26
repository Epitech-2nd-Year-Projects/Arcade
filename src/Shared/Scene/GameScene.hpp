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
  std::pair<std::size_t, std::size_t> m_mapSize = {0, 0};
};
} // namespace Arcade::Shared::Scene
