#include "../inc/player.hpp"
#include "../inc/utils.hpp"

namespace tetris {

Player::Player() {
  Host_ = false;
  Client_ = false;
  score_ = 0;
  level_ = 1;
  pseudo_ = "player";
  numBlock = 0;
}

Player::Player(std::string pseudo) : pseudo_(pseudo) {
  Host_ = false;
  Client_ = false;
  score_ = 0;
}

std::string Player::get_pseudo() const { return pseudo_; };

void Player::set_pseudo(std::string newPseudo) { pseudo_ = newPseudo; }

int Player::get_score() const { return score_; }
void Player::add_score(int points) { score_ = score_ + points; }
void Player::set_score(int new_score) { score_ = new_score; };

void Player::reset_level() { level_ = 1; }
void Player::set_level(int new_level) { level_ = new_level; }
int Player::get_level() const { return level_; }

bool Player::isHost() const { return Host_; }
void Player::set_Host(bool host) { Host_ = host; }

bool Player::isClient() const { return Client_; }
void Player::set_Client(bool client) { Client_ = client; }

int Player::get_numBlock() const { return numBlock; }
void Player::add_numBlock() { numBlock += 1; }
void Player::reset_numBlock() { numBlock = 0; }

}; // namespace tetris