#pragma once

namespace Arcade::Shared {
class GameEvent {
public:
  enum class Type { Up, Down, Left, Right, Quit, None };

  GameEvent();
  explicit GameEvent(Type type);

  Type getType() const;
  void setType(Type type);

private:
  Type m_type;
};
} // namespace Arcade::Shared
