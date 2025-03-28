#include "GameScene.hpp"
#include <algorithm>
#include <utility>

Arcade::Shared::Scene::GameScene::~GameScene() = default;

Arcade::Shared::Scene::GameScene::GameScene(GameScene &&other) noexcept
    : m_drawables(std::move(other.m_drawables)),
      m_mapSize(std::move(other.m_mapSize))
{
}

Arcade::Shared::Scene::GameScene &Arcade::Shared::Scene::GameScene::operator=(GameScene &&other) noexcept
{
  if (this != &other) {
    m_drawables = std::move(other.m_drawables);
    m_mapSize = std::move(other.m_mapSize);
  }
  return *this;
}

void Arcade::Shared::Scene::GameScene::clearDrawables()
{
  m_drawables.clear();
}

void Arcade::Shared::Scene::GameScene::addDrawable(std::unique_ptr<Arcade::Shared::Scene::IDrawable> drawable)
{
  if (drawable) {
    m_drawables.push_back(std::move(drawable));
  }
}

const std::vector<std::unique_ptr<Arcade::Shared::Scene::IDrawable>> &Arcade::Shared::Scene::GameScene::getDrawables() const
{
  return m_drawables;
}

void Arcade::Shared::Scene::GameScene::setMapSize(std::size_t width, std::size_t height)
{
  m_mapSize = std::make_pair(width, height);
}

std::pair<std::size_t, std::size_t> Arcade::Shared::Scene::GameScene::getMapSize() const
{
  return m_mapSize;
}

