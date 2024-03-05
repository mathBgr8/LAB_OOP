#include "../include/druid.hpp"
#include "../include/knight.hpp"
#include "../include/elf.hpp"

Druid::Druid(int x, int y) : NPC(DruidType, x, y) {}
Druid::Druid(std::istream &is) : NPC(DruidType, is) {}

void Druid::print(std::ostream& os)
{
    os << *this;
}

bool Druid::is_Druid() const 
{
    return true;
}

bool Druid::fight(std::shared_ptr<Druid> other) 
{
    fight_notify(other, true);
    return true;
}

bool Druid::fight(std::shared_ptr<Knight> other) 
{
    fight_notify(other, false);
    return false;
}

bool Druid::fight(std::shared_ptr<Elf> other) 
{
    fight_notify(other, false);
    return true;
}

void Druid::save(std::ostream &os) 
{
    os << DruidType << std::endl;
    NPC::save(os);
}

std::ostream &operator<<(std::ostream &os, Druid &Druid)
{
    os << "Druid: " << *static_cast<NPC *>(&Druid) << std::endl;
    return os;
}

int Druid::get_attack_range() {
    return attack_range;
}

std::pair<int, int> Druid::get_shift() {
    return {shift.first * sh[std::rand() % 2], shift.second * sh[std::rand() % 2]};
}


bool Druid::accept(std::shared_ptr<NPC> visitor) {
    return visitor->fight(std::shared_ptr<Druid>(this,[](Druid*){}));
}