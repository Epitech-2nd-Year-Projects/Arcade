#pragma once

#include <string>

namespace Arcade::Shared {
enum class ResourceType {
  Player,
  Enemy,
  Wall,
  Floor,
};

class ResourceIdentifier {
public:
  ResourceIdentifier(ResourceType type, const std::string &id);
  ~ResourceIdentifier() = default;

  ResourceType getType() const;
  const std::string &getId() const;

private:
  ResourceType m_type;
  std::string m_id;
};
}