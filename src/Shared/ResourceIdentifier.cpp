#include "ResourceIdentifier.hpp"

Arcade::Shared::ResourceIdentifier::ResourceIdentifier(ResourceType type, const std::string& id)
  : m_type(type), m_id(id) {}

Arcade::Shared::ResourceType Arcade::Shared::ResourceIdentifier::getType() const { return m_type; }

const std::string& Arcade::Shared::ResourceIdentifier::getId() const { return m_id; }



