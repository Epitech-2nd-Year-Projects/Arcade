#pragma once

#include <string>

namespace Arcade::Shared::Resource {
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

  bool operator<(const ResourceIdentifier &other) const;

private:
  ResourceType m_type;
  std::string m_id;
};
} // namespace Arcade::Shared::Resource