#ifndef MAZE_H
#define MAZE_H

#include "Gomme.h"
#include "Intersection.h"
#include "constants.h"
#include <memory>
#include <string>
#include <vector>

/**
 * @brief Tile struct
 *
 * @details struct is used to store the coordinates of a tile.
 *
 */
struct Tile {
    int x;
    int y;
};

/**
 * @brief Maze class
 *
 * @details this class stores the maze, the intersections and the gommes (pac-dots and power
 * pellets).
 *
 */
class Maze {
  public:
    /**
     * @brief Construct a new Maze object
     *
     */
    Maze();
    ~Maze();
    char getCell(int row, int col) const;
    int getWidth() const;
    int getHeight() const;
    std::vector<std::shared_ptr<Intersection>> getIntersections() const;
    std::shared_ptr<Intersection> getIntersection(int index) const;
    std::vector<std::shared_ptr<Gomme>> getGommes() const;
    void clearGomme(std::shared_ptr<Gomme> gomme);

  private:
    std::vector<std::vector<int>> cells;
    std::vector<std::shared_ptr<Intersection>> intersections;
    std::vector<std::shared_ptr<Gomme>> gommes;
    int width;
    int height;
};

#endif /* MAZE_H */
