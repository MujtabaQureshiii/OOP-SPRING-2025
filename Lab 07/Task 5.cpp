#include <iostream>
#include <string>

using namespace std;

class Character {
protected:
    int characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;

public:
    Character(int id, string name, int level, int hp, string weapon = "")
        : characterID(id), name(name), level(level), healthPoints(hp), weaponType(weapon) {}

    virtual void attack() {
        cout << name << " performs a basic attack!" << endl;
    }

    virtual void defend() {
        cout << name << " defends against an attack!" << endl;
    }

    virtual void displayStats() {
        cout << "\n--- Character Stats ---\n"
             << "ID: " << characterID
             << "\nName: " << name
             << "\nLevel: " << level
             << "\nHealth Points: " << healthPoints
             << "\nWeapon: " << (weaponType.empty() ? "None" : weaponType) << endl;
    }

    virtual ~Character() {}
};

class Warrior : public Character {
private:
    int armorStrength;
    int meleeDamage;

public:
    Warrior(int id, string name, int level, int hp, int armor, int damage, string weapon = "Sword")
        : Character(id, name, level, hp, weapon), armorStrength(armor), meleeDamage(damage) {}

    void attack() override {
        cout << name << " swings their weapon, dealing " << meleeDamage << " melee damage!" << endl;
    }

    void displayStats() override {
        Character::displayStats();
        cout << "Armor Strength: " << armorStrength
             << "\nMelee Damage: " << meleeDamage << endl;
    }
};

class Mage : public Character {
private:
    int manaPoints;
    int spellPower;

public:
    Mage(int id, string name, int level, int hp, int mana, int power, string weapon = "Staff")
        : Character(id, name, level, hp, weapon), manaPoints(mana), spellPower(power) {}

    void defend() override {
        cout << name << " casts a magical barrier, reducing damage!" << endl;
    }

    void displayStats() override {
        Character::displayStats();
        cout << "Mana Points: " << manaPoints
             << "\nSpell Power: " << spellPower << endl;
    }
};

class Archer : public Character {
private:
    int arrowCount;
    int rangedAccuracy;

public:
    Archer(int id, string name, int level, int hp, int arrows, int accuracy, string weapon = "Bow")
        : Character(id, name, level, hp, weapon), arrowCount(arrows), rangedAccuracy(accuracy) {}

    void attack() override {
        if (arrowCount > 0) {
            arrowCount--;
            cout << name << " fires an arrow with " << rangedAccuracy << "% accuracy!" << endl;
        } else {
            cout << name << " has no arrows left!" << endl;
        }
    }

    void displayStats() override {
        Character::displayStats();
        cout << "Arrows Left: " << arrowCount
             << "\nRanged Accuracy: " << rangedAccuracy << "%" << endl;
    }
};

class Rogue : public Character {
private:
    int stealthLevel;
    int agility;

public:
    Rogue(int id, string name, int level, int hp, int stealth, int agility, string weapon = "Dagger")
        : Character(id, name, level, hp, weapon), stealthLevel(stealth), agility(agility) {}

    void displayStats() override {
        Character::displayStats();
        cout << "Stealth Level: " << stealthLevel
             << "\nAgility: " << agility << endl;
    }
};

int main() {
    Warrior w1(101, "Thorn", 10, 150, 50, 30);
    Mage m1(102, "Zyra", 12, 100, 80, 40);
    Archer a1(103, "Legolas", 15, 120, 20, 85);
    Rogue r1(104, "Shadow", 14, 110, 90, 70);

    w1.displayStats();
    w1.attack();
    
    m1.displayStats();
    m1.defend();
    
    a1.displayStats();
    a1.attack();
    
    r1.displayStats();

    return 0;
}
