#include "../include/elf.hpp"
#include "../include/druid.hpp"
#include "../include/knight.hpp"

Elf::Elf(int x, int y) : NPC(ElfType, x, y) {}
Elf::Elf(std::istream &is) : NPC(ElfType, is) {}

void Elf::print(std::ostream& os)
{
    os << *this;
}

void Elf::save(std::ostream &os)
{
    os << ElfType << std::endl;
    NPC::save(os);
}

bool Elf::is_Elf() const
{
    return true;
}

bool Elf::fight(std::shared_ptr<Druid> other)
{
    fight_notify(other, true);
    return true;
}

bool Elf::fight(std::shared_ptr<Elf> other)
{
    fight_notify(other, false);
    return false;
}

bool Elf::fight(std::shared_ptr<Knight> other)
{
    fight_notify(other, true);
    return true;
}

std::ostream &operator<<(std::ostream &os, Elf &Elf)
{
    os << "Elf: " << *static_cast<NPC *>(&Elf) << std::endl;
    return os;
}


bool Elf::visit(Druid& druid) {
    return druid.fight(std::make_shared<Elf>(*this));
}
bool Elf::visit(Elf& elf) {
    return elf.fight(std::make_shared<Elf>(*this));
}
bool Elf::visit(Knight& knight) {
    return knight.fight(std::make_shared<Elf>(*this));
}

bool Elf::accept(NPC& visitor) {
    return visitor.visit(*this);
}