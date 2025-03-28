#include "sdl2.hpp"
#include <iostream>
#include <SDL2/SDL_image.h>

extern "C" Arcade::Shared::IDisplay* createDisplay() {
  return new Arcade::Graphics::SDL2;
}

Arcade::Graphics::SDL2::SDL2()
  : m_window(nullptr), m_renderer(nullptr) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL_Init error: " << SDL_GetError() << std::endl;
    return;
  }
  if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
    std::cerr << "IMG_Init error: " << IMG_GetError() << std::endl;
    SDL_Quit();
    return;
  }

  m_window = SDL_CreateWindow(
    "Arcade",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    1920,
    1080,
    SDL_WINDOW_SHOWN
  );

  if (m_window == nullptr) {
    std::cerr << "SDL_CreateWindow error: " << SDL_GetError() << std::endl;
    IMG_Quit();
    SDL_Quit();
    return;
  }

  m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
  if (m_renderer == nullptr) {
    std::cerr << "SDL_CreateRenderer error: " << SDL_GetError() << std::endl;
    SDL_DestroyWindow(m_window);
    IMG_Quit();
    SDL_Quit();
    return;
  }

  m_resourceManager = std::make_unique<ResourceManager>(m_renderer);
}

Arcade::Graphics::SDL2::~SDL2() {
  if (m_renderer != nullptr) {
    SDL_DestroyRenderer(m_renderer);
    m_renderer = nullptr;
  }
  if (m_window != nullptr) {
    SDL_DestroyWindow(m_window);
    m_window = nullptr;
  }
  IMG_Quit();
  SDL_Quit();
}

void Arcade::Graphics::SDL2::display(Shared::GameView& gameView) {
  SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
  SDL_RenderClear(m_renderer);

  const auto &scene = gameView.getScene();
  for (const auto &drawable : scene.getDrawables()) {
    renderDrawable(*drawable);
  }
  SDL_RenderPresent(m_renderer);
}

void Arcade::Graphics::SDL2::renderDrawable(const Shared::Scene::IDrawable& drawable) {
  const Shared::Resource::ResourceIdentifier resourceId = drawable.getResourceId();

  auto [x, y] = drawable.getPosition();
  SDL_Rect rect = {
    static_cast<int>(x),
    static_cast<int>(y),
    64,
    64
  };

  const auto *textDrawable = dynamic_cast<const Shared::Scene::GameText *>(&drawable);
  if (textDrawable != nullptr) {
    return;
  }

  SDL_Texture *texture = m_resourceManager->getTexture(resourceId);
  if (texture == nullptr) {
    return;
  }
  SDL_RenderCopy(m_renderer, texture, nullptr, &rect);
}

Arcade::Shared::GameEvent Arcade::Graphics::SDL2::getGameEvent() {
  Arcade::Shared::GameEvent event;
  SDL_Event sdlEvent;


  return event;
}
