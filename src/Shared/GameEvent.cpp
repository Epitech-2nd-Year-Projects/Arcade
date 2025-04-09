#include "GameEvent.hpp"

Arcade::Shared::GameEvent::GameEvent() : m_type(Type::None) {}

Arcade::Shared::GameEvent::GameEvent(Type type) : m_type(type) {}

Arcade::Shared::GameEvent::Type Arcade::Shared::GameEvent::getType() const {
  return m_type;
}

void Arcade::Shared::GameEvent::setType(Type type) { m_type = type; }
