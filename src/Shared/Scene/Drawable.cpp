#include "Drawable.hpp"

Arcade::Shared::Scene::Drawable::Drawable() : m_position(0.0f, 0.0f) {}

Arcade::Shared::Scene::Drawable::Drawable(Drawable &&other) noexcept
    : m_position(std::move(other.m_position)) {}

Arcade::Shared::Scene::Drawable &
Arcade::Shared::Scene::Drawable::operator=(Drawable &&other) noexcept {
  if (this != &other) {
    m_position = std::move(other.m_position);
  }
  return *this;
}

void Arcade::Shared::Scene::Drawable::setPosition(float x, float y) noexcept {
  m_position = std::make_pair(x, y);
}

std::pair<float, float>
Arcade::Shared::Scene::Drawable::getPosition() const noexcept {
  return m_position;
}

const Arcade::Shared::Resource::ResourceIdentifier
    Arcade::Shared::Scene::GameText::TEXT_RESOURCE =
        Resource::ResourceIdentifier(Resource::ResourceType::Player, "text");

Arcade::Shared::Scene::GameText::GameText()
    : Drawable(), m_text(""), m_fontSize(12) {}

Arcade::Shared::Scene::GameText::~GameText() {}

void Arcade::Shared::Scene::GameText::setText(const std::string_view text) {
  m_text = text;
}

std::string_view Arcade::Shared::Scene::GameText::getText() const noexcept {
  return m_text;
}

void Arcade::Shared::Scene::GameText::setFontSize(
    std::size_t fontSize) noexcept {
  m_fontSize = fontSize;
}

std::size_t Arcade::Shared::Scene::GameText::getFontSize() const noexcept {
  return m_fontSize;
}

Arcade::Shared::Resource::ResourceIdentifier
Arcade::Shared::Scene::GameText::getResourceId() const {
  return TEXT_RESOURCE;
}

Arcade::Shared::Scene::GameSprite::GameSprite()
    : Drawable(), m_resourceType(Resource::ResourceType::Floor),
      m_state("default") {}

Arcade::Shared::Scene::GameSprite::GameSprite(Resource::ResourceType type,
                                              const std::string &state)
    : Drawable(), m_resourceType(type), m_state(state) {}

void Arcade::Shared::Scene::GameSprite::setResourceType(
    Resource::ResourceType type) {
  m_resourceType = type;
}

Arcade::Shared::Resource::ResourceType
Arcade::Shared::Scene::GameSprite::getResourceType() const {
  return m_resourceType;
}

void Arcade::Shared::Scene::GameSprite::setState(const std::string &state) {
  m_state = state;
}

const std::string &Arcade::Shared::Scene::GameSprite::getState() const {
  return m_state;
}

Arcade::Shared::Resource::ResourceIdentifier
Arcade::Shared::Scene::GameSprite::getResourceId() const {
  return Resource::ResourceIdentifier(m_resourceType, m_state);
}
