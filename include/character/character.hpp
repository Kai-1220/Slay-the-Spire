#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <iostream>
#include "Util/GameObject.hpp"

class Character : public Util::GameObject {
public:
    explicit Character(const std::string& ImagePath);

    Character(const Character&) = delete;

    Character(Character&&) = delete;

    Character& operator=(const Character&) = delete;

    Character& operator=(Character&&) = delete;

    const std::string& GetImagePath() const;

    const glm::vec2& GetPosition() const;

    bool GetVisibility() const;

    void SetImage(const std::string& ImagePath);

    void SetPosition(const glm::vec2& Position);

    void SetPosition(const glm::vec2& Position);

    void SetHP(unsigned int HP);

    void SetDefense(unsigned int Defense);

    void MotifyHP(int HP);

    void MotifyDefense(int Defense);

    void GetHP();

    void GetDefense();

    void TakeDamage(unsigned int Damage);
private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }
    std::string m_ImagePath;

protected:
    bool m_Visible = true;
    unsigned int HP,Defense;
    
};


#endif //CHARACTER_HPP
