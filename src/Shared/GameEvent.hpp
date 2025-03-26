#pragma once

namespace Arcade::Shared {
class GameEvent {
public:
  enum class Type { Up, Down, Left, Right, Quit };

private:
  Type m_type;
};
} // namespace Arcade::Shared
