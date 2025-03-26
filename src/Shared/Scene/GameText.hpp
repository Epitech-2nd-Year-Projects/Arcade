#pragma once

#include "GamePosition.hpp"
#include <string>

namespace Arcade::Shared::Scene {
class GameText {
public:
  void setPosition(float x, float y);
  std::pair<float, float> getPosition() const;

  void setText(const std::string &text);
  const std::string &getText() const;

private:
  GamePosition m_position;
  std::string m_text;
};
} // namespace Arcade::Shared::Scene
