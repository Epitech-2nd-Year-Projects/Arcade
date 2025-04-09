#pragma once

#include <SDL2/SDL.h>
#include <filesystem>
#include <map>
#include <string>

#include "../../Shared/Resource/ResourceIdentifier.hpp"

namespace Arcade::Graphics {
class ResourceManager {
public:
  ResourceManager(SDL_Renderer *renderer);
  ~ResourceManager();

  SDL_Texture *getTexture(const Shared::Resource::ResourceIdentifier &id);

private:
  SDL_Texture *loadTexture(const std::filesystem::path &path);

  SDL_Renderer *m_renderer;
  std::map<std::string, SDL_Texture *> m_textures;
};
} // namespace Arcade::Graphics
