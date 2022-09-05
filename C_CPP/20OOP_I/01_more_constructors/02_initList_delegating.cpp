#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define reset "\e[0m"

/**
 * ! 1. Constructor Initialization List:
 * ? previous ways:
 * Player()
 * Player::Player(){
 *      name="Bob" //assignment not initialization
 *      health=0
 *      xp=0
 * }
 * * Better ways:
 * Player::Player():name("Nope"),health{0},sp{0}
 * 
 * 
 * ? previous ways:
 * Player(string)
 * Player::Player(string name_val){
 *      name=name_val //assignment not initialization
 *      health=0
 *      xp=0
 * }
 * * Better ways:
 * Player::Player(string name_val):name(name_val),health{0},sp{0}
 * 
 * ? previous ways:
 * Player(string)
 * Player::Player(string name_val){
 *      name=name_val //assignment not initialization
 *      health=0
 *      xp=0
 * }
 * * Better ways:
 * Player::Player(string name_val):name(name_val),health{0},sp{0}
 * 
*/
class Player {
private:
    string name;
    int health;
    int xp;

public:
    //overloadded constructor
    Player();
    Player(string name_val);
    Player(string name_val, int health, int xp_val);
};

Player::Player() : name{"Bob"}, health{0}, xp{0} {
    cout << "Palyer(): Default constructor" << endl;
}
Player::Player(string name_val) : name{name_val}, health{0}, xp{0} {}
Player::Player(string name_val, int health, int xp_val) : name{name_val}, health{health}, xp{xp} {}

/**
 * ! 2. Delegating Constructor::calling one constructor with init
 * !  list from another
 * 
 * if theres a 3-args constructor like:
 * Player::Player(string name_val, int health, int xp_val) :
 * name{name_val}, health{health}, xp{xp} {}
 * 
 * now we can call this inside other constructor
 * 
 * Player::Player():Player{"Bob",0,0}{}
 * Player::Player(string name_val):Player{name_val,0,0}{}
*/

class Delegating {
private:
    string name;
    int health;
    int xp;

public:
    //overloadded constructor
    Delegating();
    Delegating(string name_val);
    Delegating(string name_val, int health, int xp_val);
};

Delegating::Delegating() : Delegating{"Bob", 0, 0} {
    cout << "Delegating(): No-args constructor" << endl;
}
Delegating::Delegating(string name_val) : Delegating{name_val, 0, 0} {
    cout << "Delegating(): One-arg constructor";
}
Delegating::Delegating(string name_val, int health, int xp_val) : name{name_val}, health{health}, xp{xp} {}

int main() {
    Player empty;
    Player p{"Frank"};
    Player villain{"Bob", 100, 55};

    Delegating d;
    Delegating d1{"Frank"};
    Delegating d2{"Bob", 100, 55};
    return 0;
}