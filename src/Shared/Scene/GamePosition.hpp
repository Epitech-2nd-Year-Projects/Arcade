#pragma once

#include <utility>

namespace Arcade::Shared::Scene {
class GamePosition {
public:
  void setPosition(float x, float y);
  std::pair<float, float> getPosition() const;

private:
  float m_x = 0;
  float m_y = 0;
};
} // namespace Arcade::Shared::Scene
