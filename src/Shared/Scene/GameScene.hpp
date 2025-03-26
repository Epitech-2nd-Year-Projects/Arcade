#pragma once

#include "GameText.hpp"
#include <vector>

namespace Arcade::Shared::Scene {
class GameScene {
public:
  void clear();

  void pushText(const GameText &text);
  const std::vector<GameText> &getTexts() const;

private:
  std::vector<GameText> m_texts;
};
} // namespace Arcade::Shared::Scene
