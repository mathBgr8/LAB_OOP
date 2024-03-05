#pragma once
#include "npc.hpp"

struct Elf : public NPC
{
    Elf(int x, int y);
    Elf(std::istream &is);

    void print(std::ostream& os) override;

    void save(std::ostream &os) override;
    bool is_Elf() const override;

    bool visit(Druid& druid) override;
    bool visit(Elf& elf) override;
    bool visit(Knight& knight) override;

    bool accept(NPC& visitor) override;

    bool fight(std::shared_ptr<Druid> other) override;
    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<Elf> other) override;
    friend std::ostream &operator<<(std::ostream &os, Elf &knight);
};