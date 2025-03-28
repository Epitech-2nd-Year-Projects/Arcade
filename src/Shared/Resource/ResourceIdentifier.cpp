#include "ResourceIdentifier.hpp"

Arcade::Shared::Resource::ResourceIdentifier::ResourceIdentifier(
    ResourceType type,
    const std::string &id)
    : m_type(type), m_id(id) {}

Arcade::Shared::Resource::ResourceType
Arcade::Shared::Resource::ResourceIdentifier::getType() const {
  return m_type;
}

const std::string &
Arcade::Shared::Resource::ResourceIdentifier::getId() const {
  return m_id;
}

bool Arcade::Shared::Resource::ResourceIdentifier::operator<(
    const ResourceIdentifier &other) const {
  if (m_type != other.m_type)
    return static_cast<int>(m_type) < static_cast<int>(other.m_type);
  return m_id < other.m_id;
}
