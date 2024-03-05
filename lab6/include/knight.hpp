#pragma once
#include "npc.hpp"

struct Knight : public NPC
{
    Knight(int x, int y);
    Knight(std::istream &is);
    void print(std::ostream& os) override;
    void save(std::ostream &os) override;
    bool is_knight() const override;

    bool visit(Druid& druid) override;
    bool visit(Elf& elf) override;
    bool visit(Knight& knight) override;

    bool accept(NPC& visitor) override;


    bool fight(std::shared_ptr<Druid> other) override;
    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<Elf> other) override;
    friend std::ostream &operator<<(std::ostream &os, Knight &knight);
};