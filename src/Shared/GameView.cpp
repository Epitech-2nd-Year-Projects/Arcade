#include "GameView.hpp"
#include <utility>

Arcade::Shared::GameView::GameView()
    : m_scene(std::make_unique<Scene::GameScene>()) {}

Arcade::Shared::GameView::~GameView() = default;

Arcade::Shared::GameView::GameView(GameView &&other) noexcept
    : m_score(other.m_score), m_partyDuration(other.m_partyDuration), m_scene(std::move(other.m_scene)) {}

Arcade::Shared::GameView &Arcade::Shared::GameView::operator=(GameView &&other) noexcept
{
  if (this != &other) {
    m_score = other.m_score;
    m_partyDuration = other.m_partyDuration;
    m_scene = std::move(other.m_scene);
  }
  return *this;
}

int Arcade::Shared::GameView::getScore() const
{
  return m_score;
}

void Arcade::Shared::GameView::setScore(int score)
{
  m_score = score;
}

std::chrono::milliseconds Arcade::Shared::GameView::getPartyDuration() const
{
  return m_partyDuration;
}

void Arcade::Shared::GameView::setPartyDuration(std::chrono::milliseconds duration)
{
  m_partyDuration = duration;
}

const Arcade::Shared::Scene::GameScene &Arcade::Shared::GameView::getScene() const
{
  return *m_scene;
}

Arcade::Shared::Scene::GameScene &Arcade::Shared::GameView::getScene()
{
  return *m_scene;
}

void Arcade::Shared::GameView::setScene(std::unique_ptr<Scene::GameScene> scene)
{
  if (scene) {
    m_scene = std::move(scene);
  }
}
