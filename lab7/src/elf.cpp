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

int Elf::get_attack_range() {
    return attack_range;
}

std::pair<int, int> Elf::get_shift() {
    return {shift.first * sh[std::rand() % 2], shift.second * sh[std::rand() % 2]};
}

bool Elf::accept(std::shared_ptr<NPC> visitor) {
    return visitor->fight(std::shared_ptr<Elf>(this,[](Elf*){}));
}
