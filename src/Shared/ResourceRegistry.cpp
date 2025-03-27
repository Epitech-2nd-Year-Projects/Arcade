#include "ResourceRegistry.hpp"

Arcade::Shared::ResourceRegistry &Arcade::Shared::ResourceRegistry::getInstance() {
  static ResourceRegistry instance;
  return instance;
}

void Arcade::Shared::ResourceRegistry::registerResource(const ResourceIdentifier &id, const std::filesystem::path& graphicalPath, const std::string& textRepresentation) {
  m_graphicalPaths[id] = graphicalPath;
  m_textRepresentations[id] = textRepresentation;
}

std::filesystem::path Arcade::Shared::ResourceRegistry::getGraphicalPath(const ResourceIdentifier &id) const {
  auto it = m_graphicalPaths.find(id);
  if (it != m_graphicalPaths.end()) {
    return it->second;
  }
  return {};
}

std::string Arcade::Shared::ResourceRegistry::getTextRepresentation(const ResourceIdentifier &id) const {
  auto it = m_textRepresentations.find(id);
  if (it != m_textRepresentations.end()) {
    return it->second;
  }
  return nullptr;
}

void Arcade::Shared::ResourceRegistry::reset() {
  m_graphicalPaths.clear();
  m_textRepresentations.clear();
}




