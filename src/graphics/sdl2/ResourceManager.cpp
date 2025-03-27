#include <SDL2/SDL_image.h>
#include "ResourceManager.hpp"
#include "../../Shared/ResourceRegistry.hpp"

Arcade::Graphics::ResourceManager::ResourceManager(SDL_Renderer* renderer)
  : m_renderer(renderer) {}

Arcade::Graphics::ResourceManager::~ResourceManager() {

}

SDL_Texture *Arcade::Graphics::ResourceManager::getTexture(const Shared::ResourceIdentifier& id) {
  std::filesystem::path path = Shared::ResourceRegistry::getInstance().getGraphicalPath(id);

  auto it = m_textures.find(path.string());
  if (it != m_textures.end()) {
    return it->second;
  }

  SDL_Texture *texture = loadTexture(path);
  if (texture != nullptr) {
    m_textures[path.string()] = texture;
  }
  return texture;
}

SDL_Texture* Arcade::Graphics::ResourceManager::loadTexture(const std::filesystem::path& path) {
  SDL_Surface *surface = IMG_Load(path.string().c_str());
  if (surface == nullptr) {
    return nullptr;
  }

  SDL_Texture *texture = SDL_CreateTextureFromSurface(m_renderer, surface);
  if (texture == nullptr) {
    return nullptr;
  }
  SDL_FreeSurface(surface);
  return texture;
}
