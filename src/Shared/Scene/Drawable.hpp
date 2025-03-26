#pragma once

#include <cstddef>
#include <filesystem>
#include <string>

namespace Arcade::Shared::Scene {
class IDrawable {
public:
  virtual ~IDrawable() = default;

  virtual void setPosition(float x, float y) = 0;
  virtual std::pair<float, float> getPosition() const = 0;
};

class Drawable : public IDrawable {
public:
  Drawable() = default;
  ~Drawable();

  Drawable(const Drawable &) = delete;
  Drawable &operator=(const Drawable &) = delete;

  Drawable(Drawable &&other) noexcept;
  Drawable &operator=(Drawable &&other) noexcept;

  void setPosition(float x, float y) override;
  std::pair<float, float> getPosition() const override;

protected:
  std::pair<float, float> m_position;
};

class GameText final : public Drawable {
public:
  void setText(const std::string &text);
  const std::string &getText() const;

  void setFontSize(std::size_t fontSize);
  std::size_t getFontSize() const;

private:
  std::string m_text;
  std::size_t m_fontSize = 12;
};

class GameSprite final : public Drawable {
  enum class Type { Player, Enemy, Wall, Floor };

public:
  void setType(Type type);
  Type getType() const;

  void setTexturePath(const std::filesystem::path &path);
  const std::filesystem::path &getTexturePath() const;

private:
  std::filesystem::path m_texturePath;
  Type m_type;
};

} // namespace Arcade::Shared::Scene
