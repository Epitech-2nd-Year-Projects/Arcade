#pragma once

#include <filesystem>
#include <map>
#include "ResourceIdentifier.hpp"

namespace Arcade::Shared {
class ResourceRegistry {
public:
  ResourceRegistry() = default;
  ~ResourceRegistry() = default;

  void registerResource(
    const ResourceIdentifier &id,
    const std::filesystem::path &graphicalPath,
    const std::string &textRepresentation
    );

  static ResourceRegistry &getInstance();

  std::filesystem::path getGraphicalPath(const ResourceIdentifier &id) const;

  std::string getTextRepresentation(const ResourceIdentifier &id) const;

  void reset();

private:
  std::map<ResourceIdentifier, std::filesystem::path> m_graphicalPaths;
  std::map<ResourceIdentifier, std::string> m_textRepresentations;
};
}
