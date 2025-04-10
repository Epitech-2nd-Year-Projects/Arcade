#include "GameScene.hpp"
#include <algorithm>
#include <utility>

Arcade::Shared::Scene::GameScene::~GameScene() = default;

Arcade::Shared::Scene::GameScene::GameScene(GameScene &&other) noexcept
    : m_drawables(std::move(other.m_drawables)),
      m_mapSize(std::move(other.m_mapSize)) {}

Arcade::Shared::Scene::GameScene &
Arcade::Shared::Scene::GameScene::operator=(GameScene &&other) noexcept {
  if (this != &other) {
    m_drawables = std::move(other.m_drawables);
    m_mapSize = std::move(other.m_mapSize);
  }
  return *this;
}

void Arcade::Shared::Scene::GameScene::clearDrawables() noexcept {
  m_drawables.clear();
}

const std::vector<std::unique_ptr<Arcade::Shared::Scene::IDrawable>> &
Arcade::Shared::Scene::GameScene::getDrawables() const noexcept {
  return m_drawables;
}

void Arcade::Shared::Scene::GameScene::setMapSize(std::size_t width,
                                                  std::size_t height) noexcept {
  m_mapSize = std::make_pair(width, height);
}

std::pair<std::size_t, std::size_t>
Arcade::Shared::Scene::GameScene::getMapSize() const noexcept {
  return m_mapSize;
}
