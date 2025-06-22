#include <cstdint>

class Visualizable;
class NodeVisualizable;
class Colorable;

class Visualizable {

  public:

  private:

};

class NodeVisualizable : public Visualizable {

};

class Colorable {
  public:

    inline std::uint8_t getColor() {
      return this->color;
    }

    inline void setColor(std::uint8_t color) {
      this->color = color;
    };

  private:
    std::uint8_t color;

};

