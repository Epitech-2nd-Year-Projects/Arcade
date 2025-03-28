#pragma once

#include "Scene/GameScene.hpp"
#include <chrono>
#include <memory>

namespace Arcade::Shared {
class GameView {
public:
  GameView();
  ~GameView();

  GameView(const GameView &) = delete;
  GameView &operator=(const GameView &) = delete;

  GameView(GameView &&other) noexcept;
  GameView &operator=(GameView &&other) noexcept;

  int getScore() const;
  void setScore(int score);

  std::chrono::milliseconds getPartyDuration() const;
  void setPartyDuration(std::chrono::milliseconds duration);

  const Scene::GameScene &getScene() const;
  Scene::GameScene &getScene();
  void setScene(std::unique_ptr<Scene::GameScene> scene);

private:
  int m_score = 0;
  std::chrono::milliseconds m_partyDuration = std::chrono::milliseconds(0);
  std::unique_ptr<Scene::GameScene> m_scene;
};
} // namespace Arcade::Shared
