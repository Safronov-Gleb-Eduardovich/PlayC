#include "Player.h"
#include <iostream>

Player::Player(Room startRoom) : currentRoom(startRoom), health(100) {}

void Player::addItem(const Item& item) {
    inventory.push_back(item);
}

void Player::showInventory() const {
    for (const auto& item : inventory) {
        std::cout << "- " << item.getName()
            << " (" << item.getCharges() << "/"
            << item.getMaxCharges() << ")\n";
    }
}

bool Player::useItem(const std::string& itemName) {
    for (auto& item : inventory) {
        if (item.getName() == itemName) {
            return item.use();
        }
    }
    return false;
}

void Player::rechargeItem(const std::string& itemName, int amount) {
    for (auto& item : inventory) {
        if (item.getName() == itemName) {
            item.recharge(amount);
            std::cout << itemName << "\n";
            return;
        }
    }
}

int Player::getHealth() const {
    return health;
}

void Player::takeDamage(int damage) {
    health -= damage;
}

Room Player::getCurrentRoom() const {
    return currentRoom;
}

void Player::changingCurrentRoom(Room Room) {
    currentRoom = Room;
}

