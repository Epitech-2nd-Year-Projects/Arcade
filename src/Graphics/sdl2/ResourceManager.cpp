#include "ResourceManager.hpp"
#include "../../Shared/Resource/ResourceRegistry.hpp"
#include <SDL2/SDL_image.h>

Arcade::Graphics::ResourceManager::ResourceManager(SDL_Renderer *renderer)
    : m_renderer(renderer) {}

Arcade::Graphics::ResourceManager::~ResourceManager() {
  for (auto &[path, texture] : m_textures) {
    if (texture != nullptr) {
      SDL_DestroyTexture(texture);
    }
  }
  m_textures.clear();
}

SDL_Texture *Arcade::Graphics::ResourceManager::getTexture(
    const Shared::Resource::ResourceIdentifier &id) {
  std::filesystem::path path =
      Shared::Resource::ResourceRegistry::getInstance().getGraphicalPath(id);

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

SDL_Texture *Arcade::Graphics::ResourceManager::loadTexture(
    const std::filesystem::path &path) {
  if (!std::filesystem::exists(path)) {
    std::cerr << "Texture file not found: " << path.string() << std::endl;
    return nullptr;
  }

  SDL_Surface *surface = IMG_Load(path.string().c_str());
  if (surface == nullptr) {
    std::cerr << "Failed to load texture: " << path.string()
              << " - " << IMG_GetError() << std::endl;
    return nullptr;
  }

  SDL_Texture *texture = SDL_CreateTextureFromSurface(m_renderer, surface);
  SDL_FreeSurface(surface);

  if (texture == nullptr) {
    std::cerr << "Failed to create texture from surface: "
              << SDL_GetError() << std::endl;
    return nullptr;
  }

  return texture;
}