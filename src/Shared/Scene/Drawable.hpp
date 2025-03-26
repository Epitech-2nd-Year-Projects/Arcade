#pragma once

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

private:
  std::string m_text;
};

class GameSprite final : public Drawable {
  enum class Type { Player, Wall };

public:
  void setType(Type type);
  Type getType() const;

private:
  Type m_type;
};

} // namespace Arcade::Shared::Scene
