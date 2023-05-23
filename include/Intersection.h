#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "constants.h"
#include <iostream>
#include <memory>
#include <vector>
/**
 * @brief Intersection class
 *
 * @details class represents an intersection in the maze. It contains the x and y
 * coordinates of the intersection, as well as pointers to the intersections
 * that are up, down, left, and right of it.
 *
 */
class Intersection {
  public:
    /**
     * @brief Construct a new Intersection object
     *
     * @param x
     * @param y
     */
    Intersection(int x, int y);
    ~Intersection();

    int getX() const;
    int getY() const;
    void setUp(std::shared_ptr<Intersection> up);
    std::shared_ptr<Intersection> getUp() const;
    void setDown(std::shared_ptr<Intersection> down);
    std::shared_ptr<Intersection> getDown() const;
    void setLeft(std::shared_ptr<Intersection> left);
    std::shared_ptr<Intersection> getLeft() const;
    void setRight(std::shared_ptr<Intersection> right);
    std::shared_ptr<Intersection> getRight() const;

    /**
     * @brief Get the Options object
     *
     * @return the non-null neighbors of the intersection
     */
    std::vector<std::shared_ptr<Intersection>> getOptions() const;
    /**
     * @brief Get the Direction object
     *
     * @param dest
     * @return the direction you need to go to get to the destination from this intersection
     */
    int getDirection(std::shared_ptr<Intersection> dest) const;

  private:
    int x_pixel;
    int y_pixel;
    std::shared_ptr<Intersection> up = nullptr;
    std::shared_ptr<Intersection> down = nullptr;
    std::shared_ptr<Intersection> left = nullptr;
    std::shared_ptr<Intersection> right = nullptr;
};

#endif /* INTERSECTION_H */
