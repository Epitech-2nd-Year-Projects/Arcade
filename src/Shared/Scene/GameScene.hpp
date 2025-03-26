#pragma once

#include "Drawable.hpp"
#include <memory>
#include <vector>

namespace Arcade::Shared::Scene {
class GameScene {
public:
  GameScene() = default;
  ~GameScene();

  GameScene(const GameScene &) = delete;
  GameScene &operator=(const GameScene &) = delete;

  GameScene(GameScene &&other) noexcept;
  GameScene &operator=(GameScene &&other) noexcept;

  void clearDrawables();
  void addDrawable(std::unique_ptr<IDrawable> drawable);
  const std::vector<std::unique_ptr<IDrawable>> &getDrawables() const;

  void setMapSize(std::size_t width, std::size_t height);
  std::pair<std::size_t, std::size_t> getMapSize() const;

private:
  std::vector<std::unique_ptr<IDrawable>> m_drawables;
  std::pair<std::size_t, std::size_t> m_mapSize = {0, 0};
};
} // namespace Arcade::Shared::Scene
