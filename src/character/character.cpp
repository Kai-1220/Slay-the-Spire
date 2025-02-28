
#include "character.hpp"
Character::GetImagePath() const { return m_ImagePath; }

Character::GetPosition() const { return m_Transform.translation; }

Character::GetVisibility() const { return m_Visible; }

Character::SetImage(const std::string& ImagePath);

Character::SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }

Character::SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }

Character::SetHP(unsigned int HP) { this->HP = HP; }

Character::SetDefense(unsigned int Defense) { this->Defense = Defense; }

Character::MotifyHP(int HP){ this->HP += HP; }

Character::MotifyDefense(int Defense){ this->Defense += Defense; }

Character::GetHP(){ return HP; }

Character::GetDefense(){ return Defense; }

Character::TakeDamage(unsigned int Damage){ HP -= Damage; }
