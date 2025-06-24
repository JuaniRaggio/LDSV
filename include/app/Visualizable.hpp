#pragma once

#include <cstdint>
#include <string>
#include <vector>

/**
 * @brief Base class for objects that can be visualized
 */
class Visualizable {
public:
    virtual ~Visualizable() = default;
    

    /**
     * @brief Get a string representation of the object for visualization
     * @return String representation
     */
    virtual std::string to_string() const = 0;
    

    /**
     * @brief Get the type name of the object
     * @return Type name as string
     */
    virtual std::string get_type_name() const = 0;

    
    /**
     * @brief Get visualization data as a vector of strings
     * @return Vector of strings representing the object's state
     */
    virtual std::vector<std::string> get_visualization_data() const = 0;

    
    /**
     * @brief Check if the object is in a valid state for visualization
     * @return true if valid, false otherwise
     */
    virtual bool is_valid() const = 0;
};


/**
 * @brief Base class for node-like objects that can be visualized
 */
class NodeVisualizable : public Visualizable {
public:
    virtual ~NodeVisualizable() = default;
    
    /**
     * @brief Get the node's identifier
     * @return Node identifier
     */
    virtual std::string get_node_id() const = 0;
    
    /**
     * @brief Get the node's label for display
     * @return Node label
     */
    virtual std::string get_label() const = 0;
    
    /**
     * @brief Get the node's position in the visualization
     * @return Pair of x, y coordinates
     */
    virtual std::pair<double, double> get_position() const = 0;
    
    /**
     * @brief Set the node's position in the visualization
     * @param x X coordinate
     * @param y Y coordinate
     */
    virtual void set_position(double x, double y) = 0;
};


/**
 * @brief Base class for objects that have a color property
 */
class Colorable {
public:
    virtual ~Colorable() = default;

    
    /**
     * @brief Get the color value
     * @return Color as 8-bit integer
     */
    virtual std::uint8_t get_color() const {
        return color;
    }

    
    /**
     * @brief Set the color value
     * @param color Color as 8-bit integer
     */
    virtual void set_color(std::uint8_t color) {
        this->color = color;
    }

    
    /**
     * @brief Get color name for display
     * @return Color name as string
     */
    virtual std::string get_color_name() const {
        // Default implementation - can be overridden
        return "Color_" + std::to_string(color);
    }

protected:
    std::uint8_t color = 0;
};

