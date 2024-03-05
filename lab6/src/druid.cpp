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
    return false;
}

void Druid::save(std::ostream &os) 
{
    os << DruidType << std::endl;
    NPC::save(os);
}

std::ostream &operator<<(std::ostream &os, Druid &Druid)
{
    os << "druid: " << *static_cast<NPC *>(&Druid) << std::endl;
    return os;
}

bool Druid::visit(Druid& druid) {
    return druid.fight(std::make_shared<Druid>(*this));
}
bool Druid::visit(Elf& elf) {
    return elf.fight(std::make_shared<Druid>(*this));
}
bool Druid::visit(Knight& knight) {
    return knight.fight(std::make_shared<Druid>(*this));
}

bool Druid::accept(NPC& visitor) {
    return visitor.visit(*this);
}
