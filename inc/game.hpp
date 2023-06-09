#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <chrono>
#include <string>
#include <thread>

#include "./types_block/block_I.hpp"
#include "./types_block/block_J.hpp"
#include "./types_block/block_L.hpp"
#include "./types_block/block_O.hpp"
#include "./types_block/block_S.hpp"
#include "./types_block/block_T.hpp"
#include "./types_block/block_Z.hpp"
#include "block.hpp"
#include "grid.hpp"
#include "network.hpp"
#include "utils.hpp"

namespace tetris {

class Game {
private:
  bool _running = true;
  int screen = 1;
  bool end_game = false;

  int score = 0;
  int points = 0;

  sf::RenderWindow window;
  sf::View WindowView;

  std::vector<sf::RectangleShape> list_lines_rect;
  std::vector<sf::ConvexShape> list_lines_conv;

  sf::Sprite bgSprite;
  sf::Texture bgTexture;
  sf::Color ColorBorder;

  sf::RectangleShape blurGrid_;

  sf::RectangleShape soloButton;
  sf::RectangleShape multiButton;
  sf::RectangleShape pseudoBox;
  sf::RectangleShape HostButton;
  sf::RectangleShape ClientButton;
  sf::RectangleShape BackButton;
  sf::RectangleShape CreateButton;
  sf::RectangleShape ipBox;
  sf::RectangleShape portBox;
  sf::RectangleShape PlayButton;
  bool HostButton_Selected = true;
  bool ipBox_focused = true;

  /*---- Texts ----*/

  sf::Font main_font_;
  sf::Text end_msg_;
  sf::Text try_again_;
  sf::Text Nexts_;
  sf::Text Multiplayers_;
  sf::Text Score_;
  sf::Text player_score;
  sf::Text Level_;
  sf::Text player_level;

  sf::Text Title_game;
  sf::Text pickYourName;
  std::string playerInput;
  sf::Text playerText;

  sf::Text Create_server;
  sf::Text Join_server;
  sf::Text GoBack_;
  sf::Text Create_;
  sf::Text ip_;
  sf::Text ipInput;
  std::string ipString;
  sf::Text portInput;
  sf::Text port_;
  std::string portString;
  sf::Text Quitting_;
  sf::Text Title_waiting;
  sf::Text Play_;

  sf::Text Solo_Button_;
  sf::Text Multi_Button_;

  sf::Text pseudo_this_player;
  std::vector<sf::Text *> pseudos_others_players;
  std::vector<sf::Text *> scores_others_players;

  /*---- Game grid and next block grid ----*/

  Grid grid;
  Grid little_grid;

  Block *current_block;
  Block *next_block;

  sf::Clock clock;
  float fps_grid;
  const float fps_grid_init;

  Player player;
  std::vector<Player *> other_players;

  Network network;
  std::string TypeDataFromHost;

  bool targetButton(double, double, int);

  void GameScreen();
  void HomeScreen();
  void MultiPlayerScreen();
  void WaitingScreen();
  void QuittingScreen();
  void InputHandler(sf::Event);
  void Initialize_game();
  void Initialize_graphics();

  void set_running(bool new_running);
  void set_fps_grid(float new_fps_grid);
  void set_game_break();

  void integrate_block_to_grid();
  void generate_new_next_block();
  bool is_end_game();

public:
  Game();
  ~Game();
  void Run();
};

void InputHandler(sf::Event, Game &, Block &, Grid &);

} // namespace tetris

#endif // !GAME_HPP
