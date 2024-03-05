#include "../include/knight.hpp"
#include "../include/elf.hpp"
#include "../include/druid.hpp"

Knight::Knight(int x, int y) : NPC(KnightType, x, y) {}
Knight::Knight(std::istream &is) : NPC(KnightType, is) {}

void Knight::print(std::ostream& os)
{
    os << *this;
}

void Knight::save(std::ostream &os)
{
    os << KnightType << std::endl;
    NPC::save(os);
}
bool Knight::is_knight() const
{
    return true;
}

bool Knight::fight(std::shared_ptr<Druid> other)
{
    fight_notify(other, false);
    return false;
}

bool Knight::fight(std::shared_ptr<Knight> other)
{
    fight_notify(other, false);
    return false;
}

bool Knight::fight(std::shared_ptr<Elf> other)
{
    fight_notify(other, true);
    return true;
}

std::ostream &operator<<(std::ostream &os, Knight &knight)
{
    os << "knight: " << *static_cast<NPC *>(&knight) << std::endl;
    return os;
}

bool Knight::visit(Druid& druid) {
    return druid.fight(std::make_shared<Knight>(*this));
}
bool Knight::visit(Elf& elf) {
    return elf.fight(std::make_shared<Knight>(*this));
}
bool Knight::visit(Knight& knight) {
    return knight.fight(std::make_shared<Knight>(*this));
}

bool Knight::accept(NPC& visitor) {
    return visitor.visit(*this);
}
