#include "../../inc/types_block/block_O.hpp"

namespace tetris {

Block_O::Block_O(int i, int j) {
  value = 4;
  rotate_value = 0;

  list_squares.push_back({i, j});
  list_squares.push_back({i + 1, j});
  list_squares.push_back({i + 1, j + 1});
  list_squares.push_back({i, j + 1});
}

void Block_O::rotate(Grid &g) { return; };

} // namespace tetris