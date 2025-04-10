#include "ResourceRegistry.hpp"

namespace Arcade::Shared::Resource {

ResourceRegistry &ResourceRegistry::getInstance() {
  static ResourceRegistry instance;
  return instance;
}

void ResourceRegistry::registerResource(
    const ResourceIdentifier &id, const std::filesystem::path &graphicalPath,
    const std::string &textRepresentation) {
  m_graphicalPaths[id] = graphicalPath;
  m_textRepresentations[id] = textRepresentation;
}

std::filesystem::path
ResourceRegistry::getGraphicalPath(const ResourceIdentifier &id) const {
  auto it = m_graphicalPaths.find(id);
  if (it != m_graphicalPaths.end()) {
    return it->second;
  }
  return {};
}

std::string
ResourceRegistry::getTextRepresentation(const ResourceIdentifier &id) const {
  auto it = m_textRepresentations.find(id);
  if (it != m_textRepresentations.end()) {
    return it->second;
  }
  return "";
}

void ResourceRegistry::reset() {
  m_graphicalPaths.clear();
  m_textRepresentations.clear();
}

} // namespace Arcade::Shared::Resource
