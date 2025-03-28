#pragma once

#include "Drawable.hpp"
#include <memory>
#include <vector>

namespace Arcade::Shared::Scene {

template <typename T>
concept DrawableType = std::is_base_of_v<IDrawable, T>;

class GameScene {
public:
  GameScene() = default;
  ~GameScene();

  GameScene(const GameScene &) = delete;
  GameScene &operator=(const GameScene &) = delete;

  GameScene(GameScene &&other) noexcept;
  GameScene &operator=(GameScene &&other) noexcept;

  void clearDrawables() noexcept;

  template <DrawableType T> void addDrawable(std::unique_ptr<T> drawable) {
    m_drawables.push_back(std::move(drawable));
  }
  void addDrawable(std::unique_ptr<IDrawable> drawable) {
    m_drawables.push_back(std::move(drawable));
  }

  [[nodiscard]] const std::vector<std::unique_ptr<IDrawable>> &
  getDrawables() const noexcept;

  template <typename T>
    requires std::is_base_of_v<IDrawable, T>
  [[nodiscard]] std::vector<T *> getDrawablesByType() {
    std::vector<T *> matchingDrawables;

    for (const auto &drawable : m_drawables) {
      if (T *typedDrawable = dynamic_cast<T *>(drawable.get())) {
        matchingDrawables.push_back(typedDrawable);
      }
    }
    return matchingDrawables;
  }

  void setMapSize(std::size_t width, std::size_t height) noexcept;
  [[nodiscard]] std::pair<std::size_t, std::size_t> getMapSize() const noexcept;

private:
  std::vector<std::unique_ptr<IDrawable>> m_drawables;
  std::pair<std::size_t, std::size_t> m_mapSize = {0, 0};
};
} // namespace Arcade::Shared::Scene
